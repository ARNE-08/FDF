/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:36:47 by psaengha          #+#    #+#             */
/*   Updated: 2023/07/23 16:59:07 by psaengha         ###   ########.fr       */
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
	while (get_next_line(fd, &line))
	{
		fill_matrix(data->z_matrix[i], data->c_matrix[i], line, data);
		free(line);
		i++;
	}
	close(fd);
}

void	freeall(char **word)
{
	free(word[0]);
	free(word[1]);
}
