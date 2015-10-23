#include "header.h"

bool f_exit_client(char *text)
{
	char    secret[] = "EXIT PROGRAM";
	int     i;
	int     cpt;
	int     match;

	i = 0;
	cpt = 0;
	match = 0;
	while (secret[cpt] != '\0')
		cpt++;
	while (i < cpt && text[i] != '\0' && match == 0)
	{
		if (text[i + 1] != secret[i + 1])
			match = 1;
		i++;
	}
	if (match == 0)
		return (1);
	return(0);
}