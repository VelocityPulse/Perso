#include "ft_crypt_dyn.h"

char    *ft_rot_dyn(char *input, unsigned long start_rot)
{
    int     index;
    int     width;
    char    *t_crypt;

    index = 0;
    width = ft_width(input);
    t_crypt = malloc(sizeof(char) * width + 2);
    while (input[index] != '\0')
    {
        start_rot = ft_convert_head(start_rot);
        t_crypt[index] = (input[index] + start_rot);
        start_rot++;
        index++;
    }
    t_crypt[index] = '\0';
    return (t_crypt);
}

void    ft_cryptage(void)
{
    unsigned long    start_rot;
    char            input[10000];
    char            *t_crypt;

    start_rot = 0;
    ft_putstr("Veuillez entrer un chiffre\n");
    scanf("%ld", &start_rot);
    ft_getchar();
    start_rot = ft_secure_rot(start_rot);
    ft_putstr("Veuillez taper votre texte\n");
    fgets(input, 10000, stdin);
    t_crypt = ft_rot_dyn(input, start_rot);
    t_crypt = ft_crypt_head(t_crypt, start_rot);
    ft_putstr(t_crypt);
    ft_putchar('\n');
    ft_write(t_crypt);
    ft_getchar();
}

