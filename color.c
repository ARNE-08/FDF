/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:36:47 by psaengha          #+#    #+#             */
/*   Updated: 2023/07/26 22:21:25 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fillandfree(char *file, t_fdf *data)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY, 0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		fill_matrix(data->z_matrix[i], data->c_matrix[i], line, data);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}

void	freeall(char **word)
{
	free(word[0]);
	free(word[1]);
	free(word);
}

int	maxz(t_fdf *data)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	max = data->z_matrix[0][0];
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->z_matrix[i][j] > max)
				max = data->z_matrix[i][j];
			j++;
		}
		i++;
	}
	return (max);
}
