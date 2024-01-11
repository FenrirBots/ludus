#ifndef __MODULE_PATCHES_H_
#define __MODULE_PATCHES_H_
#include "inc/module/common.h"

BOOL fIsDebuggerPresent(
	);

BOOL fCheckRemoteDebuggerPresent(
	HANDLE hProcess,
	PBOOL pbDebuggerPresent
	);

#endif