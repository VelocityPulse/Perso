/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:20:40 by                   #+#    #+#             */
/*   Updated: 2016/01/04 17:34:09 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_new_image(t_env *x)
{
	t_img	*img;

	img = NULL;
	if (!(img = (t_img *)ft_memalloc(sizeof(t_img))))
		return ;
	img->endian = 0;
	img->width = x->width;
	img->img = mlx_new_image(x->mlx, x->width, x->height);
	if (img->img)
	{
		img->data = mlx_get_data_addr(img->img, &img->bpp, &img->width,
					&img->endian);
		x->mlx_img = img;
		x->mlx_img->max_size = (img->bpp / 8) * x->width * x->height;
	}
}

void	ft_draw_pixel(t_env *x, int color, t_pt pt)
{
	int		octet;
	int		position;

	octet = x->mlx_img->bpp / 8;
	position = (pt.y * x->mlx_img->width) + (pt.x * octet);
	if (ft_memcmp(x->mlx_img->data + position, &color, (unsigned)octet))
		ft_memcpy(x->mlx_img->data + position, &color, (unsigned)octet);
}
