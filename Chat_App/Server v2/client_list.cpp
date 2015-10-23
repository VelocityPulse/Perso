#include "client_list.h"

int cpt_index_client(client_list *begin)
{
	client_list *list;
	int nbr;

	nbr = 0;
	if (!begin)
		begin = add_client_list();
	list = begin;
	while (list->next)
	{
		//printf("%d ", list->index);
		nbr++;
		list = list->next;
	}
//	putchar('\n');
	return (nbr);
}

client_list *push_client_list(client_list *begin)
{
	client_list *list;

	if (begin)
	{
		list = begin;
		while (list->next)
			list = list->next;
		list->next = add_client_list();
		list->next->index = list->index + 1;
		return (begin);
	}
	else
		return (add_client_list());
}

client_list *supp_client_list(client_list *begin, int index)
{
	client_list *list;
	client_list *parent;

	if (!begin)
		begin = add_client_list();
	list = begin;
	while (list->next)
	{
		parent = parent_client_list(begin, list);
		if (list->index == index)
		{
			if (parent == list)
			{
				begin = begin->next;
				free(parent);
				return (begin);
			}
			parent->next = list->next;
			free(list);
			list = parent;
			return (begin);
		}
		list = list->next;
	}
	return (begin);
}

client_list *parent_client_list(client_list *begin, client_list *list)
{
	if (begin == list)
		return (begin);
	while (begin->next)
	{
		if (begin->next == list)
			return (begin);
		else
			begin = begin->next;
	}
	return (begin);
}

client_list *get_client(client_list *begin, int index)
{
	client_list *list;

	if (!begin)
		begin = add_client_list();
	list = begin;
	while (list)
	{
		if (list->index == index)
			return (list);
		list = list->next;
	}
	return NULL;
}

client_list *get_last_client(client_list *begin)
{
	client_list *list;

	if (!begin)
		begin = add_client_list();
	list = begin;
	while (list->next)
		list = list->next;
	return (list);
}

client_list *add_client_list(void)
{
	client_list *list;

	list = (client_list *)malloc(sizeof(client_list));
	list->s_client = NULL;
	list->addr = { 0 };
	list->h_client = NULL;
	list->index = 1;
	list->next = NULL;
	return (list);
}

client_list *free_client_list(client_list *begin)
{
	client_list *next;

	if (!begin)
		return (0);
	if (begin->next)
	{
		while (begin->next)
		{
			next = begin;
			begin = begin->next;
			free(next);
		}
	}
	free(begin);
	begin = NULL;
	return (begin);
}
