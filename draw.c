/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:52:16 by tbousque          #+#    #+#             */
/*   Updated: 2022/06/25 20:04:08 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_image.h"

t_img	image_create(void *mlx_ptr, int size_x, int size_y)
{
	t_img	img;

	img.ptr = mlx_new_image(mlx_ptr, size_x, size_y);
	img.buffer = mlx_get_data_addr(img.ptr, &img.bits_per_pixel, \
		&img.size_line, &img.endian);
	img.x = size_x;
	img.y = size_y;
	return (img);
}

void	image_put_pixel(t_img img, int x, int y, unsigned int rgb)
{
	((unsigned int *)img.buffer)[y * img.x + x] = rgb;
}

void	image_clear(t_img img)
{
	ft_memset(img.buffer, 0, img.x * sizeof(unsigned int) * img.y);
}

// unsigned int	rgb(char alpha, char red, char green, char blue)
// {
// 	return (alpha << 24 | red << 16 | green << 8 | blue);
// }

t_brasenham_helper	draw_helper(t_vec2di a, t_vec2di b)
{
	t_brasenham_helper	x;

	x.dx = ft_abs(b.x - a.x);
	x.sx = -1;
	if (a.x < b.x)
		x.sx = 1;
	x.dy = ft_abs(b.y - a.y);
	x.sy = -1;
	if (a.y < b.y)
		x.sy = 1;
	x.err = -x.dy;
	if (x.dx > x.dy)
		x.err = x.dx;
	x.err /= 2;
	return (x);
}

void	image_draw_line(t_img img, t_vec2di a, t_vec2di b)
{
	t_brasenham_helper	t;
	int					e2;

	t = draw_helper(a, b);
	while (1)
	{
		image_put_pixel(img, a.x, a.y, 0xFF34EBE5);
		if (a.x == b.x && a.y == b.y)
			break ;
		e2 = t.err;
		if (e2 > -t.dx)
		{
			t.err -= t.dy;
			a.x += t.sx;
		}
		if (e2 < t.dy)
		{
			t.err += t.dx;
			a.y += t.sy;
		}
	}
}
/*
//Bresenham algorithm 
void	image_draw_line(t_img img, int x0, int y0, int x1, int y1, int rgb) {

	int	dx = abs(x1-x0), sx = x0 < x1 ? 1 : -1;
	int	dy = abs(y1-y0), sy = y0 < y1 ? 1 : -1; 
	int	err = (dx > dy ? dx : -dy) / 2, e2;

	while (1)
	{
		image_put_pixel(img, x0, y0, rgb);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y0 += sy;
		}
	}
}
*/


//0xFF34EBE5