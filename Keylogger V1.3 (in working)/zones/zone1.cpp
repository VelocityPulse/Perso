#include "zones.h"

unsigned char zone1(int key_value, keyboard_status kb_status)
{
	if (kb_status.ctrl == 1) // CTRL enfoncé
		return (0);
	else if (kb_status.alt_gr == 1) // ALT_GR enfoncé
		return (z1_alt_gr(key_value, kb_status)); 
	else if (kb_status.shift == 1) // SHIFT enfoncé
	{
		if (kb_status.verr_maj == 1) // status maj 1
			return (key_value + 32); 
		else						 // status maj 0
			return (key_value);
	}
	else // sans SHIFT
	{
		if (kb_status.verr_maj == 1)
			return (key_value);
		else
			return (key_value + 32);
	}
}

unsigned char z1_alt_gr(int key_value, keyboard_status kb_status)
{
	if (kb_status.shift == 1)
		return (0);
	else if (key_value == 69)
		return (128);
	else
		return (0);
}