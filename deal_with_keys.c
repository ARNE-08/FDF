/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 03:43:16 by psaengha          #+#    #+#             */
/*   Updated: 2023/07/25 13:22:49 by psaengha         ###   ########.fr       */
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
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	drawmap(data);
	return (key);
}

int	close_button_event(int keycode, t_fdf *data)
{
	exit(0);
	// mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

void	createmlx(t_fdf *data)
{
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->w, data->h);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->w, data->h, "FDF");
	drawmap(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_hook(data->win_ptr, 17, 0, close_button_event, data);
	mlx_loop(data->mlx_ptr);
}
