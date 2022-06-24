/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 11:43:23 by tbousque          #+#    #+#             */
/*   Updated: 2022/05/22 12:47:53 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H
# include <math.h>
# include "vec3d.h"

typedef struct s_mat4x4
{
	float	m[4][4];
}	t_mat4x4;

t_mat4x4	mat4x4_empty(void);
t_mat4x4	mat4x4_identity(void);
t_mat4x4	mat4x4_product(t_mat4x4 a, t_mat4x4 b);
t_mat4x4	mat4x4_scale(float x, float y, float z);
t_mat4x4	mat4x4_rotate_y(float rad);
t_mat4x4	mat4x4_rotate_x(float rad);
t_mat4x4	mat4x4_rotate_z(float rad);
t_mat4x4	mat4x4_pointat(t_vec3d *pos, t_vec3d *target, t_vec3d *up);
t_mat4x4	mat4x4_lookat(t_mat4x4 *m);
t_vec3d		vec3d_projected(t_vec3d i, t_mat4x4 m);
t_mat4x4	mat4x4_translate(float x, float y, float z);

//void		mat4x4_printf(t_mat4x4 m);
#endif