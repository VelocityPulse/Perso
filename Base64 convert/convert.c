#include "head.h"

char    *ft_getchain(void)
{
    int ret;
    char buff[5000];
    char *chain;

    while(ret != -1)
    {
        ft_putstr("Tapez votre code binaire\n");
        ret = read(0, &buff, 5000);
        if (ret != -1)
        {
            buff[ret] = '\0';
            chain = malloc(sizeof(char) * ret);
            chain = ft_strcmp(buff, chain);
            return (chain);
        }
        else
            ft_putstr("Read Error;\n\n");
    }
}




int     ft_checkchain(char *chain)
{
    int i;

    i = 0;
    while (chain[i + 1] != '\0')
    {
        if (chain[i] < '0' || chain[i] > '1')
            return (1);
        i++;
    }
    if (i == 0)
        return (1);
    return (0);
}




int     ft_define_size(int n)
{
    int size;

    size = 1;
    if (n > 6)
        size += ft_define_size(n - 6);
    return (size);
}





int     ft_ibin(char *chain, int i)
{
    int bit;
    int power;
    int value;
    int n;

    n = 0;
    bit = 1;
    power = 0;
    value = 0;
    while (chain[i + bit] != '\0' && bit <= 6)
    {
        bit++;
        power++;
    }
    while (power)
    {
        if (value == 0)
            value = 1;
        else
            value *= 2;
        power--;
    }
    bit = 0;
    while (chain[i + bit] != '\0' && bit <= 6)
    {
        if (chain [i + bit] == '1')
            n += value;
        value /= 2;
        bit++;
    }
    return (n);
}






char    ft_unit64(char *chain, int i)
{
    int n;

    n = ft_ibin(chain, i);
    if (n == 62)
        return (43);
    else if (n == 63)
        return (47);
    else if (n >= 0 && n <= 25) // majuscule
        return(n + 65);
    else if (n >= 26 && n <= 51) // minuscule
        return ((n - 26) + 97);
    else if (n >= 52 && n <= 61) // chiffres
        return ((n - 52) + 48);
}

char    *ft_convert(char *chain)
{
    char    *convert;
    int     i;
    int     cpt;
    int     size;

    size = ft_define_size(ft_width(chain) - 1);
    cpt = 0;
    i = 0;
    convert = malloc(sizeof(char) * size);
    while (cpt < size)
    {
        convert[cpt] = ft_unit64(chain, i);
        i += 6;
        cpt++;
    }
    ft_putstr("\n");
    convert[cpt] = '\0';
    return (convert);
}




char    *ft_control_convert(void)
{
    char *chain;

    chain = ft_getchain();
    if (ft_checkchain(chain))
    {
        ft_putstr("Votre chaine binaire contient un parasite.\n");
        chain = ft_control_convert();
    }
    else
        chain = ft_convert(chain);
    return (chain);
}
