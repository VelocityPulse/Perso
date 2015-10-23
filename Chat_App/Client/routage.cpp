#include "header.h"

extern SOCKET s_client[100];
extern SOCKADDR_IN client[100];
extern HANDLE h_thread[100];
extern int i;

void f_broadcast(char *text)
{
	int id;
	int ex;

	id = 1;
	ex = 0;
	printf("%s", text);
	while (s_client[id] && id <= i)
	{
		send(s_client[id], text, (int)strlen(text), 0);
		ex = id;
		id++;
	}
}

void f_broadcast_pseudo(char *pseudo)
{
	int id;
	int ex;
	t_str *chain;
	char *str;

	chain = NULL;
	id = 1;
	ex = 0;
	chain = add_str(chain, "SERVEUR :: ", 0);
	chain = add_str(chain, pseudo, 0);
	chain = add_str(chain, " s'est connecter\n", 0);
	str = export_str(chain);
	printf("%s", str);
	chain = free_list(chain);
	while (id < i && s_client[id] != s_client[ex])
	{
		send(s_client[id], str, (int)strlen(str), 0);
		ex = id;
		id++;
	}
}

void f_multicast(char *text, int src)
{
	int id;
	int ex;

	id = 1;
	ex = 0;
	printf("%s", text);
	while (id < i && s_client[id] != s_client[ex])
	{
		if (id != src)
			send(s_client[id], text, (int)strlen(text), 0);
		ex = id;
		id++;
	}
}