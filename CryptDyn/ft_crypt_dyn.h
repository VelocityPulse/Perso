#ifndef FT_CRYPT_DYN_H
# define FT_CRYPT_DYN_H

# define LINE printf("%d\n", __LINE__);
# define PAUSE ft_getchar();
# define SAUT ft_putchar('\n');

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>


void            ft_putchar(char c);
void            ft_putstr(char *str);
void            ft_putun_nbr(unsigned long n);
void            ft_putnbr(int n);
char            *ft_strcpy(char *src, char *dest);
void            ft_getchar(void);
unsigned long   ft_secure_rot(unsigned long rot);
char            *ft_capture_text(void);
int             ft_width(char *str);
int             ft_password(void);
void            ft_cryptage(void);
char            *ft_rot_dyn(char *input, unsigned long start_rot);
unsigned long   ft_convert_head_u(unsigned long start_rot);
int             ft_convert_head(int start_rot);
char            *ft_crypt_head(char *text, unsigned long start_rot);
char            *ft_place_head(char *src, char header);
void            ft_decryptage(void);
void            ft_analys_crypt(char *t_crypt, int start_rot);
int             ft_check_head(char *input);
char            *ft_cut_head(char *input);
int             ft_get_rot(char *input);
void            ft_write(char *t_crypt);

#endif // FT_CRYPT_DYN_H
