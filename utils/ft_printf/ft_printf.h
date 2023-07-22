/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:52:00 by psaengha          #+#    #+#             */
/*   Updated: 2022/11/05 14:30:11 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# include <stdio.h>

int	ft_printf(const char *str, ...);
int	c(int c);
int	string(char *str);
int	nbr(int n);
int	u(unsigned int n);
int	lower(unsigned int n);
int	upper(unsigned int n);
int	p(unsigned long n);

#endif
