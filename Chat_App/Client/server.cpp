#include "header.h"

SOCKET s_client[100];
SOCKADDR_IN client[100];
HANDLE h_thread[100];
int i = 1;

char *reception(SOCKET client)
{
	char buff[40];
	char *str;
	t_str *chain;
	int n;

	n = 0;
	chain = NULL;
	do {
		n = recv(client, buff, sizeof(buff) - 1, 0);
		buff[n] = 0;
		chain = add_str(chain, buff, 0);
	} while (n == sizeof(buff) - 1);
	str = export_str(chain);
	free_list(chain);
	return (str);
}

DWORD WINAPI f_client(LPVOID lpParameter)
{
	int id;
	char *pseudo;
	char *final_message;
	char *message;
	t_str *chain;
	DWORD ExitCode;

	chain = NULL;
	ExitCode = NULL;
	id = (int)lpParameter;
	chain = add_str(chain, reception(s_client[id]), 0);
	pseudo = export_str(chain);
	chain = free_list(chain);
	f_broadcast_pseudo(pseudo);
	while (1)
	{
		message = reception(s_client[id]); 
		if (!f_exit_client(message))
		{
			chain = add_str(chain, pseudo, 0);
			chain = add_str(chain, " : ", 0);
			chain = add_str(chain, message, 0);
			chain = add_str(chain, 0, '\n');
			final_message = export_str(chain);
			chain = free_list(chain);
			f_multicast(final_message, id);
		}
		else
		{
			chain = add_str(chain, "SERVEUR :: ", 0);
			chain = add_str(chain, pseudo, 0);
			chain = add_str(chain, " s'est deconnecter\n", 0);
			final_message = export_str(chain);
			chain = free_list(chain);
			f_multicast(final_message, id);

			shutdown(s_client[id], SD_SEND);
			closesocket(s_client[id]);
			GetExitCodeThread(h_thread[id], &ExitCode);
			TerminateThread(h_thread[id], ExitCode);
		}
	}
}

void f_accept(SOCKET s_server, SOCKADDR_IN server_addr)
{
	int csize;

	csize = sizeof(client[i]);
	s_client[i] = accept(s_server, (SOCKADDR *)&client[i], &csize);
	if (s_client[i] == INVALID_SOCKET)
		printf("Erreur fonction accept\n");
	else
	{
		printf("Le client %s s'est connecte\n", inet_ntoa(client[i].sin_addr));
		h_thread[i] = CreateThread(0, 0, f_client, (void*)i, 0, 0);
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
		while (i < 100)
			f_accept(s_server, server_addr);
	}
}