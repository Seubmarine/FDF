/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:04:36 by tbousque          #+#    #+#             */
/*   Updated: 2022/05/24 09:03:25 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	char	*dst;

	dst = img.buffer + (y * img.size_line + x * (img.bits_per_pixel / 8));
	*(unsigned int*)dst = rgb;
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

int	rot_on_press(int keycode, t_mlx_info *info)
{
	static double angle = 0;

	//printf("keycode : %d as been released\n", keycode);
	if (keycode == 65361)
		angle += 0.1f;
	else if (keycode == 65363)
		angle -= 0.1f;
	image_clear(info->img);	
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img.ptr, 0, 0);
	if (keycode == 114)
		image_clear(info->img);	
	if (keycode == 65307 || keycode == 113 || keycode == 65477)
		exit(0);

	return (0);
}

#include "vec2di.h"
int hook_mouse_pos(int x, int y, t_mlx_info *info)
{
	(void) info;
	static t_vec2di last = {.x = 0, .y = 0};
	t_vec2di current = vec2di(x, y);
	t_vec2di relative = vec2di_sub(last, current);
	last = current;
	static double angle = 0;

	angle += (double) (relative.x) / 1000;
	printf("mouse: %i, %i\n", x, y);
	printf("relative: %i, %i\n", relative.x, relative.y);
	image_clear(info->img);	
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img.ptr, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	t_mlx_info	context;
	
	context.mlx_ptr = mlx_init();
	context.win_ptr = mlx_new_window(context.mlx_ptr, 620, 400, "FDF");
	context.img = image_create(context.mlx_ptr, 620, 400);
	
	mlx_put_image_to_window(context.mlx_ptr, context.win_ptr, context.img.ptr, 0, 0);
	//mlx_key_hook(context.win_ptr, &key_exit, &context);
	mlx_key_hook(context.win_ptr, &rot_on_press, &context);
	//6 motion notify, OL all
	mlx_hook(context.win_ptr, 6, 1L<<6, &hook_mouse_pos, &context);
	mlx_loop(context.mlx_ptr);
	return (0);
}
