#include "header.h"

int main()
{
	WSADATA wsaData;

	if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0)
		printf("Creation d'un flux de donnee impossible\n");
	else
		f_server();
}