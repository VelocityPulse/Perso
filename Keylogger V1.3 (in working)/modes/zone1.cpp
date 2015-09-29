#include "zones.h"

unsigned char zone1(int key_value, keyboard_status kb_status)
{
	if (kb_status.shift != 0 && kb_status.shift != 1)
	{
		if (kb_status.verr_maj == 1)
			return (key_value + 32); // inversement car shift appuyé
		else
			return (key_value);
	}
	else
	{
		if (kb_status.verr_maj == 1)
			return (key_value);
		else
			return (key_value + 32);
	}
}