#include "ft_crypt_dyn.h"

unsigned long    ft_convert_head_u(unsigned long start_rot)
{
    if (start_rot == 0)
        start_rot = ft_convert_head_u(1);
    if (start_rot < 33)
        start_rot = ft_convert_head_u(start_rot * 2);
    if (start_rot > 100)
        start_rot = ft_convert_head_u(start_rot / 2);
    return (start_rot);
}

int             ft_convert_head(int start_rot)
{
    if (start_rot == 0)
        start_rot = ft_convert_head(1);
    if (start_rot < 33)
        start_rot = ft_convert_head(start_rot * 2);
    if (start_rot > 100)
        start_rot = ft_convert_head(start_rot / 2);
    return (start_rot);
}

char    *ft_place_head(char *src, char header)
{
    int     width;
    int     index;
    char    *n_text;

    index = 0;
    width = ft_width(src);
    n_text = malloc(sizeof(char) * width + 2);
    n_text[0] = header;
    while (src[index])
    {
        n_text[index + 1] = src[index];
        index++;
    }
    index++;
    n_text[index] = header + 1;
    n_text[index + 1] = '\0';
    free(src);
    return (n_text);
}

char    *ft_crypt_head(char *text, unsigned long start_rot)
{
    char    header;
    char    *n_text;

    header = ft_convert_head_u(start_rot);
    SAUT
    ft_putnbr(header);
    SAUT

    n_text = ft_place_head(text, header);
    return (n_text);
}
