#include "zones.h"

short zone2(int key_value, keyboard_struct kb_status)
{
	if (kb_status.alt_gr == 1 || kb_status.shift == 1 || kb_status.ctrl == 1)
		return (0);
	else
	{
		if (key_value >= 96 && key_value <= 105 && kb_status.verr_num == 1)
			return (key_value - 48);
		else
			return (z2_num_pad(key_value));
	}
}

short z2_num_pad(int key_value)
{
	switch (key_value)
	{
	case 106 :
		return ('*');
		break;
	case 107 :
		return ('+');
		break;
	case 109 :
		return ('-');
		break;
	case 110 :
		return ('.');
		break;
	case 111 :
		return ('/');
		break;
	default : // 108
		return (0);
	}
}