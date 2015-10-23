#ifndef _HEADER_H
# define _HEADER_H

//# include <Windows.h>
# include <stdio.h>
# include <winsock2.h>
# include <io.h>

# include "str_list.h"
# include "client_list.h"

DWORD WINAPI f_client(LPVOID data);
void f_accept(client_list client, SOCKET s_server);
void f_server(void);

bool f_exit_client(char *text);

char *reception(SOCKET client);
void f_broadcast_pseudo(char *pseudo);
void f_multicast(char *message, int src);


#endif // _HEADER_H