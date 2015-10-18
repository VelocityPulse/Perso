#include "header.h"

char *f_capture_pseudo(void)
{
	t_str *pseudo;
	char c;
	char *str;

	pseudo = NULL;
	printf("Entrez votre pseudo ");
	while (_read(0, &c, 1))
		pseudo = add_str(pseudo, 0, c);
	str = export_str(pseudo);
	free_list(pseudo);
	return (str);
}

char *f_capture_text(void)
{
	t_str *text;
	char c;
	char *str;

	text = NULL;
	while (_read(0, &c, 1))
		text = add_str(text, 0, c);
	str = export_str(text);
	free_list(text);
	return (str);
}

DWORD WINAPI f_send(void*)
{
	char *pseudo;
	char *text;
	SOCKET s_socket;
	SOCKADDR_IN server;
	LPDWORD lpExitCode;

	lpExitCode = 0;
	pseudo = f_capture_pseudo();
	printf("Pseudo : %s\n", pseudo);
	printf("Connection en cours...\n");
	s_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr("192.168.1.10");
	server.sin_port = htons(4242);
	memset(&server.sin_zero, '\0', sizeof(server.sin_zero));

	while (connect(s_socket, (SOCKADDR *)&server, sizeof(server)) == SOCKET_ERROR)
		printf("Connexion impossible\nNouvel essai...\n");
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

			if (!f_exit_client(text))
			{
				printf("LOOOOOOOOL\n");
				if (send(s_socket, text, (int)strlen(text), 0) == SOCKET_ERROR)
				{
					printf("Erreur de transmission de donnees\n");
					system("PAUSE");
					return (0);
				}
			}
			else
			{
				shutdown(s_socket, SD_SEND);
				closesocket(s_socket);
				WSACleanup();
				system("PAUSE");
				GetExitCodeThread(GetCurrentThread(), lpExitCode);
				ExitThread(*lpExitCode);
				return (0);
			}
		}
	}
	return (0);
}