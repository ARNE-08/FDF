/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoibase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 04:41:12 by psaengha          #+#    #+#             */
/*   Updated: 2023/07/23 14:44:40 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	powerof16(int i)
{
	int	ans;

	ans = 1;
	while (i > 0)
	{
		ans *= 16;
		i--;
	}
	return (ans);
}

int	ft_atoibase16(char *str)
{
	int	i;
	int	ans;
	int	power;

	power = ft_strlen(str);
	i = 0;
	if (str[i] == '0')
		i++;
	if (str[i] == 'x')
		i++;
	power = power - i - 1;
	ans = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 70)
			ans += (str[i] - 55) * powerof16(power);
		else if (str[i] >= 97 && str[i] <= 102)
			ans += (str[i] - 87) * powerof16(power);
		else if (str[i] >= 48 && str[i] <= 57)
			ans += (str[i] - 48) * powerof16(power);
		power--;
		i++;
	}
	return (ans);
}
