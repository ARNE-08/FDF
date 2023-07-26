/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfdf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:22:35 by psaengha          #+#    #+#             */
/*   Updated: 2023/07/26 22:58:12 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// get height count the number of line in the file
// get weight from number of column in line
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
	line = get_next_line(fd);
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
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
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		if (line != NULL)
			width = word_count(line, ' ');
	}
	close(fd);
	if (width == -1)
	{
		perror("incorrect map argument");
		exit(1);
	}
	return (width);
}

void	fill_matrix(int *z_line, int *c_line, char *line, t_fdf *data)
{
	char		**nums;
	char		**word;
	int			i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		checkmap(nums[i]);
		if (ft_strchr(nums[i], ','))
		{
			word = ft_split(nums[i], ',');
			z_line[i] = ft_atoi(word[0]);
			c_line[i] = ft_atoibase16(word[1]);
			freeall(word);
		}
		else
		{
			z_line[i] = ft_atoi(nums[i]);
			c_line[i] = 0;
		}
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_file(char *file, t_fdf *data)
{
	int		fd;
	int		i;

	data->height = get_height(file);
	data->width = get_width(file);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	data->c_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i <= data->height)
	{
		data->z_matrix[i] = (int *)malloc(sizeof(int) * (data->width + 1));
		data->c_matrix[i] = (int *)malloc(sizeof(int) * (data->width + 1));
		i++;
	}
	fillandfree(file, data);
}
