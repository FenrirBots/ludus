#include "inc/module/common.h"
#include "inc/module/threads.h"
#include "inc/module/patches.h"
#include "inc/module/minhook/minhook.h"

#include <winuser.h>

void HookIsDebuggerPresent(
	)
{
	LPVOID tmp;
	LPVOID pIsDebuggerPresent;
	// Check the value of this before calling MH_CreateHook
	pIsDebuggerPresent = GetProcAddress(GetModuleHandleA("kernel32.dll"), "IsDebuggerPresent");

	if (MH_OK == MH_CreateHook(pIsDebuggerPresent, fIsDebuggerPresent, tmp))
	{
		return;
	}

	MessageBox(NULL, "Failed to hook IsDebuggerPresent", "ERROR", MB_OK);
}

void HookCheckRemoteDebuggerPresent(
	)
{
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