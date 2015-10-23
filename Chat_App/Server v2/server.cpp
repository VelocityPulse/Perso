#include "header.h"

client_list *l_client; // liste des clients

// play back 
// https://coderpad.io/PXXNH2JM/playback

DWORD WINAPI f_client(LPVOID data)
{
	client_list		*client;
	int				index;
	t_str			*chain;
	char			*message;
	char			*pseudo;
	DWORD			ExitCode;
	HANDLE			h_temp;

	index = (int)data; // *(client_list *)&data;
	client = get_client(l_client, index);
	chain = NULL;
	chain = add_str(chain, reception(client->s_client), 0);
	pseudo = export_str(chain);
	chain = free_str_list(chain);
	f_broadcast_pseudo(pseudo);
	
	while (1)
	{
		message = reception(client->s_client);
		if (!f_exit_client(message)) // si le client n'a pas demandé une déconnexion
		{
			chain = add_str(chain, pseudo, 0);
			chain = add_str(chain, " : ", 0);
			chain = add_str(chain, message, 0);
			chain = add_str(chain, 0, '\n');
			f_multicast(export_str(chain), client->index);
			chain = free_str_list(chain);
		}
		else // si le client demande une déconnexion
		{
			// annonce
			chain = add_str(chain, "SERVEUR :: ", 0);
			chain = add_str(chain, pseudo, 0);
			chain = add_str(chain, " s'est deconnecter.\n", 0);
			f_multicast(export_str(chain), client->index);
			chain = free_str_list(chain);
			// déconnexion du client
			shutdown(client->s_client, SD_SEND);
			h_temp = client->h_client;
			l_client = supp_client_list(l_client, client->index);
			GetExitCodeThread(h_temp, &ExitCode);
			TerminateThread(h_temp, ExitCode);
		}
	}
}

void f_accept(client_list *client, SOCKET s_server)
{
	int ssize;

	ssize = (int)sizeof(client->addr);
	printf("SERVEUR :: En attente d'une connexion...\n");
	client->s_client = accept(s_server, (SOCKADDR *)&client->addr, &ssize);
	if (client->s_client == SOCKET_ERROR)
		printf("SERVEUR :: Tentative de connexion echouee...\n");
	else
	{
		printf("SERVEUR :: L'adresse %s s'est connecte.\n", inet_ntoa(client->addr.sin_addr));
		client->h_client = CreateThread(0, 0, f_client, (void*)client->index, 0, 0);
	}
}

void f_server(void)
{
	SOCKET        s_server;
	SOCKADDR_IN   server_addr;

	s_server = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(4242);
	memset(&server_addr.sin_zero, '\0', sizeof(server_addr.sin_zero));

	bind(s_server, (SOCKADDR *)&server_addr, sizeof(server_addr));
	if (listen(s_server, 0) == SOCKET_ERROR)
	{
		printf("SERVEUR :: Impossible d'ecouter\n");
		Sleep(500);
		f_server();
	}
	else
	{
		while (1)
		{
			l_client = push_client_list(l_client);
			f_accept(get_last_client(l_client), s_server);
		}
	}
}
