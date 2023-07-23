/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:36:47 by psaengha          #+#    #+#             */
/*   Updated: 2023/07/23 16:07:58 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	assign_color(char **word, int *z_line, char **nums, t_fdf *data)
{
	int	i;

	i = 0;
	// ! comeback to fix
	while (nums[i])
	{
		if (ft_strchr(nums[i], ','))
		{
			word = ft_split(nums[i], ',');
			z_line[i] = ft_atoi(word[0]);
			data->color = ft_atoibase16(word[1]);
			printf("assign color = %d\n", data->color);
			free(word[0]);
			free(word[1]);
		}
		else
		{
			// data->color = 0;
			z_line[i] = ft_atoi(nums[i]);
			// printf("assign color = %d\n", data->color);
		}
		free(nums[i]);
		i++;
	}
}
