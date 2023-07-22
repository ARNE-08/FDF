/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:53:24 by psaengha          #+#    #+#             */
/*   Updated: 2023/07/23 02:06:17 by psaengha         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_fdf	*data;
	t_pos	x1;
	t_pos	x2;

	x1.x = 10;
	x1.y = 10;
	x2.x = 600;
	x2.y = 300;
	check_error(ac, av);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	read_file(av[1], data);
	data->zoom = 25;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, "FDF");
	drawmap(data);
	// bonus
	// mlx_key_hook(data->win_ptr, deal_key, NULL);
	// to keep the window open
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
