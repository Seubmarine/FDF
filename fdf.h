/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 08:14:04 by tbousque          #+#    #+#             */
/*   Updated: 2022/01/20 05:39:36 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include"mlx.h"
# include"get_next_line.h"
# include<stddef.h>
# include<stdlib.h>
# define DEBUG 1
# if DEBUG
#  include<stdio.h>
# endif

typedef struct s_img
{
	void	*ptr;
	char	*buffer;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_point
{
	int x;
	int y;
}	t_point;

typedef struct s_mlx_info
{
	void *mlx_ptr;
	void *win_ptr;
	t_img img;
} t_mlx_info;

int		key_exit(int keycode, t_mlx_info *mlx_info);
unsigned int	rgb(char t, char r, char g, char b);
void	image_put_pixel(t_img img, int x, int y, unsigned int rgb);
void	image_draw_line(t_img img, int x1, int y1, int x2, int y2);
int	test_parse(char *path);
#endif
