#ifndef __MODULE_PATCHES_H_
#define __MODULE_PATCHES_H_
#include "inc/module/common.h"

void HookIsDebuggerPresent(
	);
BOOL fIsDebuggerPresent(
	);

void HookCheckRemoteDebuggerPresent(
	);
BOOL fCheckRemoteDebuggerPresent(
	HANDLE hProcess,
	PBOOL pbDebuggerPresent
	);

struct tagPROCESSENTRY32;

void HookProcessFileName(
	);
BOOL fProcess32FirstW(
	HANDLE,
	struct tagPROCESSENTRY32* );
BOOL fProcess32NextW(
	HANDLE,
	struct tagPROCESSENTRY32* );

#endif