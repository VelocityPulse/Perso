#include "ft_crypt_dyn.h"

void            ft_getchar(void)
{
    while (getchar() != '\n')
        ;
}

unsigned long    ft_secure_rot(unsigned long start_rot)
{
    if (start_rot == 0)
    {
        ft_putstr("Etes vous sur de selectionner 0 ?\n");
        ft_putstr("Veuillez comfirmer votre choix\n");
        scanf("%ld", &start_rot);
        ft_getchar();
        return (start_rot);
    }
    else
        return (start_rot);
}

int             ft_width(char *str)
{
    int cpt;

    cpt = 0;
    while (str[cpt])
        cpt++;
    return (cpt);
}
