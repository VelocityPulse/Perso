/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 18:50:41 by                   #+#    #+#             */
/*   Updated: 2016/01/04 16:33:59 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

int		*ft_color_w(int code, t_env *x, int multiplicator)
{
	t_pt	pt;
	int		mode;
	int		save;

	save = multiplicator;
	pt.y = 0;
	mode = 0;
	while (pt.y < x->height)
	{
		pt.x = 0;
		multiplicator = save;
		while (multiplicator-- > 0)
			code = next_rainbow(code, &mode);
		while (pt.x < x->width)
		{
			ft_draw_pixel(x, code, pt);
			pt.x++;
		}
		pt.y++;
	}
	mlx_put_image_to_window(x->mlx, x->win, x->mlx_img->img, 0, 0);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	int static multiplicator = 3;
	int static previous = (int)0xff0000;

	if (keycode == 53) // echap
		exit(0);
	else if (keycode == 78 || keycode == 27)
		multiplicator--;
	else if (keycode == 69 || keycode == 24)
		multiplicator++;
	else
	{
		if (keycode == 12) // Q
			keycode = (int)0xff0000;
		else if (keycode == 13) // W
			keycode = (int)0x00ff00;
		else if (keycode == 14) // E
			keycode = (int)0x0000ff;
		else
			keycode = (int)0xffffff;
		previous = keycode;
	}
	if (multiplicator == 0)
		multiplicator = 1;
	ft_color_w(previous, e, multiplicator);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	*x;

	ft_putstr("USING :\tQ for start on red\n\tW for start on green\
\n\tE for start on blue\n\t+ for mulitiplicate rainbow\n\t- for soustrate \
rainbow\n\tEchap for quit\n");

	x = (t_env *)ft_memalloc(sizeof(t_env));
	x->height = 600;
	x->width = 400;
	x->mlx = mlx_init();
	x->win = mlx_new_window(x->mlx, x->width, x->height, "test1");
	ft_new_image(x);
	mlx_key_hook(x->win, key_hook, x);
	mlx_loop(x->mlx);
	return (0);
}
