#include "zones.h"

unsigned char zone3(int key_value, keyboard_status kb_status)
{
	if (kb_status.ctrl == 1) // NI CONTROLE
		return (0);
	else if (kb_status.alt_gr == 1) // ALT_GR enfoncé
		return (z3_alt_gr(key_value, kb_status)); // vérifier maj
	else if (kb_status.shift == 1)
	{
		if (kb_status.verr_maj == 1)
			return (z3_min(key_value));
		else
			return (z3_maj(key_value));
	}
	else
	{
		if (kb_status.verr_maj == 1)
			return (z3_maj(key_value));
		else
			return (z3_min(key_value));
	}
}

unsigned char z3_alt_gr(int key_value, keyboard_status kb_status)
{
	if (kb_status.shift == 1)
		return (0);
	else
	{
		switch (key_value)
		{
		case 186:
			return ('¤');
			break;
		case 187:
			return ('}');
			break;
		case 219:
			return (']');
		default:
			return (0);
		}
	}
}

unsigned char z3_min(int key_value)
{
	switch (key_value)
	{
	case 186 :
		return ('$');
		break;
	case 187 : 
		return ('=');
		break;
	case 188 :
		return (',');
		break;
	case 190 :
		return (';');
		break;
	case 191 :
		return (':');
		break;
	case 192 :
		return ('ù');
		break;
	case 219 :
		return (')');
		break;
	case 220 :
		return ('*');
		break;
	case 221 :
		return ('^');
		break;
	case 223 :
		return ('!');
		break;
	case 226 :
		return ('<');
	}
}

unsigned char z3_maj(int key_value)
{
	switch (key_value)
	{
	case 186:
		return ('£');
		break;
	case 187:
		return ('+');
		break;
	case 188:
		return ('?');
		break;
	case 190:
		return ('.');
		break;
	case 191:
		return ('/');
		break;
	case 192:
		return ('%');
		break;
	case 219:
		return ('°');
		break;
	case 220:
		return ('µ');
		break;
	case 221:
		return ('¨');
		break;
	case 223:
		return ('§');
		break;
	case 226:
		return ('>');
	}
}



