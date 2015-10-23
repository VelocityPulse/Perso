#include "header.h"

extern SOCKET s_socket;
extern bool connected;

DWORD WINAPI f_receive(void*)
{
	char buff[40];
	int n;
	t_str *chain;

	chain = NULL;
	n = 0;
	while (1)
	{
		if (connected == 1)
		{
			do {
				n = recv(s_socket, buff, sizeof(buff) - 1, 0);
				if (n >= 0 && n <= 40)
					buff[n] = 0;
				chain = add_str(chain, buff, 0);
			} while (n == sizeof(buff) - 1);

			printf("%s", export_str(chain));
			chain = free_list(chain);
		}
		else
			Sleep(500);
	}
}