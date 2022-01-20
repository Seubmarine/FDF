/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:04:36 by tbousque          #+#    #+#             */
/*   Updated: 2022/01/20 12:22:42 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_img	image_create(void *mlx_ptr, int size_x, int size_y)
{
	t_img	img;

	img.ptr = mlx_new_image(mlx_ptr, size_x, size_y);
	img.buffer = mlx_get_data_addr(img.ptr, &img.bits_per_pixel, &img.size_line, &img.endian);
	return (img);
}

void image_put_pixel(t_img img, int x, int y, unsigned int rgb)
{
	char	*dst;

	dst = img.buffer + (y * img.size_line + x * (img.bits_per_pixel / 8));
	*(unsigned int*)dst = rgb;
}

//wireframe triangle
void image_put_triangle(t_img img, t_point a, t_point b, t_point c)
{
	image_draw_line(img, a.x, a.y, b.x, b.y);
	image_draw_line(img, b.x, b.y, c.x, c.y);
	image_draw_line(img, c.x, c.y, a.x, a.y);
}

int	main(int argc, char **argv)
{
	/*
	t_mlx_info	context;
	t_point a = {.x = 100, .y = 50};
	t_point b = {.x = 370, .y = 153};
	t_point c = {.x = 5, .y = 307};
	t_point d = {.x = b.x + a.x, .y = b.y + a.y }; 
	
	(void) argc;
	(void) argv;
	context.mlx_ptr = mlx_init();
	context.win_ptr = mlx_new_window(context.mlx_ptr, 620, 400, "FDF");
	context.img = image_create(context.mlx_ptr, 620, 400);

	image_put_triangle(context.img, a, b, c);
	image_put_triangle(context.img, d, b, c);

	mlx_put_image_to_window(context.mlx_ptr, context.win_ptr, context.img.ptr, 0, 0);
	mlx_key_hook(context.win_ptr, &key_exit, &context);
	mlx_loop(context.mlx_ptr);
	*/
	if (argc < 2)
		return (1); //no file given
	test_parse(argv[1]);
	return (0);
}
