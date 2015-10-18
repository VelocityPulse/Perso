#include "header.h"

SOCKET *s_client;
SOCKADDR_IN *client;
HANDLE *h_thread;
int i = 1;

DWORD WINAPI f_client(__in LPVOID lpParameter)
{
	int id;
	char buff[1];
	char *pseudo;
	char *text;
	t_str *chain;
	LPDWORD lpExitCode;

	chain = NULL;
	lpExitCode = NULL;
	id = (int)lpParameter;
	while (recv(s_client[id], buff, sizeof(buff) - 1, 0))
		chain = add_str(chain, 0, buff[0]);
	pseudo = export_str(chain);
	free_list(chain);
	f_broadcast_pseudo(pseudo);
	while (1)
	{
		chain = add_str(chain, pseudo, 0);
		chain = add_str(chain, " : ", 0);
		while (recv(s_client[id], buff, sizeof(buff) - 1, 0))
			chain = add_str(chain, 0, buff[0]);
		chain = add_str(chain, 0, '\n');
		text = export_str(chain);
		free_list(chain);
		if (!f_exit_client(text))
			f_multicast(text, id);
		else
		{
			chain = add_str(chain, "Le client ", 0);
			chain = add_str(chain, pseudo, 0);
			chain = add_str(chain, " s'est deconnecter\n", 0);
			text = export_str(chain);
			free_list(chain);
			f_multicast(text, id);
			closesocket(s_client[id]);
			GetExitCodeThread(h_thread[id], lpExitCode);
			ExitThread(*lpExitCode);
		}
	}
}

void f_accept(SOCKET s_server, SOCKADDR_IN server_addr)
{
	int csize;

	s_client = (SOCKET *)realloc(s_client, sizeof(SOCKET) * i);
	client = (SOCKADDR_IN)realloc(client, sizeof(SOCKADDR_IN) * i);
	h_thread = (HANDLE *)realloc(h_thread, sizeof(HANDLE) * i);
	csize = sizeof(client[i]);
	s_client[i] = accept(s_server, (SOCKADDR *)&client[i], &csize);
	if (s_client[i] == INVALID_SOCKET)
		printf("Erreur fonction accept\n");
	else
	{
		printf("Le client %s s'est connecte\n", inet_ntoa(client[i].sin_addr));
		h_thread[i] = CreateThread(0, 0, f_client, &i, 0, 0);
		i++;
	}	
	return;
}

void f_server(void)
{
	SOCKET s_server;
	SOCKADDR_IN server_addr;

	s_server = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	printf("Creation d'un point de connection en cours...\n");
	
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(4242);
	memset(&server_addr.sin_zero, '\0', sizeof(server_addr.sin_zero));

	bind(s_server, (SOCKADDR *)&server_addr, sizeof(server_addr));
	if (listen(s_server, 0) == SOCKET_ERROR)
		printf("Impossible d'ecouter...\n");
	else
	{ 
		while (1)
			f_accept(s_server, server_addr);
	}
}