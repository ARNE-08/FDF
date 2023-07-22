/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:49:40 by psaengha          #+#    #+#             */
/*   Updated: 2022/11/05 14:33:48 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	numlen(unsigned int n)
{
	int	len;

	len = 1;
	while (n / 10 != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	u(unsigned int n)
{
	int	len;

	len = numlen(n);
	if (n < 10)
		c(n + '0');
	else if (n >= 10)
	{
		u(n / 10);
		u(n % 10);
	}
	return (len);
}
