#include "mlx_image.h"

t_img	image_create(void *mlx_ptr, int size_x, int size_y)
{
	t_img	img;

	img.ptr = mlx_new_image(mlx_ptr, size_x, size_y);
	img.buffer = mlx_get_data_addr(img.ptr, &img.bits_per_pixel, &img.size_line, &img.endian);
	img.x = size_x;
	img.y = size_y;
	return (img);
}

void image_put_pixel(t_img img, int x, int y, unsigned int rgb)
{
	//char	*dst;
	if (x < 0 || x > img.x || y < 0 || y > img.y)
		return ;
	//dst = img.buffer + (y * img.size_line + x * (img.bits_per_pixel / 8));
	//*(unsigned int*)dst = rgb;
	((unsigned int *)img.buffer)[y * img.x + x] = rgb;
}

//wireframe triangle
void image_put_triangle(t_img img, t_vec2di a, t_vec2di b, t_vec2di c)
{
	image_draw_line(img, a.x, a.y, b.x, b.y);
	image_draw_line(img, b.x, b.y, c.x, c.y);
	image_draw_line(img, c.x, c.y, a.x, a.y);
}

void image_draw_line_from_vec2di(t_img img, t_vec2di a, t_vec2di b)
{
	image_draw_line(img, a.x, a.y, b.x, b.y);
}

#include <string.h>
void	image_clear(t_img img)
{
	memset(img.buffer, 0, img.x * sizeof(unsigned int) * img.y);
}

unsigned int rgb(char alpha, char red, char green, char blue)
{
	return (alpha << 24 | red << 16 | green  << 8 | blue);
}

void	scan_line(t_img img, int x1, int x2, int y)
{
	while (x1 < x2)
	{
		image_put_pixel(img, x1, y, 0xFF34EBE5);
		x1++;
	}
}

//Bresenham algorithm
void	image_draw_line(t_img img, int x0, int y0, int x1, int y1) {

	int	dx = abs(x1-x0), sx = x0 < x1 ? 1 : -1;
	int	dy = abs(y1-y0), sy = y0 < y1 ? 1 : -1; 
	int	err = (dx > dy ? dx : -dy) / 2, e2;

	while(1)
	{
		image_put_pixel(img, x0, y0, 0xFF34EBE5);
		if (x0==x1 && y0==y1)
			break;
		e2 = err;
		if (e2 >-dx)
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
/*
void	image_draw_line(t_img img, int x1, int y1, int x2, int y2)
{
	int	dx;
	int	dy;
	int	p;

	dx = x2 - x1;
	dy = y2 - y1;
	while (x1 < x2)
	{
	if (p >= 0)
		{
			image_put_pixel(img, x1, y1, 0xFFFFFFFF);
			y1 += 1;
			p = p + dy * 2 - dx * 2;
		}
		else
		{
			image_put_pixel(img, x1, y1, 0xFFFFFFFF);
			p = p + dx * 2;
		}
		x1 += 1;
	}
}
*/
