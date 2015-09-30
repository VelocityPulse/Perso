#ifndef _HEADER_H
# define _HEADER_H

# include <Windows.h>
# include <Stdio.h> // à effacer

#include "structs.h"

void StartKeyBoardHook();
LRESULT __stdcall HookProcedure(int nCode, WPARAM wParam, LPARAM lParam);
void ReleaseHook();


void init_kb_status(int key_value);
short key_zone(int key_value);
short translate_key_value(keyboard_status kb_status, int key_value);
void analyse_keyboard_status(int key_value);

#endif // _HEADER_H
