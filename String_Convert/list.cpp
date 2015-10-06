#include "list.h"

t_str	*add_str(t_str *begin, char *str, char c)
{
	int i;
	t_str *list;

	i = 0;
	if (!begin)
		begin = add_list(NULL);
	list = begin;
	while (list->next)
		list = list->next;
	if (str)
	{
		while (str[i])
		{
			if (list->index < 32)
			{
				list->str[list->index] = str[i];
				list->index++;
				i++;
			}
			else
			{
				list->next = add_list(begin);
				list = list->next;
			}
		}
	}
	else if (c)
	{
		if (list->index < 32)
		{
			list->str[list->index] = c;
			list->index++;
		}
		else
		{
			list->next = add_list(begin);
			list = list->next;
			list->str[list->index] = c;
			list->index++;
		}
	}
	return (begin);
}

char *export_str(t_str *begin)
{
	int i;
	int i2;
	char *str;

	i = 0;
	i2 = 0;
	if (!begin)
		begin = add_list(NULL);
	str = (char *)malloc(sizeof(char) * cpt_index(begin) + 1);
	if (begin->next)
	{
		while (begin->next)
		{
			while (i < 32 && begin->str[i] != 0)
			{
				str[i2] = begin->str[i];
				i2++;
				i++;
			}
			begin = begin->next;
			i = 0;
		}
		while (i < 32 && begin->str[i] != 0)
		{
			str[i2] = begin->str[i];
			i2++;
			i++;
		}
	}
	else
	{
		while (i < 32 && begin->str[i] != 0)
		{
			str[i2] = begin->str[i];
			i2++;
			i++;
		}
	}
	str[i2] = '\0';
	return(str);
}

int cpt_index(t_str *begin)
{
	int total;

	total = 0;
	if (!begin)
		begin = add_list(NULL);
	if (begin->next)
	{
		while (begin->next)
		{
			total = total + begin->index;
			begin = begin->next;
		}
		total = total + begin->index;
		return (total);
	}
	else
		while (begin->str[total] != 0)
			total++;
	return (total);
}

t_str *add_list(t_str *begin)
{
	t_str *list;
	int i;

	i = 0;
	list = (t_str *)malloc(sizeof(t_str));
	if (begin)
	{
		while (begin->next)
			begin = begin->next;
		begin->next = list;
	}
	list->next = NULL;
	list->index = 0;
	while (i <= 32)
	{
		list->str[i] = 0;
		i++;
	}
	return (list);
}

t_str *free_list(t_str *begin)
{
	t_str *next;

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
		free(begin);
	}
	else
		free(begin);
	begin = NULL;
	return (begin);
}
