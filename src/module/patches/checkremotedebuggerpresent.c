#include "inc/module/common.h"
#include "inc/module/patches.h"
#include "inc/module/minhook/minhook.h"
#include "inc/module/utils/log.h"

void HookCheckRemoteDebuggerPresent(
	)
{
	LPVOID tmp = NULL;
	LPVOID address = NULL;
	HANDLE module = NULL;

	module = GetModuleHandleA("kernel32.dll");
	if (module == NULL)
	{
		LogWithPrefix("CheckRemoteDebuggerPresent", "Failed to get a handle to 'kernel32.dll'");
		return;
	}

	address = GetProcAddress(module, "CheckRemoteDebuggerPresent");
	if (address == NULL)
	{
		LogWithPrefix("CheckRemoteDebuggerPresent", "Failed to get the address of 'CheckRemoteDebuggerPresent'");
		return;
	}

	if (MH_CreateHook(address, fCheckRemoteDebuggerPresent, tmp) != MH_OK)
	{
		LogWithPrefix("CheckRemoteDebuggerPresent", "Failed to hook 'CheckRemoteDebuggerPresent'");
		return;
	}

	LogWithPrefix("CheckRemoteDebuggerPresent", "Successfully hooked 'CheckRemoteDebuggerPresent'\n");
}

BOOL fCheckRemoteDebuggerPresent(
	HANDLE hProcess,
	PBOOL pbDebuggerPresent
	)
{
	*pbDebuggerPresent = FALSE;
	return TRUE;
}