#include "zones.h"

short zone6(int key_value, keyboard_struct kb_status)
{
	if (key_value == 192)
		return ('²');
	else if (key_value == 32)
		return (' ');
	else 
		return (0);
}