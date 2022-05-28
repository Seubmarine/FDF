/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:04:36 by tbousque          #+#    #+#             */
/*   Updated: 2022/05/26 19:43:14 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


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
	static double angle_x = 0;
	static double angle_y = 0;
	angle_y += (double) (relative.x) / 100;
	angle_x += (double) (relative.y) / 100;

	//t_mat4x4 scale = mat4x4_scale(1, 1, 1);
	t_mat4x4 roty = mat4x4_rotate_y(angle_y);
	t_mat4x4 rotx = mat4x4_rotate_x(angle_x);
	t_mat4x4 rot = mat4x4_product(rotx, roty);
	info->map->transform = rot;
	
	printf("mouse: %i, %i\n", x, y);
	printf("relative: %i, %i\n", relative.x, relative.y);
	image_clear(info->img);
	mesh_draw(info->map, info->img, info->proj);
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
	//context.map = mesh_init_cube();
	//t_vec3d m_v[3] =  {{0.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 0.0f}};
	//t_edge	m_e[3] = {{{0, 1}}, {{1, 2}}, {{0, 2}}};
	//context.map = mesh_init(3, m_v, 3, m_e);
	context.map = mesh_init_cube();
	t_mat4x4 proj = set_projection_matrix(0.1f, 1000.0f, 90.f, (float)context.img.y /(float)context.img.x);
	context.proj = proj;
	mesh_draw(context.map, context.img, proj);
	//image_draw_line(context.img, 0, 0, 100, 100);
	//image_put_pixel(context.img)
	mlx_put_image_to_window(context.mlx_ptr, context.win_ptr, context.img.ptr, 0, 0);
	//mlx_key_hook(context.win_ptr, &key_exit, &context);
	mlx_key_hook(context.win_ptr, &rot_on_press, &context);
	//6 motion notify, OL all
	mlx_hook(context.win_ptr, 6, 1L<<6, &hook_mouse_pos, &context);
	mlx_loop(context.mlx_ptr);
	return (0);
}
