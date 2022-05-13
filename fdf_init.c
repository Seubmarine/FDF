/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:04:36 by tbousque          #+#    #+#             */
/*   Updated: 2022/05/13 19:02:26 by tbousque         ###   ########.fr       */
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
void image_put_triangle(t_img img, t_vector2 a, t_vector2 b, t_vector2 c)
{
	image_draw_line(img, a.x, a.y, b.x, b.y);
	image_draw_line(img, b.x, b.y, c.x, c.y);
	image_draw_line(img, c.x, c.y, a.x, a.y);
}

t_rect	rect_init(t_vector2 pos, t_vector2 size)
{
	t_rect square;
	square.vertices[0] = pos;
	square.vertices[1] = vector2(pos.x + size.x, pos.y);
	square.vertices[2] = vector2(pos.x, pos.y + size.y);
	square.vertices[3] = vector2(pos.x + size.x, pos.y + size.y);
	return (square);
}

void image_draw_line_from_vector2(t_img img, t_vector2 a, t_vector2 b)
{
	image_draw_line(img, a.x, a.y, b.x, b.y);
}

t_rect	rect_rot(t_rect r, t_vector2 center, double angle)
{
	double	cos_result = cos(angle);
	double	sin_result = sin(angle);
	double	rot_mat[4] = {cos_result, -sin_result, cos_result, sin_result};
	t_rect			new_rect;
	int i = 0;
	while (i < 4)
	{
		t_vector2 to_center = vector2_sub(r.vertices[i], center);
		t_vector2 rotated = vector2_matrix(to_center, rot_mat);
		t_vector2 to_previous_pos = vector2_add(rotated, center);
		
		new_rect.vertices[i] = to_previous_pos;
		i++;
	}
	return (new_rect);
}

void	rect_draw(t_img img, t_rect r)
{
		image_draw_line_from_vector2(img, r.vertices[0], r.vertices[1]);
		image_draw_line_from_vector2(img, r.vertices[1], r.vertices[3]);
		image_draw_line_from_vector2(img, r.vertices[3], r.vertices[2]);
		image_draw_line_from_vector2(img, r.vertices[0], r.vertices[2]);
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
		angle += 3.14 / 8;
	else if (keycode == 65363)
		angle -= 0.4f;
	t_rect rot = rect_rot(info->map, info->map.vertices[0] ,angle);
	image_clear(info->img);	
	rect_draw(info->img, rot);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img.ptr, 0, 0);
	if (keycode == 114)
		image_clear(info->img);	
	if (keycode == 65307 || keycode == 113 || keycode == 65477)
		exit(0);

	return (0);
}

int hook_mouse_pos(int x, int y, t_mlx_info *info)
{
	(void) info;
	static t_vector2 last = {.x = 0, .y = 0};
	t_vector2 current = vector2(x, y);
	t_vector2 relative = vector2_sub(last, current);
	last = current;
	static double angle = 0;

	angle += (double) (relative.x) / 1000;
	printf("mouse: %i, %i\n", x, y);
	printf("relative: %i, %i\n", relative.x, relative.y);
	t_rect rot = rect_rot(info->map, info->map.vertices[0], angle);
	image_clear(info->img);	
	rect_draw(info->img, rot);
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
	context.map = rect_init(vector2(300, 100), vector2(50, 60));
	rect_draw(context.img, context.map);
	
	mlx_put_image_to_window(context.mlx_ptr, context.win_ptr, context.img.ptr, 0, 0);
	//mlx_key_hook(context.win_ptr, &key_exit, &context);
	mlx_key_hook(context.win_ptr, &rot_on_press, &context);
	//6 motion notify, OL all
	mlx_hook(context.win_ptr, 6, 1L<<6, &hook_mouse_pos, &context);
	mlx_loop(context.mlx_ptr);
	return (0);
}
