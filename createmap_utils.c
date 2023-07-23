/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createmap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 01:54:18 by psaengha          #+#    #+#             */
/*   Updated: 2023/07/23 16:05:04 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(t_pos *x1, t_fdf *data)
{
	x1->x *= data->zoom;
	x1->y *= data->zoom;
	x1->z *= 1;
}

void	isometric(t_pos *x1, t_fdf *data)
{
	x1->x = (x1->x - x1->y) * cos(ANGLE);
	x1->y = (x1->x + x1->y) * sin(ANGLE) - x1->z;
	x1->x += data->shift_x;
	x1->y += data->shift_y;
}

void	color(t_pos *x1, t_pos *x2, t_fdf *data)
{
	x1->z = data->z_matrix[(int)x1->y][(int)x1->x];
	x2->z = data->z_matrix[(int)x2->y][(int)x2->x];
	if (x1->z || x2->z)
		data->color = AQUA;
	else
		data->color = WHITE;
	zoom(x1, data);
	zoom(x2, data);
	isometric(x1, data);
	isometric(x2, data);
}

float	fmodule(float i)
{
	if (i < 0)
		i *= -1;
	return (i);
}
