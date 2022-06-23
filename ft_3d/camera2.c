/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:37:03 by tbousque          #+#    #+#             */
/*   Updated: 2022/06/23 21:37:13 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_mat4x4	get_view_mat(t_camera *camera)
{
	t_vec3d		up;
	t_vec3d		target;
	t_mat4x4	camrot;
	t_mat4x4	camera_matrix;
	t_mat4x4	view_matrix;

	up = (t_vec3d){0, 1, 0};
	target = (t_vec3d){0, 0, 1};
	camrot = mat4x4_rotate_y(camera->yaw);
	camera->look_dir = vec3d_projected(target, camrot);
	target = vec3d_add(&(camera->pos), &(camera->look_dir));
	camera_matrix = mat4x4_pointat(&(camera->pos), &target, &up);
	view_matrix = mat4x4_lookat(&camera_matrix);
	return (view_matrix);
}