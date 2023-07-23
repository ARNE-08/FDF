/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:53:24 by psaengha          #+#    #+#             */
/*   Updated: 2023/07/23 17:01:32 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// include header and initialize to use mlx function with mlx_init()
void	check_amount(char *file)
{
	char	*line;
	int		temp;
	int		amount;
	int		fd;

	fd = open(file, O_RDONLY, 0);
	get_next_line(fd, &line);
	temp = word_count(line, ' ');
	while (get_next_line(fd, &line))
	{
		amount = word_count(line, ' ');
		if (temp != amount)
		{
			perror("Maps test must have amount of value in every line equal.");
			exit(1);
		}
	}
}

void	check_error2(int fd)
{
	if (fd == -1)
	{
		perror("File does not exist.");
		exit(1);
	}
	else
	{
		perror("Argument have to be '.fdf' extension file.");
		exit(1);
	}
}

void	check_error(int ac, char **av)
{
	char	**file;
	int		i;
	int		fd;

	if (ac != 2)
	{
		perror("Invalid argument");
		exit(1);
	}
	fd = open(av[1], O_RDONLY, 0);
	file = ft_split(av[1], '.');
	i = 0;
	while (file[i])
		i++;
	if (fd < 0 || ft_strcmp(file[i - 1], "fdf") != 0)
		check_error2(fd);
	else
		check_amount(av[1]);
}

int	close_button_event(int keycode, t_fdf *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	// mlx_loop_end(data->mlx_ptr);
	return (0);
}

// ! pentenegpos is acting weird
// ! should read or not read pylone?
int	main(int ac, char **av)
{
	t_fdf	*data;

	check_error(ac, av);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	read_file(av[1], data);
	// ! what should be the value for zoom
	data->zoom = 50;
	data->w = WIN_W;
	data->h = WIN_H;
	data->mlx_ptr = mlx_init();
	if (data->width > WIN_W)
		data->w = data->width;
	if (data->height > WIN_H)
		data->h = data->height;
	data->shift_x = data->w / 3;
	data->shift_y = data->h / 3;
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->w, data->h, "FDF");
	drawmap(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	// ! abort when trying to close with 'x' button
	mlx_hook(data->win_ptr, 17, 0, close_button_event, data);
	mlx_loop(data->mlx_ptr);
}

//main for readfile
// int		i;
// int		j;
// i = 0;
// while (i < data->height)
// {
// 	j = 0;
// 	while (j < data->width)
// 	{
// 		ft_printf("%d ", data->z_matrix[i][j]);
// 		j++;
// 	}
// 	ft_printf("\n");
// 	i++;
// }

//main for connecting a dot and draw a line
// t_pos	x1;
// t_pos	x2;
// x1.x = 10;
// x1.y = 10;
// x2.x = 600;
// x2.y = 300;
// data->mlx_ptr = mlx_init();
// data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, "FDF");
// connectpoint(x1, x2, data);
// // to keep the window open
// mlx_loop(data->mlx_ptr);
