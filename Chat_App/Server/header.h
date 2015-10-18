#include <stdio.h>
#include <winsock2.h>
#include <io.h>

#include "list.h"

DWORD WINAPI f_receive(void*);
DWORD WINAPI f_send(void*);