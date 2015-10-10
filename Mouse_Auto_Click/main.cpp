#include <Windows.h>
#include <stdio.h>

HHOOK mouse_Hook;
HHOOK keyboard_Hook;
MOUSEHOOKSTRUCT mouse_Struct;
KBDLLHOOKSTRUCT keyboard_Struct;
MOUSEMOVEPOINT mouse_position;
bool F2;
RECT area;

LRESULT __stdcall HookMouseProcedure(int nCode, WPARAM wParam, LPARAM lParam)
{
	static bool blocked;
	static bool up;
	static short state;
	POINT coor;
	
	mouse_Struct = *((MOUSEHOOKSTRUCT*)lParam);
	printf("%d, %d\n", mouse_Struct.pt.x, mouse_Struct.pt.y);
	if (F2)
	{
		if (blocked == 0)
		{
			coor = mouse_Struct.pt;
			area.top = coor.y;
			area.bottom = coor.y;
			area.right = coor.x;
			area.left = coor.x;
			ClipCursor(&area);
			blocked = 1;
			printf("saving\n");
			printf("%d, %d", coor.x, coor.y);
		}
		else
		{
			coor = mouse_Struct.pt;
			state = GetKeyState(VK_F2);
			while (state == GetKeyState(VK_F2))
			{
				if (up == 0)
				{
					Sleep(1);
					mouse_event(MOUSEEVENTF_LEFTDOWN, coor.x, coor.y, 0, 0);
					printf("1");
					up = 1;
				}
				else
				{
					Sleep(1);
					mouse_event(MOUSEEVENTF_LEFTUP, coor.x, coor.y, 0, 0);
					up = 0;
				}
			}
			F2 = 0;
			blocked = 0;
			ClipCursor(NULL);
		}
	}
	else
	{
		blocked = 0;
		ClipCursor(NULL);
	}	
	return (CallNextHookEx(mouse_Hook, nCode, wParam, lParam));
}

LRESULT __stdcall HookKeyBoardProcedure(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (wParam == WM_KEYDOWN)
	{
		keyboard_Struct = *((KBDLLHOOKSTRUCT*)lParam);
		if (keyboard_Struct.vkCode == VK_F2)
		{
			if (F2 == 0)
				F2 = 1;
			else
				F2 = 0;
		}
	}
	return CallNextHookEx(keyboard_Hook, nCode, wParam, lParam);
}

void SetMouseHook(void)
{
	int count;

	count = 4;
	if (!(mouse_Hook = SetWindowsHookEx(WH_MOUSE_LL, HookMouseProcedure, NULL, 0)))
	{
		printf("Mouse hook installation error\n");
		Sleep(100);
		printf("New try in ");
		while (count >= 0)
		{
			printf("%d ", count);
			count--;
			Sleep(1000);
		}
		putchar('\n');
		SetMouseHook();
	}
}

void SetKeyBoardHook()
{
	int count;

	count = 4;
	if (!(keyboard_Hook = SetWindowsHookEx(WH_KEYBOARD_LL, HookKeyBoardProcedure, NULL, 0)))
	{
		printf("Keyboard hook installation error\n");
		Sleep(100);
		printf("New try in ");
		while (count >= 0)
		{
			printf("%d ", count);
			count--;
			Sleep(1000);
		}
		putchar('\n');
		SetKeyBoardHook();
	}
}


int main()
{
	MSG msg;

	SetMouseHook();
	SetKeyBoardHook();
	GetMessage(&msg, NULL, 0, 0);
	return (0);
}