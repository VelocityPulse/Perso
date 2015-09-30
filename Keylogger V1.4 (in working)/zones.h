#ifndef _ZONES_H
# define _ZONES_H

# include <Windows.h>
# include <stdio.h>

# include "structs.h"

short zone1(int key_value, keyboard_status kb_status);
short z1_alt_gr(int key_value, keyboard_status kb_status);

short zone2(int key_value, keyboard_status kb_status);
short z2_num_pad(int key_value);

short zone3(int key_value, keyboard_status kb_status);
short z3_alt_gr(int key_value, keyboard_status kb_status);
short z3_min(int key_value);
short z3_maj(int key_value);

short zone4(int key_value, keyboard_status kb_status);
short z4_alt_gr(int key_value, keyboard_status kb_status);
short z4_min(int key_value);
short z4_maj(int key_value);

short zone5(int key_value, keyboard_status kb_status);
short zone6(int key_value, keyboard_status kb_status);

#endif // _ZONES_H