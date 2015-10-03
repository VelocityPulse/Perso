#include "zones.h"

short zone4(int key_value, keyboard_struct kb_status)
{
	if (kb_status.alt_gr == 1)
		return (z4_alt_gr(key_value, kb_status));
	else if (kb_status.shift == 1)
	{
		if (kb_status.verr_maj == 1)
			return (z4_min(key_value));
		else
			return (z4_maj(key_value));
	}
	else
	{
		if (kb_status.verr_maj == 1)
			return (z4_maj(key_value));
		else
			return (z4_min(key_value));
	}
}

short z4_alt_gr(int key_value, keyboard_struct kb_status)
{
	if (kb_status.shift == 1)
		return (0);
	else
	{
		switch (key_value)
		{
		case 48 : // @
			return ('@');
			break;
		case 50 : 
			return ('~');
			break;
		case 51 :
			return ('#');
			break;
		case 52 :
			return ('{');
			break;
		case 53 :
			return ('[');
			break;
		case 54 :
			return ('|');
			break;
		case 55 :
			return ('`');
			break;
		case 56 :
			return ('\\');
			break;
		case 57 :
			return ('^');
			break;
		default :
			return (0);
			break;
		}
	}
}

short z4_min(int key_value)
{
	switch (key_value)
	{
	case 48 :
		return ('à');
		break;
	case 49 :
		return ('&');
		break;
	case 50 :
		return ('é');
		break;
	case 51 :
		return ('"');
		break;
	case 52 :
		return ('\'');
		break;
	case 53 :
		return ('(');
		break;
	case 54 :
		return ('-');
		break;
	case 55 :
		return ('è');
		break;
	case 56 :
		return ('_');
		break;
	case 57 :
		return ('ç');
		break;
	default :
		return (0);
		break;
	}
}

short z4_maj(int key_value)
{
	switch (key_value)
	{
	case 48:
		return ('0');
		break;
	case 49:
		return ('1');
		break;
	case 50:
		return ('2');
		break;
	case 51:
		return ('3');
		break;
	case 52:
		return ('4');
		break;
	case 53:
		return ('5');
		break;
	case 54:
		return ('6');
		break;
	case 55:
		return ('7');
		break;
	case 56:
		return ('8');
		break;
	case 57:
		return ('9');
		break;
	default:
		return (0);
		break;
	}
}






