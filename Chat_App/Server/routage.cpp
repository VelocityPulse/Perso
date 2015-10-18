#include "header.h"

void f_broadcast(char *text)
{
	int id;

	id = 1;
	while (s_client[id] && id <= i)
	{
		send(s_client[id], text, (int)strlen(text), 0);
		id++;
	}
}

void f_broadcast_pseudo(char *pseudo)
{
	int id;
	t_str *chain;
	char *str;

	chain = NULL;
	id = 1;
	chain = add_str(chain, pseudo, 0);
	chain = add_str(chain, "\ts'est connecter\n", 0);
	str = export_str(chain);
	free_list(chain);
	while (s_client[id] && id <= i)
	{
		send(s_client[id], str, (int)strlen(str), 0);
		id++;
	}
}

void f_multicast(char *text, int src)
{
	int id;

	id = 1;
	while (s_client[id] && id <= i)
	{
		if (id != src)
			send(s_client[id], text, (int)strlen(text), 0);
		id++;
	}
}