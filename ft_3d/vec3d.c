/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 06:32:51 by tbousque          #+#    #+#             */
/*   Updated: 2022/06/10 21:14:21 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3d.h"

t_vec3d	vec3d(float x, float y, float z)
{
	return ((t_vec3d){x, y, z});
}

t_vec3d vec3d_sub(t_vec3d *a, t_vec3d *b)
{
	t_vec3d v;
	v.x = a->x - b->x; 
	v.y = a->y - b->y; 
	v.z = a->z - b->z;
	return (v);
}

float vec3d_dotproduct(t_vec3d *a, t_vec3d *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

float vec3d_length(t_vec3d *v)
{
	return(sqrtf(vec3d_dotproduct(v, v)));
}

t_vec3d vec3d_normalize(t_vec3d *v)
{
	float length = vec3d_length(v);
	return ((t_vec3d) {v->x / length, v->y / length, v->z / length});
}

t_vec3d vec3d_mul(t_vec3d *v, float number)
{
	return ((t_vec3d) {v->x * number, v->y * number, v->z * number});
}

t_vec3d vec3d_add(t_vec3d *v1, t_vec3d *v2)
{
	return ((t_vec3d) {v1->x + v2->x, v1->y + v2->y, v1->z + v2->z});
}

t_vec3d vec3d_crossproduct(t_vec3d *v1, t_vec3d *v2)
{
		t_vec3d v;
		v.x = v1->y * v2->z - v1->x * v2->y;
		v.y = v1->z * v2->x - v1->x * v2->z;
		v.z = v1->x * v2->y - v1->y * v2->x;
		return v;
}