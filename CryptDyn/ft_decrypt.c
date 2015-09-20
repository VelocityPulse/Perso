#include "ft_crypt_dyn.h"

void    ft_analys_crypt(char *t_crypt, int start_rot)
{
    char    *decrypt;
    int     width;
    int     index;

    width = ft_width(t_crypt);
    index = 0;
    decrypt = malloc(sizeof(char) * width);
    while (t_crypt[index] != '\0')
    {
        start_rot = ft_convert_head(start_rot);
        decrypt[index] = (t_crypt[index] - start_rot);
        start_rot++;
        index++;
    }
    decrypt[index] = '\0';
    ft_putstr("\n\n");
    ft_putstr(decrypt);
    ft_putstr("\n");
    free(t_crypt);
}

void    ft_decryptage(void)
{
    char    input[10000];
    char    *t_crypt;
    int     start_rot;
    FILE    *fichier;

    fichier = fopen("crypt.cypt", "r");
    if (fichier != NULL)
    {
        fgets(input, 10000, fichier);
        fclose(fichier);
        ft_putstr("Message capte :\n\n");
        ft_putstr(input);
        ft_putstr("\n\nTapez sur entrer pour decrypter\n");
        ft_getchar();
        if (ft_check_head(input))
        {
            start_rot = ft_get_rot(input);
            start_rot = ft_convert_head(start_rot);
            t_crypt = ft_cut_head(input);
            ft_analys_crypt(t_crypt, start_rot);
            ft_getchar();
        }
    }
    else
    {
        ft_putstr("\ncrypt.cypt n'a pas ete trouver dans le repertoir local.\n");
        ft_putstr("Appuyez sur une touche pour fermer le programme...");
        getchar();
        system("exit");
    }
}










