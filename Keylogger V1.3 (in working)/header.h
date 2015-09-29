#ifndef _HEADER_H
# define _HEADER_H

# include <Windows.h>
# include <Stdio.h> // � effacer

#include "structs.h"


void StartKeyBoardHook();
LRESULT __stdcall HookProcedure(int nCode, WPARAM wParam, LPARAM lParam);
void ReleaseHook();


keyboard_status init_kb_status(int key_value);
short key_mode(int key_value);
unsigned char translate_key_value(keyboard_status kb_status, int key_value);
void analyse_keyboard_status(int key_value);

#endif // _HEADER_H
