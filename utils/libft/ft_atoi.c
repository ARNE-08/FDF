/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <psaengha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:53:38 by psaengha          #+#    #+#             */
/*   Updated: 2022/08/27 17:07:34 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkneg(const char *str)
{
	int	n;
	int	i;
	int	count;

	n = 1;
	i = 0;
	count = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -1;
		i++;
		count++;
	}
	if (count > 1)
		return (0);
	return (n);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	n;
	int	i;
	int	count;

	i = 0;
	n = checkneg(str);
	result = 0;
	count = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result * n);
}

/*int	main(int argc, char **argv)
{
	argc = 2;
	printf("%d", ft_atoi(argv[1]));
}*/
