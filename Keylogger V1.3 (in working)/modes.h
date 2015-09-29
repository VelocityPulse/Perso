#ifndef _MODES_H
# define _MODES_H

# include <Windows.h>

# include "structs.h"

unsigned char mode_1(int key_value, keyboard_status kb_status);

unsigned char mode_2(int key_value, keyboard_status kb_status);

unsigned char mode_3(int key_value, keyboard_status kb_status);

#endif // _MODES_H