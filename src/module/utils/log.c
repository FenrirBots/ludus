#include "inc/module/common.h"
#include "inc/module/utils/log.h"
#include <conio.h>
#include <stdio.h>

BOOL SetConsoleVTPEnabled(
	)
{
	DWORD flags  = 0;
	HANDLE handle = NULL;
	BOOL result = 0;

	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	if (handle == NULL)
	{
		return FALSE;
	}

	result = GetConsoleMode(handle, &flags);
	if (result == 0)
	{
		return FALSE;
	}

	result = SetConsoleMode(handle, flags | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
	if (result == 0)
	{
		return FALSE;
	}

	return TRUE;
}

void SetConsoleTextColor(
	unsigned int color )
{
	HANDLE handle = NULL;
	
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	if (handle == NULL)
	{
		return;
	}

	SetConsoleTextAttribute(handle, color);
}

void Log(
	const char*	 text )
{
	printf("%s", text);
}

void LogWithColor(
	const char* text,
	unsigned int color )
{
	SetConsoleTextColor(color);
	Log(text);
}

void LogWithPrefix(
	const char* prefix,
	const char* text )
{
	LogWithColor("[", CONSOLE_TEXT_COLOR_WHITE);
	LogWithColor(prefix, CONSOLE_TEXT_COLOR_YELLOW);
	LogWithColor("]:", CONSOLE_TEXT_COLOR_WHITE);
	Log(text);
}

void ClearScreen(
	)
{
	for(int idx = 0; idx < 50; idx++)
	{
		Log("\n");
	}
}