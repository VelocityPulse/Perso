#include <Windows.h>
#include <stdio.h>

HHOOK _hook;
KBDLLHOOKSTRUCT kbdStruct;

LRESULT __stdcall HookProcedure(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode >= 0)
	{
		if (wParam == WM_KEYDOWN)
		{
			kbdStruct = *((KBDLLHOOKSTRUCT*)lParam);
			if (kbdStruct.vkCode == VK_F2)
			{
				//MessageBox(NULL, L"F1 is pressed!", L"key pressed", MB_ICONINFORMATION);
				int cpt = 4;
				while (cpt--)
				{
					keybd_event('A', 0, 0, 0);
					keybd_event('A', 0, KEYEVENTF_KEYUP, 0);
				}

			}
		}
	}
	return CallNextHookEx(_hook, nCode, wParam, lParam);
}

void SetHook()
{
	if (!(_hook = SetWindowsHookEx(WH_KEYBOARD_LL, HookProcedure, NULL, 0)))
	{
		MessageBox(NULL, L"Failed to install hook!", L"Error", MB_ICONERROR);
	}
}

void ReleaseHook()
{
	UnhookWindowsHookEx(_hook);
}

int main()
{
	SetHook();
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		SetHook();
	}
	ReleaseHook();

	return (0);
}






