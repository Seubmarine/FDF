/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 05:12:18 by tbousque          #+#    #+#             */
/*   Updated: 2022/06/25 19:46:21 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_IMAGE_H
# define MLX_IMAGE_H
# include <math.h>
# include <stdlib.h>
# include "mlx.h"
# include "vec2di.h"
# include "libft.h"

typedef struct s_img
{
	void	*ptr;
	char	*buffer;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	int		y;
}	t_img;

typedef struct s_brasenham_helper
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}	t_brasenham_helper;

void	image_put_pixel(t_img img, int x, int y, unsigned int rgb);
t_img	image_create(void *mlx_ptr, int size_x, int size_y);
//void	image_draw_line(t_img img, int x0, int y0, int x1, int y1, int rgb);
void	image_draw_line(t_img img, t_vec2di a, t_vec2di b);
void	image_clear(t_img img);
#endif