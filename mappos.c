/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mappos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:24:38 by psaengha          #+#    #+#             */
/*   Updated: 2023/07/26 22:56:05 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_zoom(char **av, t_fdf *data)
{
	if ((ft_strcmp(av[1], "test_maps/42.fdf") != 0)
		&& (ft_strcmp(av[1], "test_maps/pnp_flat.fdf") != 0)
		&& (ft_strcmp(av[1], "test_maps/pyramide.fdf") != 0))
		data->shift_x = WIN_W / 2;
	else if (ft_strcmp(av[1], "test_maps/pyramide.fdf") == 0)
		data->shift_x = 1075;
	else
		data->shift_x = 750;
	data->shift_y = 300;
	if (ft_strcmp(av[1], "test_maps/100-6.fdf") == 0)
		data->shift_y = 200;
	if (data->width >= 500)
		data->zoom = 2;
	else if (data->width > 100)
		data->zoom = 5;
	else if (data->width == 100)
		data->zoom = 12;
	else if (data->width >= 50)
		data->zoom = 20;
	else if (data->width >= 20)
		data->zoom = 40;
	else if (data->width <= 10)
		data->zoom = 65;
	else
		data->zoom = 50;
}

void	checkmap(char *str)
{
	char	**word;

	if (ft_strchr(str, ','))
	{
		word = ft_split(str, ',');
		if (ft_strlen(word[0]) > 10)
		{
			perror("Value in the map exceed MAX/MIN INT");
			exit(1);
		}
		freeall(word);
	}
	else
	{
		if (ft_strlen(str) > 10)
		{
			perror("Value in the map exceed MAX/MIN INT");
			exit(1);
		}
	}
}
