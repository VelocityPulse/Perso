#include <Windows.h>
#include <stdio.h>

HHOOK _hook;
KBDLLHOOKSTRUCT kbdStruct;

LRESULT __stdcall HookProcedure(int nCode, WPARAM wParam, LPARAM lParam)
{
	static bool active;
	if (nCode >= 0)
	{
		if (wParam == WM_KEYDOWN)
		{
			kbdStruct = *((KBDLLHOOKSTRUCT*)lParam);
			if (kbdStruct.vkCode == VK_F2)
			{
				//MessageBox(NULL, L"F2 is pressed!", L"key pressed", MB_ICONINFORMATION);
				if (active == 0)
				{
					active = 1;
					while (active = 1)
					{
						Sleep(50);
						
						keybd_event(0x39, 0, 0, 0);							// ç
						keybd_event(0x39, 0, KEYEVENTF_KEYUP, 0);

						keybd_event('A', 0, 0, 0);							// a
						keybd_event('A', 0, KEYEVENTF_KEYUP, 0);

						keybd_event(VK_SPACE, 0, 0, 0);						// space
						keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);

						keybd_event('V', 0, 0, 0);							// v
						keybd_event('V', 0, KEYEVENTF_KEYUP, 0);

						keybd_event('A', 0, 0, 0);							// a
						keybd_event('A', 0, KEYEVENTF_KEYUP, 0);
						
						keybd_event(VK_SPACE, 0, 0, 0);						// space
						keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);

						keybd_event(VK_SHIFT, 0, 0, 0); // shift

						keybd_event(188, 0, 0, 0);							// ? 
						keybd_event(188, 0, KEYEVENTF_KEYUP, 0);

						keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);

						keybd_event(VK_RETURN, 0, 0, 0);					// entrer
						keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
					}
				}
				else
					active = 0;
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
	MSG msg;

	printf("push F2 for spam Mathias !!:D\n");
	SetHook();
	GetMessage(&msg, NULL, 0, 0);
	ReleaseHook();
	return (0);
}


