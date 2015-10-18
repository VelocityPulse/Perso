#ifndef _HEADER_H
#define _HEADER_H

#include <stdio.h>
#include <winsock2.h>
#include <io.h>

#include "list.h"

typedef struct struct_info {
	SOCKET		s_server;
	SOCKADDR_IN	server_addr;
}				s_info;

void f_server(void);
DWORD WINAPI f_client(__in LPVOID lpParameter);
void f_accept(SOCKET s_server, SOCKADDR_IN server_addr);

void f_multicast(char *text, int src);
void f_broadcast_pseudo(char *pseudo);
void f_broadcast(char *text);

bool f_exit_client(char *text);

#endif // _HEADER_H