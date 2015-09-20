#include "head.h"

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
}

void    ft_putnbr(int n)
{
    if (n < 0)
    {
        ft_putchar('-');
        ft_putnbr(-n);
    }
    if (n > 10)
    {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
    else
        ft_putchar(n + 48);
}


char    *ft_strcmp(char *src, char *dest)
{
    int i;

    i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}



void    ft_getchar(void)
{
    while (getchar() != '\n');
}

int     ft_width(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}














