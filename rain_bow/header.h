/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:21:24 by                   #+#    #+#             */
/*   Updated: 2016/01/04 16:24:37 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HEADER_H
# define _HEADER_H

# include "mlx.h"
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

# define YOLO ft_putstr("YOLO\n");
# define YOLO1 ft_putstr("\nYOLO1-\n");
# define YOLO2 ft_putstr("\nYOLO2--\n");

# define red 0xff0000
# define green 0x00ff00
# define blue 0x0000ff

# define blueadd 0x000001
# define redadd 0x010000
# define greenadd 0x000100

# define goblue 1
# define gored 2
# define gogreen 3

# define backblue 4
# define backred 5
# define backgreen 6

typedef struct	s_pt
{
	int		x;
	int		y;
}				t_pt;

typedef struct	s_img
{
	char	*data;
	void	*img;
	int		width;
	int		bpp;
	int		endian;
	int		max_size;
}				t_img;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	t_img	*mlx_img;
}				t_env;

int		add_green(int color, int *mode);
int		add_blue(int color, int *mode);
int		add_red(int color, int *mode);
int		back_green(int color, int *mode);
int		back_blue(int color, int *mode);
int		back_red(int color, int *mode);
int		next_rainbow(int color, int *mode);
int		*ft_color_w(int code, t_env *e, int multiplicator);

void	ft_new_image(t_env *x);
void	ft_draw_pixel(t_env *x, int color, t_pt pt);

#endif
