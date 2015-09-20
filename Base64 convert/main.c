#include "head.h"

int main(void)
{
    char c;
    char *str;
    int start;
    int ret;

    ret = 0;
    start = 0;
    c = 0;
    ft_putstr("\
###############################################################################\n\
############################### LOGICIEL EDITE PAR ############################\n\
###############################################################################\n\
#############################-   CLEMENT CHAMEYRAT   -#########################\n\
###############################################################################\n");

    while (start != 1)
    {
        ft_putstr("\n\n\t\t\t     Convertire ou Traduire ? \n\t\t\t\t      C/T\n");
        ret = read(0, &c, 1);
        ft_getchar();
        if (ret != -1)
        {
            if (c == 'C' || c == 'c')
            {
                start = 1;
                str = ft_control_convert();

                ft_putstr(str);
                ft_putchar('\n');
                // ft_write(str);
                free(str);
                ft_putstr("\nTapez sur une touche pour fermer le programme\n");
                getchar();
                system("exit");
            }
            else if (c == 'T' || c == 't')
            {
                start = 1;
   //             ft_translate();
                ft_putstr("\nTapez sur une touche pour fermer le programme\n");
                getchar();
                system("exit");
            }
            else
            {
                ft_putstr("l'entree ne correspond a aucun choix.\n");
            }
        }
        else
        {
            ft_putstr("Input error\nVeuillez Tapez sur une touche pour fermer le programme\n");
            system("exit");
        }
    }
    ft_putstr("\n\n");
    return (0);
}

