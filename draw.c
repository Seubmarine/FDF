#include "fdf.h"

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
