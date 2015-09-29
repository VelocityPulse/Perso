#ifndef _ZONES_H
# define _ZONES_H

# include <Windows.h>

# include "structs.h"

unsigned char zone1(int key_value, keyboard_status kb_status);

unsigned char zone2(int key_value, keyboard_status kb_status);
unsigned char z2_num_pad(int key_value);

unsigned char zone3(int key_value, keyboard_status kb_status);
unsigned char zone4(int key_value, keyboard_status kb_status);
unsigned char zone5(int key_value, keyboard_status kb_status);
unsigned char zone6(int key_value, keyboard_status kb_status);

#endif // _ZONES_H