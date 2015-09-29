#include "header.h"
# define WM_SYSKEYUP 257

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
	keyboard_struct = *((KBDLLHOOKSTRUCT*)lParam);
	if (nCode >= 0);
	{
		if (wParam == WM_KEYDOWN)
			analyse_keyboard_status(keyboard_struct.vkCode);
		else if (wParam == WM_SYSKEYDOWN && keyboard_struct.vkCode != 126)
			keybd_event(VK_CONTROL, 0, 0, 0);
		else if (wParam == WM_SYSKEYUP && keyboard_struct.vkCode == 165)
			keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
	}
	return CallNextHookEx(hook, nCode, wParam, lParam);
}

void ReleaseHook()
{
	UnhookWindowsHookEx(hook);
}