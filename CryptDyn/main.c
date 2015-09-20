#include "ft_crypt_dyn.h"

int      main(void)
{
    char    mode[1];
    if (ft_password())
    {
            ft_putstr("\
###############################################################################\n\
############################### LOGICIEL EDITE PAR ############################\n\
###############################################################################\n\
#############################-   CLEMENT CHAMEYRAT   -#########################\n\
###############################################################################\n");

        ft_putstr("\nCrypter ou Decrypter ? C/D\n");
        scanf("%1s", mode);
        ft_getchar();
        if (mode[0] == 'C' || mode[0] == 'c')
            ft_cryptage();
        else if (mode[0] == 'D' || mode[0] == 'd')
            ft_decryptage();
        else
            ft_putstr("desole !\n");
    }
    return 0;
}
