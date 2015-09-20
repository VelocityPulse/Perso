#ifndef HEAD_H
# define HEAD_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

void    ft_putchar(char c);
void    ft_putstr(char *str);
void    ft_putnbr(int n);
char    *ft_strcmp(char *src, char *dest);
void    ft_getchar(void);
char    *ft_control_convert(void);
char    *ft_convert(char *chain);
int     ft_checkchain(char *chain);
int     ft_define_size(int n);
int     ft_width(char *str);
char    *ft_getchain(void);
char    ft_unit64(char *chain, int i);
int     ft_ibin(char *chain, int i);
//void    ft_translate(void);
//void    ft_write(char *str);


#endif // HEAD_H
