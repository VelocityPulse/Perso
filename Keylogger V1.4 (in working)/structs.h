#ifndef _STRUCTS_H
# define _STRUCTS_H

# define ENTRY printf("ENTRY ");
# define STATUS printf("%hd, %hd, %hd -", kb_status.ctrl, kb_status.alt_gr, kb_status.shift);
# define KEY_ printf("%hd ", key_value);

typedef struct	struct_keyboard_status {
	bool	verr_maj;
	bool	verr_num;
	short	zone;
	bool	shift;
	bool	ctrl;
	bool	alt_gr;
	
}				keyboard_struct;

#endif // _STRUCTS_H