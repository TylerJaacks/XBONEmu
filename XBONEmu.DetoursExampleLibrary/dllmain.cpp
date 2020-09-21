#include "pch.h"

#include "../Detours/src/detours.h"

static LONG dwSlept = 0;

// Target pointer for the uninstrumented Sleep API.
//
static VOID(WINAPI* TrueSleep)(DWORD dwMilliseconds) = Sleep;

// Detour function that replaces the Sleep API.
//
VOID WINAPI TimedSleep(DWORD dwMilliseconds)
{
	// Save the before and after times around calling the Sleep API.
	DWORD dwBeg = GetTickCount();
	TrueSleep(dwMilliseconds);
	DWORD dwEnd = GetTickCount();

	InterlockedExchangeAdd(&dwSlept, dwEnd - dwBeg);
}

// DllMain function attaches and detaches the TimedSleep detour to the
// Sleep target function.  The Sleep target function is referred to
// through the TrueSleep target pointer.
//
BOOL WINAPI DllMain(HINSTANCE hinst, DWORD dwReason, LPVOID reserved)
{
	if (DetourIsHelperProcess()) {
		return TRUE;
	}

	if (dwReason == DLL_PROCESS_ATTACH) {
		DetourRestoreAfterWith();

		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourAttach(&(PVOID&)TrueSleep, TimedSleep);
		DetourTransactionCommit();
	}
	else if (dwReason == DLL_PROCESS_DETACH) {
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourDetach(&(PVOID&)TrueSleep, TimedSleep);
		DetourTransactionCommit();
	}
	return TRUE;
}