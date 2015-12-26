/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 18:50:41 by                   #+#    #+#             */
/*   Updated: 2015/12/26 18:40:26 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

#define red 0xff0000
#define green 0x00ff00
#define blue 0x0000ff

#define blueadd 0x000001
#define redadd 0x010000
#define greenadd 0x000100

#define goblue 1
#define gored 2
#define gogreen 3

#define backblue 4
#define backred 5
#define backgreen 6

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	int		height;
	int		width;
}				t_env;

int		add_green(int color, int *mode)
{
	if (color < red + green)
	{
		*mode = gogreen;
		return (color + greenadd);
	}
	*mode = backred;
	return (color);
}

int		add_blue(int color, int *mode)
{
	if (color < green + blue)
	{
		*mode = goblue;
		return (color + blueadd);
	}
	*mode = backgreen;
	return (color);
}

int		add_red(int color, int *mode)
{
	if (color < blue + red)
	{
		*mode = gored;
		return (color + redadd);
	}
	*mode = backblue;
	return (color);
}
// ------- back

int		back_green(int color, int *mode)
{
	if (color > blue)
	{
		*mode = backgreen;
		return (color - greenadd);
	}
	*mode = gored;
	return (color);
}

int		back_blue(int color, int *mode)
{
	if (color > red)
	{
		*mode = backblue;
		return (color - blueadd);
	}
	*mode = gogreen;
	return (color);
}

int		back_red(int color, int *mode)
{
	if (color > green)
	{
		*mode = backred;
		return (color - redadd);
	}
	*mode = goblue;
	return (color);
}

int		next_rainbow(int color, int *mode)
{
	if (*mode == 0)
	{
		if (color == red)
			return (add_green(color, mode));
		else if (color == green)
			return (add_blue(color, mode));
		else if (color == blue)
			return (add_red(color, mode));
		else return (color);
	}
	else if (*mode == gored)
		return (add_red(color, mode));
	else if (*mode == gogreen)
		return (add_green(color, mode));
	else if (*mode == goblue)
		return (add_blue(color, mode));
	else if (*mode == backred)
		return (back_red(color, mode));
	else if (*mode == backgreen)
		return (back_green(color, mode));
	else if (*mode == backblue)
		return (back_blue(color, mode));
	return (color);
}

int		*ft_color_w(int code, t_env *e)
{
	int		x;
	int		y;
	int mode;

	y = 0;
	mode = 0;
	if (code == 53) // echap
		exit(0);
	else if (code == 12) // Q
		code = (int)0xff0000;
	else if (code == 13) // W
		code = (int)0x00ff00; 
	else if (code == 14) // E
		code = (int)0x0000ff;
	else
		code = (int)0xffffff;
	while (y < e->height)
	{
		x = 0;
		code = next_rainbow(code, &mode);
		code = next_rainbow(code, &mode);
		code = next_rainbow(code, &mode);
		while (x < e->width)
		{
			mlx_pixel_put(e->mlx, e->win, x, y, code);
			x++;
		}
		y++;
	}
	ft_putnbr(code); ft_putchar('\n');
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	ft_color_w(keycode, e);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	e;

	e.height = 600;
	e.width = 400;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, e.width, e.height, "test1");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
