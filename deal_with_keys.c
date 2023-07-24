/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 03:43:16 by psaengha          #+#    #+#             */
/*   Updated: 2023/07/24 16:10:36 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, t_fdf *data)
{
	// ft_printf("%d\n", key);
	if (key == KEY_ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
	// if (key == KEY_UP || key == KEY_W)
	// 	data->shift_y -= 10;
	// if (key == KEY_DOWN || key == KEY_S)
	// 	data->shift_y += 10;
	// if (key == KEY_LEFT || key == KEY_A)
	// 	data->shift_x -= 10;
	// if (key == KEY_RIGHT || key == KEY_D)
	// 	data->shift_x += 10;
	// if (key == KEY_PLUS)
	// 	data->zoom += 1;
	// if (key == KEY_MINUS)
	// 	data->zoom -= 1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	drawmap(data);
	return (key);
}
