#include "inc/module/common.h"
#include "inc/module/threads.h"
#include "inc/module/patches.h"
#include "inc/module/minhook/minhook.h"
#include "inc/module/utils/log.h"

#include <stdio.h>
#include <winuser.h>

void HookCheckWindowClassName(
	)
{
	LogWithPrefix("CheckWindowClassName", "Successfully hooked ''\n");
}

void HookNtSetInformationThread(
	)
{
	LogWithPrefix("NtSetInformationThread", "Successfully hooked ''\n");
}

void HookQueryPerformanceCounter(
	)
{
	LogWithPrefix("QueryPerformanceCounter", "Successfully hooked ''\n");
}

void HookGetTickCount(
	)
{
	LogWithPrefix("GetTickCount", "Successfully hooked ''\n");
}

void HookHardwareDebugRegisters(
	)
{
	LogWithPrefix("HardwareDebugRegisters", "Successfully hooked ''\n");
}

void HookMovSS(
	)
{
	LogWithPrefix("MovSS", "Successfully hooked ''\n");
}

void HookCloseHandleException(
	)
{
	LogWithPrefix("CloseHandleException", "Successfully hooked ''\n");
}

void HookSingleStepException(
	)
{
	LogWithPrefix("SingleStepException", "Successfully hooked ''\n");
}

void HookInt3(
	)
{
	LogWithPrefix("Int3", "Successfully hooked ''\n");
}

void HookPrefixHop(
	)
{
	LogWithPrefix("PrefixHop", "Successfully hooked ''\n");
}

void HookInt2D(
	)
{
	LogWithPrefix("Int2D", "Successfully hooked ''\n");
}

MODULE_EXPORT DWORD Startup(
	LPVOID reserved )
{
	if (MH_Initialize() != MH_OK)
	{
		return FALSE;
	}

	ClearScreen();
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

	if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK)
	{
		LogWithPrefix("ERROR", "Failed to enable all MinHook Hooks\n");
	}

	SetConsoleTextColor(CONSOLE_TEXT_COLOR_WHITE);
	Log("Welcome to Ludus - Gladiator School of Debugger Evasion\n");
	Log("Choose a function to call:\n");
	Log("01. IsDebuggerPresent\n");
	Log("02. CheckRemoteDebuggerPresent\n");
	Log("03. ProcessFileName\n");
	Log("04. CheckWindowClassName\n");
	Log("05. NtSetInformationThread\n");
	Log("06. QueryPerformanceCounter\n");
	Log("07. GetTickCount\n");
	Log("08. HardwareDebugRegisters\n");
	Log("09. MovSS\n");
	Log("10. CloseHandleException\n");
	Log("11. SingleStepException\n");
	Log("12. Int3\n");
	Log("13. PrefixHop\n");
	Log("14. Int2D\n");
	Log("> ");

	return FALSE;
}