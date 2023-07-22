/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:04:37 by psaengha          #+#    #+#             */
/*   Updated: 2022/11/05 15:13:11 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	numlen(unsigned long n)
{
	int	len;

	len = 1;
	while (n / 16 != 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

static void	print(unsigned long n)
{
	if (n < 10)
		c(n + 48);
	else if (n < 16)
		c(n + 87);
	else if (n >= 16)
	{
		print(n / 16);
		print(n % 16);
	}
}

int	p(unsigned long n)
{
	int	len;

	len = numlen(n);
	string("0x");
	print(n);
	return (len + 2);
}
