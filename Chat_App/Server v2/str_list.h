#ifndef STR_LIST_H
# define STR_LIST_H 

# include <stdio.h>
# include <stdlib.h>

# define ENTRY printf("ENTRY ");
# define ENTRY2 printf("ENTRY2 ");
# define STATUS printf("%hd, %hd, %hd -", kb_status.ctrl, kb_status.alt_gr, kb_status.shift);
# define KEY_ printf("%hd ", key_value);
# define LINE printf(" %d ", __LINE__);

typedef struct struct_str {
	short				index;
	char				str[32];
	struct struct_str	*next;
}				t_str;

t_str	*add_str(t_str *begin, char *str, char c);
char	*export_str(t_str *begin);
int		str_cpt_index(t_str *begin);
t_str	*add_str_list(t_str *begin);
t_str	*free_str_list(t_str *begin);


#endif // STR_LIST_H