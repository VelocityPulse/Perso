#ifndef _CLIENT_LIST_H
# define _CLIENT_LIST_H

# include <stdio.h>
# include <stdlib.h>
# include <Windows.h>

typedef struct	s_client_list {
	SOCKET					s_client;
	SOCKADDR_IN				addr;
	HANDLE					h_client;
	int						index;
	struct s_client_list	*next;
}				client_list;

int			cpt_index_client(client_list *begin);
client_list *push_client_list(client_list *begin);
client_list *add_client_list(void);
client_list *get_client(client_list *begin, int index);
client_list *get_last_client(client_list *begin);
client_list *supp_client_list(client_list *begin, int index);
client_list *parent_client_list(client_list *begin, client_list *list);
client_list *free_client_list(client_list *begin);


#endif // _CLIENT_LIST_H