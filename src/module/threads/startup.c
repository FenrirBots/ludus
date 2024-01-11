#include "inc/module/common.h"
#include "inc/module/threads.h"
#include "inc/module/patches.h"
#include "inc/module/minhook/minhook.h"

#include <winuser.h>

void HookIsDebuggerPresent(
	)
{
	LPVOID tmp = NULL;
	LPVOID address = NULL;
	
	address = GetProcAddress(GetModuleHandleA("kernel32.dll"), "IsDebuggerPresent");
	if (address == NULL)
	{
		MessageBox(NULL, "GetProcAddress returned NULL", "ERROR", MB_OK);
	}

	if (MH_OK == MH_CreateHook(address, fIsDebuggerPresent, tmp))
	{
		return;
	}

	MessageBox(NULL, "Failed to hook IsDebuggerPresent", "ERROR", MB_OK);
}

void HookCheckRemoteDebuggerPresent(
	)
{
	LPVOID tmp = NULL;
	LPVOID address = NULL;
	
	address = GetProcAddress(GetModuleHandleA("kernel32.dll"), "CheckRemoteDebuggerPresent");
	if (address == NULL)
	{
		MessageBox(NULL, "GetProcAddress returned NULL", "ERROR", MB_OK);
	}

	if (MH_OK == MH_CreateHook(address, fCheckRemoteDebuggerPresent, tmp))
	{
		return;
	}

	MessageBox(NULL, "Failed to hook CheckRemoteDebuggerPresent", "ERROR", MB_OK);
}

void HookProcessFileName(
	)
{
}

void HookCheckWindowClassName(
	)
{
}

void HookNtSetInformationThread(
	)
{
}

void HookQueryPerformanceCounter(
	)
{
}

void HookGetTickCount(
	)
{
}

void HookHardwareDebugRegisters(
	)
{
}

void HookMovSS(
	)
{
}

void HookCloseHandleException(
	)
{
}

void HookSingleStepException(
	)
{
}

void HookInt3(
	)
{
}

void HookPrefixHop(
	)
{
}

void HookInt2D(
	)
{
}

MODULE_EXPORT DWORD Startup(
	LPVOID reserved )
{
	if (MH_OK == MH_Initialize())
	{
		HookIsDebuggerPresent();
		HookCheckRemoteDebuggerPresent();
		HookProcessFileName();
		HookCheckWindowClassName();
		HookNtSetInformationThread();
		HookQueryPerformanceCounter();
		HookGetTickCount();
		HookHardwareDebugRegisters();
		HookMovSS();
		HookCloseHandleException();
		HookSingleStepException();
		HookInt3();
		HookPrefixHop();
		HookInt2D();

		if (MH_OK == MH_EnableHook(MH_ALL_HOOKS))
		{
			MessageBox(NULL, "Hooked", "SUCCESS", MB_OK);
			return TRUE;
		}

		MessageBox(NULL, "Failed to enable the hooks", "ERROR", MB_OK);
		return FALSE;
	}

	MessageBox(NULL, "Failed to initialize MinHook", "ERROR", MB_OK);
	return FALSE;
}