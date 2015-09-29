#ifndef _STRUCTS_H
# define _STRUCTS_H

typedef struct	struct_keyboard_status {
	bool	verr_maj;
	bool	verr_num;
	short	shift;
	short	ctrl;
	short	alt_gr;
	bool	mode;
}				keyboard_status;

#endif // _STRUCTS_H