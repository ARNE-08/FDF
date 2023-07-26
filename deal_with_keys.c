/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 03:43:16 by psaengha          #+#    #+#             */
/*   Updated: 2023/07/26 22:56:56 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	freefdf(t_fdf *data)
{
	int	i;

	i = 0;
	while (data->z_matrix[i] && data->c_matrix[i])
	{
		free(data->z_matrix[i]);
		free(data->c_matrix[i]);
		i++;
	}
	free(data->z_matrix);
	free(data->c_matrix);
	free(data);
}

int	close_button_event(int keycode, t_fdf *data)
{
	exit(0);
}

int	deal_key(int key, t_fdf *data)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		freefdf(data);
		exit(0);
	}
	return (key);
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
