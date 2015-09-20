#include "ft_crypt_dyn.h"

int     ft_password(void)
{
    char    secret[] = "alpha42";
    char    input[40];
    int     i;
    int     cpt;
    int     match;

    i = 0;
    cpt = 0;
    match = 0;
    scanf("%39s", input);
    while (secret[cpt] != '\0')
            cpt++;
    while (i < cpt && input[i] != '\0' && match == 0)
    {
        if (input[i + 1] != secret[i + 1])
                match = 1;
        i++;
    }
    if (match == 0)
    {
        ft_putstr("pass ok\n");
        return (1);
    }
    ft_putstr("pass error\n");
    system("exit");
    return(0);
}
