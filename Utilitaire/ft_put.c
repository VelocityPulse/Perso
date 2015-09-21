void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
}

void    ft_putnbr(int n)
{
    if (n < 0)
        ft_putchar('-');
    if (n > 10)
    {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
    else
        ft_putchar(n + 48);
}

void    ft_putnbr_un(unsigned long n)
{
    if (n > 10)
    {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
    else
        ft_putchar(n + 48);
}


char    *ft_strcpy(char *src, char *dest)
{
    int i;

    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}




