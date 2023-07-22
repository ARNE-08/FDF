/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xupper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:18:38 by psaengha          #+#    #+#             */
/*   Updated: 2022/11/05 15:05:22 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	numlen(unsigned int n)
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

int	upper(unsigned int n)
{
	int	len;

	len = numlen(n);
	if (n < 10)
		c(n + 48);
	else if (n < 16)
		c(n + 55);
	else if (n >= 16)
	{
		upper(n / 16);
		upper(n % 16);
	}
	return (len);
}
