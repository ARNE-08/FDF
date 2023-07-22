/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 13:29:17 by psaengha          #+#    #+#             */
/*   Updated: 2023/07/18 12:43:30 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# include <sys/types.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

// char	*get_next_line(int fd);
char	*get_next_line(int fd, char **res);
size_t	ft_strlenmode(const char *s, int mode);
char	*ft_strjoinfree(char *s1, char *s2);
char	*read_line(int fd, char *str, char *buffer);
char	*ft_strchrget(char *s, int c);
char	*ft_dupnl(char *str);
char	*cut_line(char	*str);
char	*ft_strsubjoin(char *str, char *s1, char *s2);

#endif
