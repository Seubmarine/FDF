/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:52:16 by tbousque          #+#    #+#             */
/*   Updated: 2022/06/25 19:22:00 by tbousque         ###   ########.fr       */
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

unsigned int	rgb(char alpha, char red, char green, char blue)
{
	return (alpha << 24 | red << 16 | green << 8 | blue);
}

void	image_draw_line(t_img img, t_vec2di a, t_vec2di b)
{
	int	dx = abs(b.x - a.x), sx = a.x < b.x ? 1 : -1;
	int	dy = abs(b.y - a.y), sy = a.y < b.y ? 1 : -1; 
	int	err = (dx > dy ? dx : -dy) / 2, e2;

	while (1)
	{
		image_put_pixel(img, a.x, a.y, 0xFF34EBE5);
		if (a.x == b.x && a.y == b.y)
			break ;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			a.x += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			a.y += sy;
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

// #include <stdbool.h>
// void image_draw_line(t_img surface, int x, int y, int x2, int y2, int rgb) {
//    	bool yLonger=false;
// 	int shortLen=y2-y;
// 	int longLen=x2-x;
// 	if (abs(shortLen)>abs(longLen)) {
// 		int swap=shortLen;
// 		shortLen=longLen;
// 		longLen=swap;				
// 		yLonger=true;
// 	}
// 	int decInc;
// 	if (longLen==0) decInc=0;
// 	else decInc = (shortLen << 16) / longLen;

// 	if (yLonger) {
// 		if (longLen>0) {
// 			longLen+=y;
// 			for (int j=0x8000+(x<<16);y<=longLen;++y) {
// 				image_put_pixel(surface,j >> 16,y, rgb);	
// 				j+=decInc;
// 			}
// 			return;
// 		}
// 		longLen+=y;
// 		for (int j=0x8000+(x<<16);y>=longLen;--y) {
// 			image_put_pixel(surface,j >> 16,y, rgb);	
// 			j-=decInc;
// 		}
// 		return;	
// 	}

// 	if (longLen>0) {
// 		longLen+=x;
// 		for (int j=0x8000+(y<<16);x<=longLen;++x) {
// 			image_put_pixel(surface,x,j >> 16, rgb);
// 			j+=decInc;
// 		}
// 		return;
// 	}
// 	longLen+=x;
// 	for (int j=0x8000+(y<<16);x>=longLen;--x) {
// 		image_put_pixel(surface,x,j >> 16, rgb);
// 		j-=decInc;
// 	}

// }