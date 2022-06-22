/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:38:15 by tbousque          #+#    #+#             */
/*   Updated: 2022/06/23 01:13:26 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3d.h"

t_vec3d	vec3d_crossproduct(t_vec3d *v1, t_vec3d *v2)
{
	t_vec3d	v;

	v.x = v1->y * v2->z - v1->x * v2->y;
	v.y = v1->z * v2->x - v1->x * v2->z;
	v.z = v1->x * v2->y - v1->y * v2->x;
	return (v);
}

float	vec3d_dotproduct(t_vec3d *a, t_vec3d *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

float	vec3d_length(t_vec3d *v)
{
	return (sqrtf(vec3d_dotproduct(v, v)));
}

t_vec3d	vec3d_normalize(t_vec3d *v)
{
	const float	length = vec3d_length(v);

	return ((t_vec3d){v->x / length, v->y / length, v->z / length});
}
