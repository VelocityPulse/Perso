#include "zones.h"

short zone5(int key_value, keyboard_struct kb_status)
{
	if (key_value == 13)
		return ('\n');
	else if (key_value == 8)
	{
		 // fuck
		return (215); // retour en arrière ATTENTION -> variantes possibles 
	}

	else
		return (0);
}