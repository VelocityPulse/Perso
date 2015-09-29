#include "header.h"
#include "modes.h"

keyboard_status kb_status;

keyboard_status init_kb_status(int key_value)
{
	kb_status.verr_maj	= GetKeyState(VK_CAPITAL);
	kb_status.verr_num	= GetKeyState(VK_NUMLOCK);
	kb_status.shift		= GetKeyState(VK_SHIFT);
	kb_status.ctrl		= GetKeyState(VK_CONTROL);
	kb_status.alt_gr	= GetKeyState(VK_RMENU);
	kb_status.mode		= key_mode(key_value);
	return (kb_status);
}

short key_mode(int key_value)
{
	if (key_value >= 65 && key_value <= 90) // lettres
		return (2); // 2		
	else if (key_value >= 96 && key_value <= 105) // nums pad
		return (1); // 1
	else if (key_value >= 48 && key_value <= 57) // nums
		return (1); // 1
	else if (key_value >= 186 && key_value <= 191) // :/  +=}  ,?  )°]  .;  !§
		return (1); // 1
	else if (key_value >= 219 && key_value <= 222) // ^¨  *µ  $£¤  ù%
		return (1); // 1
	else if (key_value == 192) // ²
		return (3); // 3
	else
	{
		printf(" unsigned "); // xxxxxxxxxxxxxxxx a supprimer
		return (0);
	}
}

unsigned char translate_key_value(int key_value)
{
	init_kb_status(key_value);
	if (kb_status.mode == 0)
		return (0);
	else if (kb_status.mode == 1) // char spéciaux
		return(mode_1(key_value, kb_status));
	else if (kb_status.mode == 2) // lettres
		return(mode_2(key_value, kb_status));
	else if (kb_status.mode == 3) // ²
		return(mode_3(key_value, kb_status));
}

void analyse_keyboard_status(int key_value)
{
	unsigned char charactere;

	charactere = 0;
	charactere = translate_key_value(key_value);
	if (charactere)
		printf("%c", charactere);

}





