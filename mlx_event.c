/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 02:05:08 by tbousque          #+#    #+#             */
/*   Updated: 2022/05/31 02:35:50 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_event.h"

void	mlx_context_free(t_mlx_info *context)
{
	free(context->map);
	mlx_destroy_image(context->mlx_ptr, context->img.ptr);
	mlx_destroy_window(context->mlx_ptr, context->win_ptr);
	mlx_destroy_display(context->mlx_ptr);
	free(context->mlx_ptr);
}

int	key_event(int keycode, t_mlx_info *info)
{
	if (keycode == 114)
		image_clear(info->img);
	if (keycode == 65307 || keycode == 113 || keycode == 65477)
	{
		mlx_context_free(info);
		exit(0);
	}
	return (0);
}

int	mouse_event(int x, int y, t_mlx_info *info)
{
	static t_vec2di	last = {.x = 0, .y = 0};
	static double	angle_x = 0;
	static double	angle_y = 0;
	t_vec2di		current;
	t_vec2di		relative;

	current = vec2di(x, y);
	relative = vec2di_sub(last, current);
	last = current;
	
	angle_y += (double)(relative.x) / 100;
	angle_x += (double)(relative.y) / 100;
	t_mat4x4 	roty = mat4x4_rotate_y(angle_y);
	t_mat4x4	rotx = mat4x4_rotate_x(angle_x);
	t_mat4x4	rot = mat4x4_product(rotx, roty);
	info->map->transform = rot;
	
	printf("mouse: %i, %i\n", x, y);
	printf("relative: %i, %i\n", relative.x, relative.y);
	
	image_clear(info->img);
	mesh_draw(info->map, info->img, info->proj);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img.ptr, 0, 0);
	return (0);
}