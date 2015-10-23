#include "header.h"

extern client_list *l_client;

char *reception(SOCKET client)
{
	char buff[40] = { 0 };
	char *str;
	t_str *chain;
	int n;

	n = 0;
	chain = NULL;
	do {
		n = recv(client, buff, sizeof(buff) - 1, 0);
		if (n <= 0 && n >= 40)
			buff[n] = 0;
		chain = add_str(chain, buff, 0);
	} while (n == sizeof(buff) - 1);
	str = export_str(chain);
	free_str_list(chain);
	return (str);
}

void f_broadcast_pseudo(char *pseudo)
{
	t_str		*chain;
	client_list *guest;
	char		*str;
	int			nbr_client;
	int			i;

	chain = NULL;
	i = 0;
	chain = add_str(chain, "SERVEUR :: ", 0);
	chain = add_str(chain, pseudo, 0);
	chain = add_str(chain, " est en ligne.\n", 0);
	str = export_str(chain);
	chain = free_str_list(chain);
	printf("%s", str);
	nbr_client = cpt_index_client(l_client);
	while (i <= nbr_client)
	{
		guest = get_client(l_client, i);
		if (guest != NULL)
			send(guest->s_client, str, (int)strlen(str), 0);
		i++;
	}
}

void f_multicast(char *message, int src)
{
	int nbr_client;
	int i;
	client_list *guest;

	i = 0;
	nbr_client = cpt_index_client(l_client);
	printf("%s", message);
	while (i <= nbr_client)
	{
		guest = get_client(l_client, i);
		if (guest != NULL && guest->index != src)
			send(guest->s_client, message, (int)strlen(message), 0);			
		i++;
	}

}

