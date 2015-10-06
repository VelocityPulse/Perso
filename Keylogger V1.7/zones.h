#ifndef _ZONES_H
# define _ZONES_H

# include <Windows.h>
# include <Stdio.h>

# include "structs.h"

short	zone1(int key_value, keyboard_struct kb_status);
short	z1_alt_gr(int key_value, keyboard_struct kb_status);

short	zone2(int key_value, keyboard_struct kb_status);
short	z2_num_pad(int key_value);

short	zone3(int key_value, keyboard_struct kb_status);
short	z3_alt_gr(int key_value, keyboard_struct kb_status);
short	z3_min(int key_value, keyboard_struct kb_status);
short	z3_maj(int key_value, keyboard_struct kb_status);

short	zone4(int key_value, keyboard_struct kb_status);
short	z4_alt_gr(int key_value, keyboard_struct kb_status);
short	z4_min(int key_value);
short	z4_maj(int key_value);

short	zone5(int key_value, keyboard_struct kb_status);
short	z5_supp(int key_value);
wchar_t	*z5_str_add(wchar_t *src, wchar_t *str);

short	zone6(int key_value, keyboard_struct kb_status);

#endif // _ZONES_H