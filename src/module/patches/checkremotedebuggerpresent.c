#include "inc/module/common.h"
#include "inc/module/patches.h"

BOOL fCheckRemoteDebuggerPresent(
	HANDLE hProcess,
	PBOOL pbDebuggerPresent
	)
{
	*pbDebuggerPresent = FALSE;
	return TRUE;
}