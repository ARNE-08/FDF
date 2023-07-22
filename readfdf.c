/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readFDF.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:22:35 by psaengha          #+#    #+#             */
/*   Updated: 2023/07/23 00:16:07 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// get height count the number of line in the file
// get weight from number of column in line
// int	word_count(char *line, char c)
// {
// 	char	**split;
// 	int		i;

// 	split = ft_split(line, ' ');
// 	i = 0;
// 	while (split[i])
// 	{
// 		free(split[i]);
// 		i++;
// 	}
// 	free(split);
// 	return (i);
// }
// use a new get_next_line function that also receive line as parameter
// return the result to line
int	word_count(char *str, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i] != 10 && str[i])
			words++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (words);
}

int	get_height(char *file)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int	get_width(char	*file)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY, 0);
	get_next_line(fd, &line);
	width = word_count(line, ' ');
	free(line);
	close(fd);
	if (width == -1)
	{
		perror("incorrect map argument");
		exit(1);
	}
	return (width);
}

void	fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_file(char *file, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	data->height = get_height(file);
	data->width = get_width(file);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i <= data->height)
		data->z_matrix[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
	fd = open(file, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	close(fd);
	data->z_matrix[i] = NULL;
}
