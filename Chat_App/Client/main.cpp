#include "header.h"

extern bool quit;
bool connected = 0;

int main()
{
	HANDLE h_receive;
	HANDLE h_send;
	WSADATA wsaData;

	if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0)
		printf("Creation d'un flux de donnee impossible\n");
	else
	{
		h_receive = CreateThread(0, 0, f_receive, 0, 0, 0);
		h_send = CreateThread(0, 0, f_send, 0, 0, 0);
		while (quit != 1)
			Sleep(200);
		Sleep(100);
		system("EXIT");
	}
	return (0);
}