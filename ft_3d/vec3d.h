/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 06:24:20 by tbousque          #+#    #+#             */
/*   Updated: 2022/06/23 01:14:00 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3D_H
# define VEC3D_H
# include <math.h>

typedef struct s_vec3d
{
	float	x;
	float	y;
	float	z;
}	t_vec3d;

t_vec3d	vec3d(float x, float y, float z);
t_vec3d	vec3d_add(t_vec3d *v1, t_vec3d *v2);
t_vec3d	vec3d_sub(t_vec3d *a, t_vec3d *b);
t_vec3d	vec3d_normalize(t_vec3d *v);
t_vec3d	vec3d_mul(t_vec3d *v, float number);
float	vec3d_dotproduct(t_vec3d *a, t_vec3d *b);
t_vec3d	vec3d_crossproduct(t_vec3d *v1, t_vec3d *v2);
#endif 