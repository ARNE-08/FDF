/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:53:24 by psaengha          #+#    #+#             */
/*   Updated: 2023/07/26 22:36:13 by psaengha         ###   ########.fr       */
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
	line = get_next_line(fd);
	temp = word_count(line, ' ');
	while (line != NULL)
	{
		amount = word_count(line, ' ');
		if (temp != amount)
		{
			perror("Maps test must have amount of value in every line equal.");
			exit(1);
		}
		free(line);
		line = get_next_line(fd);
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
		perror("Invalid argument | ./fdf '.fdf map");
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
	i = 0;
	while (file[i])
	{
		free(file[i]);
		i++;
	}
	free(file);
}

int	main(int ac, char **av)
{
	t_fdf	*data;

	check_error(ac, av);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	read_file(av[1], data);
	data->w = WIN_W;
	data->h = WIN_H;
	data->mlx_ptr = mlx_init();
	if (data->width > WIN_W)
		data->w = data->width;
	if (data->height > WIN_H)
		data->h = data->height;
	get_zoom(av, data);
	createmlx(data);
}
