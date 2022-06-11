/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 02:05:08 by tbousque          #+#    #+#             */
/*   Updated: 2022/06/11 17:31:30 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_event.h"

static void load_new_file(t_mlx_info *info)
{
	static char file_to_load[255] = "";
	ssize_t end;
	t_mesh *new_mesh;
	
	end = read(STDIN_FILENO, file_to_load, 255);
	file_to_load[end] = '\0';
	if (end >= 1 && file_to_load[end - 1] == '\n')
		file_to_load[end - 1] = '\0';
	new_mesh = parse_file_to_mesh(file_to_load);
	if (new_mesh)
	{
		free(info->map);
		info->map = new_mesh;
	}
}

int	mlx_context_free(t_mlx_info *context)
{
	free(context->map);
	mlx_destroy_image(context->mlx_ptr, context->img.ptr);
	mlx_destroy_window(context->mlx_ptr, context->win_ptr);
	mlx_destroy_display(context->mlx_ptr);
	free(context->mlx_ptr);
	exit(0);
	return (0);
}


#define KEY_W 119
#define KEY_D 100
#define KEY_S 115
#define KEY_A 97
#define KEY_SPACE 32
# define KEY_C 99
# define KEY_Q 113
# define MOVE_SPEED 0.2f;

static void key_move(int keycode, t_mlx_info *info)
{
	t_vec3d	dir;
	
	dir = vec3d(0, 0, 0);
	if (keycode == KEY_D)
		dir.x += MOVE_SPEED;
	if (keycode == KEY_A)
		dir.x -= MOVE_SPEED;
	if (keycode == KEY_W)
		dir.z += MOVE_SPEED; 
	if (keycode == KEY_S)
		dir.z -= MOVE_SPEED;
	if (keycode == KEY_SPACE)
		dir.y -= MOVE_SPEED;
	if (keycode == KEY_C)
		dir.y += MOVE_SPEED;
	dir = vec3d_projected(dir, mat4x4_rotate_y(info->camera.yaw));
	info->camera.pos = vec3d_add((&info->camera.pos), &dir);
}

int	key_event(int keycode, t_mlx_info *info)
{
	key_move(keycode, info);
	if (keycode == 114)
		image_clear(info->img);
	if (keycode == 65307 || keycode == 65477)
	{
		mlx_context_free(info);
		exit(0);
	}
	if (keycode == KEY_L)
	 	load_new_file(info);
	image_clear(info->img);
	mesh_draw(info->map, info->img, info->proj, &(info->camera), 0xFF34EBE5);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img.ptr, 0, 0);
	return (0);
}

int	mouse_event(int x, int y, t_mlx_info *info)
{
	static t_vec2di	last = {.x = 0, .y = 0};
	t_vec2di		current;
	t_vec2di		relative;

	current = vec2di(x, y);
	relative = vec2di_sub(last, vec2di(x, y));
	last = current;
	info->camera.yaw += -(relative.x / 100.0f);
	image_clear(info->img);
	mesh_draw(info->map, info->img, info->proj, &(info->camera), 0xFF34EBE5);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img.ptr, 0, 0);
	return (0);
}
