#include "ft_crypt_dyn.h"

void    ft_write(char *t_crypt)
{
    char    standard_input;
    FILE    *fichier;

    ft_putstr("Tapez sur entrez pour sauvegarder le contenu dans un fichier texte\n");
    standard_input = getchar();
    if (standard_input == '\n')
    {
        fichier = fopen("crypt.cypt", "w+");
        if (fichier != NULL)
        {
            fprintf(fichier, "%s", t_crypt);
            fclose(fichier);
            ft_putchar('\n');
            ft_putstr(t_crypt);
            ft_putstr("\nwrite ok");
        }
        else
            ft_putstr("open error\n");
    }
    else
        ft_putstr("entree non validee\n");
    free(t_crypt);
}
