/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:01:23 by tbousque          #+#    #+#             */
/*   Updated: 2022/06/25 20:30:09 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_mat4x4	set_perspective_matrix(float near, float far, float fov,
					float aspect_ratio)
{
	const float	fovrad = 1.0f / tanf(fov * 0.5f / 180.0f * 3.14159f);
	t_mat4x4	proj;

	proj = mat4x4_empty();
	proj.m[0][0] = aspect_ratio * fovrad;
	proj.m[1][1] = fovrad;
	proj.m[2][2] = far / (far - near);
	proj.m[3][2] = (-far * near) / (far - near);
	proj.m[2][3] = 1.0f;
	proj.m[3][3] = 0.0f;
	return (proj);
}

t_mat4x4	set_isometric_matrix(void)
{
	t_mat4x4	rot;

	rot = mat4x4_product(
			mat4x4_rotate_z(to_rad(-30)), \
			mat4x4_rotate_y(to_rad(30))
			);
	return (rot);
}

t_mat4x4	get_projection_matrix(t_projection container)
{
	if (container.mode == mode_perspective)
		return (container.perspective);
	return (container.isometric);
}

t_projection	set_all_proj(float near, float far, float fov,
	float aspect_ratio)
{
	t_projection	p;

	p.perspective = set_perspective_matrix(near, far, fov, aspect_ratio);
	p.isometric = set_isometric_matrix();
	p.mode = mode_isometric;
	return (p);
}

void	switch_projection_mode(t_projection *p)
{
	p->mode = !p->mode;
}
