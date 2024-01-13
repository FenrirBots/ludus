#include "inc/module/common.h"
#include "inc/module/patches.h"
#include "inc/module/minhook/minhook.h"
#include "inc/module/utils/log.h"
#include <tlhelp32.h>

void HookProcessFileName(
	)
{
	LPVOID tmp = NULL;
	LPVOID address = NULL;
	HANDLE module = NULL;
	module = GetModuleHandleA("kernel32.dll");

	if (module == NULL)
	{
		LogWithPrefix("ProcessFileName", "Failed to get a handle to 'kernel32.dll'");
		return;
	}
	
	address = GetProcAddress(module, "Process32FirstW");
	if (address == NULL)
	{
		LogWithPrefix("ProcessFileName", "Failed to get the address of 'Process32FirstW'");
		return;
	}

	if (MH_CreateHook(address, fProcess32FirstW, tmp) != MH_OK)
	{
		LogWithPrefix("ProcessFileName", "Failed to hook 'Process32FirstW'");
		return;
	}

	LogWithPrefix("ProcessFileName", "Successfully hooked 'Process32FirstW'\n");
	
	address = GetProcAddress(module, "Process32NextW");
	if (address == NULL)
	{
		LogWithPrefix("ProcessFileName", "Failed to get the address of 'Process32NexttW'");
		return;
	}

	if (MH_CreateHook(address, fProcess32NextW, tmp) != MH_OK)
	{
		LogWithPrefix("ProcessFileName", "Failed to hook 'Process32NextW'");
		return;
	}
	
	LogWithPrefix("ProcessFileName", "Successfully hooked 'Process32NextW'\n");
}

// If this doesnt work then replace the entry in lppe with something simple like explorer.exe
BOOL fProcess32FirstW(
	HANDLE hSnapshot,
	LPPROCESSENTRY32 lppe )
{
	return FALSE;
}

BOOL fProcess32NextW(
	HANDLE hSnapshot,
	LPPROCESSENTRY32 lppe )
{
	return FALSE;
}