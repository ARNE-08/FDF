/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:53:44 by psaengha          #+#    #+#             */
/*   Updated: 2023/07/24 22:25:45 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "utils/ft_printf/ft_printf.h"
# include "utils/get_next_line/get_next_line.h"
# include "utils/libft/libft.h"
# include "minilibx_macos/mlx.h"

# define WIN_H 1080
# define WIN_W 1920
# define ANGLE 0.7
# define SHIFT 10
# define ZOOM_SHIFT 0.25
# define ROT_SHIFT 0.01
# define WHITE 0xFFFFFF
# define CARROT 0xFFA500
# define YELLOW 0xFFFF00
# define CREAM 0xF9F1CC
# define GRASS 0x00FF00
# define AQUA 0x00FFFF
# define RED 0xFF0000
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8
# define KEY_V 9
# define KEY_B 11
# define KEY_N 45
# define KEY_P 35
# define KEY_R 15
# define KEY_MINUS 27
# define KEY_PLUS 24
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_RIGHT 124

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_matrix;
	int		**c_matrix;

	int		color;

	float	zoom;
	int		shift_x;
	int		shift_y;
	int		w;
	int		h;

	void	*img_ptr;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;

typedef struct s_pos
{
	float	x;
	float	y;
	float	z;
}	t_pos;

// typedef struct s_color
// {
// 	float	x;
// 	float	y;
// 	int		col;
// }	t_color;

int		word_count(char *line, char c);
int		get_height(char *file);
int		get_width(char	*file);
void	fill_matrix(int *z_line, int *c_line, char *line, t_fdf *data);
void	read_file(char *file, t_fdf *data);
void	check_amount(char *file);
void	check_error(int ac, char **av);
void	check_error2(int fd);
void	connectpoint(t_pos x1, t_pos x2, t_fdf *data);
void	drawmap(t_fdf *data);
void	drawmap_sub(t_pos pos, t_fdf *data, int mode);
void	zoom(t_pos *x1, t_fdf *data);
void	isometric(t_pos *x1, t_fdf *data);
void	color(t_pos *x1, t_pos *x2, t_fdf *data);
float	fmodule(float i);
int		deal_key(int key, t_fdf *data);
int		ft_atoibase16(char *str);
void	fillandfree(char *file, t_fdf *data);
void	freeall(char **word);
int		maxz(t_fdf *data);
// void	assign_color(char **word, int *z_line, char **nums, t_fdf *data);

#endif
