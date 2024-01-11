#include "inc/module/common.h"
#include "inc/module/threads.h"

BOOL DllMain(
	HINSTANCE instance,
	DWORD reason,
	LPVOID reserved )
{
	switch (reason)
	{
		case DLL_PROCESS_ATTACH:
			if (DisableThreadLibraryCalls(instance))
			{
				CreateThread(0, 0, Startup, instance, 0, 0);
				return TRUE;
			}

			return FALSE;
		case DLL_PROCESS_DETACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		default:
	}

	return TRUE;

	(void) reserved;
}