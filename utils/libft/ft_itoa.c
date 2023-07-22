/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 10:13:51 by psaengha          #+#    #+#             */
/*   Updated: 2022/09/23 20:26:34 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n / 10 > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	divide(int len)
{
	int	digit;

	digit = 1;
	while (len > 1)
	{
		digit *= 10;
		len--;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	long	num;
	int		len;
	int		use;
	int		i;
	char	*re;

	i = 0;
	num = n;
	len = numlen(num);
	use = len;
	re = malloc(sizeof(char) * len + 1);
	if (!re)
		return (0);
	if (num < 0)
	{
		re[i++] = '-';
		num *= -1;
		len--;
	}
	while (i < use)
		re[i++] = ((num / divide(len--)) % 10) + 48;
	re[use] = '\0';
	return (re);
}

/*len count "-" as len beacause when we turn it to
char [0] will be '-' and we still need more digit to fit the int
so in ito we minus the len when n < 0
in while loop divide len use to turn len in to 10, 100, etc
if we want to get two from 123 it will be 123 / 10 = 12
so we mod 10 for the 2*/
