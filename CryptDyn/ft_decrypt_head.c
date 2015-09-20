#include "ft_crypt_dyn.h"

int     ft_check_head(char *input)
{
    int     width;

    width = ft_width(input);
    if (input[0] == (input[width - 1] - 1))
        return (1);
    ft_putstr("Message error;\n");
    ft_putstr("Tapez sur une touche pour fermer le programme...\n");
    ft_getchar();
    system("exit");
    return (0);
}

char    *ft_cut_head(char *input)
{
    char    *t_crypt;
    int     width;
    int     index;

    index = 1;
    width = ft_width(input);
    t_crypt = malloc(sizeof(char) * width - 2);
    while (index <= width - 3)
    {
        t_crypt[index - 1] = input[index];
        index++;
    }
    t_crypt[index - 1] = '\0';
    free(input);
    return (t_crypt);
}


int     ft_get_rot(char *input)
{
    int     start_rot;

    start_rot = input[0];
    if (start_rot < 0)
        start_rot = -start_rot;
    return (start_rot);
}














