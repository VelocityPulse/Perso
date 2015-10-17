#ifndef _STRUCTS_H
# define _STRUCTS_H 

# include <stdio.h>
# include <stdlib.h>

typedef struct struct_str {
	short				index;
	char				str[32];
	struct struct_str	*next;
}				t_str;

t_str	*add_str(t_str *begin, char *str, char c);
t_str	*add_list(t_str *begin);
char	*export_str(t_str *begin);
t_str	*free_list(t_str *begin);
int		cpt_index(t_str *begin);

#endif // _STRUCTS_H