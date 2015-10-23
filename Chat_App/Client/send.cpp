#include "header.h"

bool quit = 0;
SOCKET s_socket;
extern bool connected;

char *f_capture_pseudo(void)
{
	t_str *pseudo;
	char c;
	char *str;
	int width;
	int i;

	i = 0;
	pseudo = NULL;
	printf("Entrez votre pseudo ");
	while (_read(0, &c, 1))
		pseudo = add_str(pseudo, 0, c);
	str = export_str(pseudo);
	width = cpt_index(pseudo);
	if (width == 0)
		str = f_capture_pseudo();
	while (str[i])
	{
		if (str[i] == ' ')
		{
			i = 0;
			str = f_capture_pseudo();
		}
		i++;
	}
	pseudo = free_list(pseudo);
	return (str);
}

char *f_capture_text(void)
{
	t_str *text;
	char c;
	char *str;
	int width;

	text = NULL;
	while (_read(0, &c, 1))
		text = add_str(text, 0, c);
	str = export_str(text);
	width = cpt_index(text);
	if (width == 0)
		str = f_capture_text();
	text = free_list(text);
	return (str);
}

DWORD WINAPI f_send(void*)
{
	char *pseudo;
	char *text;
	t_str *chain;
	
	SOCKADDR_IN server;
	DWORD ExitCode;

	chain = NULL;
	ExitCode = 0;
	pseudo = f_capture_pseudo();
	printf("Pseudo : %s\n", pseudo);
	printf("Connection en cours...\n");
	s_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr("192.168.1.32"); // pensez bien à préciser ici l'adresse de votre serveur
	server.sin_port = htons(4242);
	memset(&server.sin_zero, '\0', sizeof(server.sin_zero));

	while (connect(s_socket, (SOCKADDR *)&server, sizeof(server)) == SOCKET_ERROR)
	{
		printf("Connexion impossible\nNouvel essai...\n");
		Sleep(400);
		connected = 0;
	}
	connected = 1;
	printf("\t-------- Connexion etablie --------\n");
	if (send(s_socket, pseudo, (int)strlen(pseudo), 0) == SOCKET_ERROR)
	{
		printf("Erreur de transmission de donnees\n");
		system("PAUSE");
		return (0);
	}
	else
	{
		printf("Tapez \"EXIT PROGRAM\" pour quitter le programme\n");
		while (1)
		{
			text = f_capture_text();
			if (f_exit_client(text) == 0)
			{
				chain = add_str(chain, text, 0);
				chain = add_str(chain, 0, '\n');
				text = export_str(chain);
				if (send(s_socket, text, cpt_index(chain) - 1, 0) == SOCKET_ERROR)
				{
					printf("Erreur de transmission de donnees\n");
					system("PAUSE");
					system("EXIT");
					return (0);
				}
				chain = free_list(chain);
			}
			else
			{
				connected = 0;
				printf("Deconnection...\n");
				shutdown(s_socket, SD_SEND);
				closesocket(s_socket);
				WSACleanup();
				printf("Fermeture du client en court...\n");
				Sleep(300);
				printf("Le programme va se fermer...\n");
				Sleep(300);
				quit = 1;
				GetExitCodeThread(GetCurrentThread(), &ExitCode);
				ExitThread(ExitCode);
				return (0);
			}
		}
	}
	return (0);
}