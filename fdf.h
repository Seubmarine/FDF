/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 08:14:04 by tbousque          #+#    #+#             */
/*   Updated: 2022/05/26 05:07:34 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include"mlx.h"
# include"mlx_type.h"
# include"get_next_line.h"
# include "ft_3d.h"
# include<stddef.h>
# include<stdlib.h>
# define DEBUG 1
# if DEBUG
#  include<stdio.h>
# endif

int		key_exit(int keycode, t_mlx_info *mlx_info);
unsigned int	rgb(char t, char r, char g, char b);
void	image_put_pixel(t_img img, int x, int y, unsigned int rgb);
void	image_draw_line(t_img img, int x1, int y1, int x2, int y2);
int	test_parse(char *path);
#endif
