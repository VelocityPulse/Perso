#include "zones.h"

unsigned char zone2(int key_value, keyboard_status kb_status)
{
	if (kb_status.alt_gr == 1 || kb_status.shift == 1 || kb_status.ctrl == 1)
		return (0);
	else
	{
		if (key_value >= 96 && key_value <= 105 && kb_status.verr_num == 0)
			return (key_value - 48);
		else
			return (z2_num_pad(key_value));
	}
}

unsigned char z2_num_pad(int key_value)
{
	switch (key_value)
	{
	case 106 :
		return (42);
		break;
	case 107 :
		return (43);
		break;
	case 108 :
		return (0);
		break;
	case 109 :
		return (45);
		break;
	case 110 :
		return (46);
		break;
	case 111 :
		return (47);
		break;
	default :
		return (0);
	}
}