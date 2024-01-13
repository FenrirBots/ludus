#include "inc/module/common.h"
#include "inc/module/patches.h"
#include "inc/module/minhook/minhook.h"
#include "inc/module/utils/log.h"

void HookIsDebuggerPresent(
	)
{
	LPVOID tmp = NULL;
	LPVOID address = NULL;
	HANDLE module = NULL;

	module = GetModuleHandleA("kernel32.dll");
	if (module == NULL)
	{
		LogWithPrefix("IsDebuggerPresent", "Failed to get a handle to 'kernel32.dll'");
		return;
	}

	address = GetProcAddress(module, "IsDebuggerPresent");
	if (address == NULL)
	{
		LogWithPrefix("IsDebuggerPresent", "Failed to get the address of 'IsDebuggerPresent'");
		return;
	}

	if (MH_CreateHook(address, fIsDebuggerPresent, tmp) != MH_OK)
	{
		LogWithPrefix("IsDebuggerPresent", "Failed to hook 'IsDebuggerPresent'");
		return;
	}

	LogWithPrefix("IsDebuggerPresent", "Successfully hooked 'IsDebuggerPresent'\n");
}

BOOL fIsDebuggerPresent(
	)
{
	return FALSE;
}