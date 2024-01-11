#include "inc/module/common.h"
#include "inc/module/threads.h"

DWORD Cleanup(
	LPVOID reserved )
{
	FreeLibraryAndExitThread((HMODULE)reserved, 0);
}