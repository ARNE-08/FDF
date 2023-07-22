/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:31:38 by psaengha          #+#    #+#             */
/*   Updated: 2022/11/05 14:33:35 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	numlen(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n / 10 != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	nbr(int n)
{
	int		len;

	len = numlen(n);
	if (n == -2147483648)
	{
		c('-');
		nbr(214748364);
		c('8');
	}
	else if (n < 0)
	{
		c('-');
		nbr(n * -1);
	}
	else if (n < 10)
		c(n + '0');
	else if (n >= 10)
	{
		nbr(n / 10);
		nbr(n % 10);
	}
	return (len);
}
