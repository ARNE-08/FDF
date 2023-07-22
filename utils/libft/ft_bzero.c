/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <psaengha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 23:25:22 by psaengha          #+#    #+#             */
/*   Updated: 2022/08/26 23:25:24 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ch;
	unsigned long	i;

	i = 0;
	ch = (unsigned char *)s;
	while (i < n)
	{
		ch[i] = 0;
		i++;
	}
	s = ch;
}
