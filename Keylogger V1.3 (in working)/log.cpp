#include "header.h"
#include "zones.h"

keyboard_status kb_status;

keyboard_status init_kb_status(int key_value)
{
	kb_status.verr_maj	= GetKeyState(VK_CAPITAL);
	kb_status.verr_num	= GetKeyState(VK_NUMLOCK);
	kb_status.zone		= key_zone(key_value);
	// ---------------------------
	if (GetKeyState(VK_SHIFT) == -127 || GetKeyState(VK_SHIFT) == -128)
		kb_status.shift = 1;
	else
		kb_status.shift = 0;
	// ---------------------------
	if (GetKeyState(VK_CONTROL) == -127 || GetKeyState(VK_CONTROL) == -128)
		kb_status.ctrl = 1;
	else
		kb_status.ctrl = 0;
	// ---------------------------
	if (GetKeyState(VK_MENU) == -127 || GetKeyState(VK_MENU) == -128)
		kb_status.alt_gr = 1; 
	else
		kb_status.alt_gr = 0; 
	// ---------------------------
	return (kb_status);
}

short zone(int key_value)
{
	if (key_value >= 65 && key_value <= 90) // lettres
		return (1); // 1		
	else if (key_value >= 96 && key_value <= 111 ) // nums pad
		return (2); // 2
	else if (key_value >= 48 && key_value <= 57) // nums
		return (3); // 3
	else if (key_value == 186 || key_value == 187 || key_value == 188 || key_value == 190 
		|| key_value == 191 || key_value == 192 || key_value == 219 || key_value == 220 
		|| key_value == 221	|| key_value == 223 || key_value == 226)
		return (4); // 4
	else if (key_value == 13 || key_value == 8)  // entrer  supp
		return (5); // 5 
	else if (key_value == 192) // ²
		return (6); // 6
	else
	{
		printf(" unsigned "); // xxxxxxxxxxxxxxxx a supprimer
		return (0);
	}
}

unsigned char translate_key_value(int key_value)
{
	init_kb_status(key_value);
	if (kb_status.ctrl != 1 && kb_status.ctrl != 0)
		return (0);
	switch (kb_status.zone)
	{
	case 0 :
		return (0);
		break;
	case 1 :
		return (zone1(key_value, kb_status)); 
		break;
	case 2 :
		return (zone2(key_value, kb_status));
		break;
	case 3 :
		return (zone3(key_value, kb_status));
		break;
	case 4 :
		return (zone3(key_value, kb_status));
		break;
	case 5 :
		return (zone4(key_value, kb_status));
		break;
	case 6 :
		return (zone5(key_value, kb_status));
		break;
	}
}

void analyse_keyboard_status(int key_value)
{
	unsigned char charactere;

	charactere = 0;
	charactere = translate_key_value(key_value);
	if (charactere)
		printf("%c", charactere);
}





