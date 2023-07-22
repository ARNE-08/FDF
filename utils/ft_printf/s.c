/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:19:27 by psaengha          #+#    #+#             */
/*   Updated: 2022/11/05 14:58:39 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	string(char *str)
{
	int	len;

	len = 0;
	if (!str)
	{
		string("(null)");
		return (6);
	}
	while (*str)
	{
		c(*str);
		len++;
		str++;
	}
	return (len);
}

/*int	main(void)
{
	printf(" NULL %s NULL \n", NULL);
	string(NULL);
}*/
