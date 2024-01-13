#ifndef __MODULE_UTILS_LOG_H_
#define __MODULE_UTILS_LOG_H_
#include "inc/module/common.h"

#define CONSOLE_TEXT_COLOR_BLACK 0
#define CONSOLE_TEXT_COLOR_BLUE 1
#define CONSOLE_TEXT_COLOR_GREEN 2
#define CONSOLE_TEXT_COLOR_CYAN 3
#define CONSOLE_TEXT_COLOR_RED 4
#define CONSOLE_TEXT_COLOR_MAGENTA 5
#define CONSOLE_TEXT_COLOR_BROWN 6
#define CONSOLE_TEXT_COLOR_LIGHTGRAY 7
#define CONSOLE_TEXT_COLOR_DARKGRAY 8
#define CONSOLE_TEXT_COLOR_LIGHTBLUE 9
#define CONSOLE_TEXT_COLOR_LIGHTGREEN 10
#define CONSOLE_TEXT_COLOR_LIGHTCYAN 11
#define CONSOLE_TEXT_COLOR_LIGHTRED 12
#define CONSOLE_TEXT_COLOR_LIGHTMAGENTA 13
#define CONSOLE_TEXT_COLOR_YELLOW 14
#define CONSOLE_TEXT_COLOR_WHITE 15

BOOL SetConsoleVTPEnabled(
	);

void SetConsoleTextColor(
	unsigned int color );

void Log(
	const char* text );

void LogWithColor(
	const char* text,
	unsigned int color );

void LogWithPrefix(
	const char* prefix,
	const char* text );

void ClearScreen(
	);
	
#endif