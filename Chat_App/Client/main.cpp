#include "header.h"




int main()
{
	HANDLE h_receive;
	HANDLE h_send;
	MSG msg;
	WSADATA wsaData;

	if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0)
		printf("Creation d'un flux de donnee impossible\n");
	else
	{
//		h_receive = CreateThread(0, 0, f_receive, 0, 0, 0);
		h_send = CreateThread(0, 0, f_send, 0, 0, 0);
		GetMessage(&msg, 0, 0, 0);
	}
	return (0);
}