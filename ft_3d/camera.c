/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:01:23 by tbousque          #+#    #+#             */
/*   Updated: 2022/06/11 19:20:19 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_mat4x4	set_projection_matrix(float near, float far, float fov,
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

t_mat4x4	set_paralel_matrix(float right, float left, float top,
				float bottom, float far, float near)
{
	t_mat4x4	m;

	m = mat4x4_empty();
	m.m[0][0] = 2 / (right - left);
	m.m[1][1] = 2 / (top - bottom);
	m.m[2][2] = -2 / (far - near);
	m.m[3][3] = 1;
	m.m[0][3] = -(right + left) / (right - left);
	m.m[1][3] = -(top + bottom) / (top - bottom);
	m.m[2][3] = -(far + near) / (far - near);
	return (m);
}

t_mat4x4	get_projection_matrix(t_projection container)
{
	if (container.mode == mode_perspective)
		return (container.perspective);
	return (container.paralel);
}

t_projection	set_all_proj(float near, float far, float fov,
	float aspect_ratio)
{
	t_projection	p;

	p.perspective = set_projection_matrix(near, far, fov, aspect_ratio);
	p.paralel = set_paralel_matrix(30, -30, 30, -30, 30, -30);
	p.mode = mode_perspective;
	return (p);
}

void	switch_projection_mode(t_projection *p)
{
	p->mode = !p->mode;
}