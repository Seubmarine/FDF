/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 05:12:18 by tbousque          #+#    #+#             */
/*   Updated: 2022/05/26 06:01:13 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_IMAGE_H
# define MLX_IMAGE_H
# include <math.h>
# include <stdlib.h>
# include "mlx.h"
# include "vec2di.h"

typedef struct s_img
{
	void	*ptr;
	char	*buffer;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int x;
	int y;
}	t_img;

t_img	image_create(void *mlx_ptr, int size_x, int size_y);
void	image_draw_line(t_img img, int x0, int y0, int x1, int y1);
void	image_clear(t_img img);
#endif