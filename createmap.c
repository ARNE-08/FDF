/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:54:07 by psaengha          #+#    #+#             */
/*   Updated: 2023/07/23 16:05:06 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// drawmap function draw a down / right line
// to connect two closest point together, except for the point at the border
// 0 -- 0
// |
// 0

void	connectpoint(t_pos x1, t_pos x2, t_fdf *data)
{
	float	x_step;
	float	y_step;
	float	max;

	color(&x1, &x2, data);
	x_step = x2.x - x1.x;
	y_step = x2.y - x1.y;
	if (fmodule(x_step) > fmodule(y_step))
		max = fmodule(x_step);
	else
		max = fmodule(y_step);
	x_step /= max;
	y_step /= max;
	while ((int)(x1.x - x2.x) || (int)(x1.y - x2.y))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x1.x, x1.y, data->color);
		x1.x += x_step;
		x1.y += y_step;
		if (x1.x > WIN_W || x1.y > WIN_H || x1.y < 0 || x1.x < 0)
			break ;
	}
}

void	drawmap_sub(t_pos pos, t_fdf *data, int mode)
{
	t_pos	horizontal;
	t_pos	vertical;

	if (mode == 0)
	{
		horizontal.x = pos.x + 1;
		horizontal.y = pos.y;
		connectpoint(pos, horizontal, data);
	}
	else
	{
		vertical.x = pos.x;
		vertical.y = pos.y + 1;
		connectpoint(pos, vertical, data);
	}
}

void	drawmap(t_fdf *data)
{
	t_pos	pos;
	t_pos	horizontal;
	t_pos	vertical;

	pos.y = 0;
	while (pos.y < data->height)
	{
		pos.x = 0;
		while (pos.x < data->width)
		{
			if (pos.x < data->width - 1)
				drawmap_sub(pos, data, 0);
			if (pos.y < data->height - 1)
				drawmap_sub(pos, data, 1);
			pos.x++;
		}
		pos.y++;
	}
}
