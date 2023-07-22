/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:12:14 by psaengha          #+#    #+#             */
/*   Updated: 2022/11/05 15:05:02 by psaengha         ###   ########.fr       */
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

int	lower(unsigned int n)
{
	int	len;

	len = numlen(n);
	if (n < 10)
		c(n + 48);
	else if (n < 16)
		c(n + 87);
	else if (n >= 16)
	{
		lower(n / 16);
		lower(n % 16);
	}
	return (len);
}

/*int	main(void)
{
	printf("%x\n", 99);
	lower(99);
	printf("\n%d", numlen(99));
}*/
