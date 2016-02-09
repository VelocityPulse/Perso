#ifndef _STRUCTS_H
# define _STRUCTS_H

# define ENTRY printf(" ENTRY ");
# define ENTRY2 printf(" ENTRY2 ");
# define STATUS printf("%hd, %hd, %hd -", kb_status.ctrl, kb_status.alt_gr, kb_status.shift);
# define KEY_ printf("%hd ", key_value);
# define LINE printf(" %d ", __LINE__);

typedef struct	struct_keyboard_status {
	bool	verr_maj;
	bool	verr_num;
	short	zone;
	bool	shift;
	bool	ctrl;
	bool	alt_gr;
	
}				keyboard_struct;

typedef struct struct_str {
	short				index;
	char				str[32];
	struct struct_str	*next;
}				t_str;

t_str	*add_str(t_str *begin, char *str, char c);
t_str	*add_list(t_str *begin);
t_str	*print_file_str(t_str *begin);
char	*export_str(t_str *begin);
t_str	*free_list(t_str *begin);
int		cpt_index(t_str *begin);

#endif // _STRUCTS_H