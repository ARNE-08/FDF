/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:21:34 by psaengha          #+#    #+#             */
/*   Updated: 2022/11/05 14:28:36 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check(va_list args, const char *str)
{
	if (*str == 'c')
		return (c(va_arg(args, int)));
	else if (*str == 's')
		return (string(va_arg(args, char *)));
	else if (*str == 'p')
		return (p(va_arg(args, unsigned long)));
	else if (*str == 'd' || *str == 'i')
		return (nbr(va_arg(args, int)));
	else if (*str == 'u')
		return (u(va_arg(args, unsigned int)));
	else if (*str == 'x')
		return (lower(va_arg(args, unsigned int)));
	else if (*str == 'X')
		return (upper(va_arg(args, unsigned int)));
	else if (*str == '%')
		return (c('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	va_start(args, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			len += check(args, str + 1);
			str++;
		}
		else
		{
			len++;
			c(*str);
		}
		str++;
	}
	va_end(args);
	return (len);
}
