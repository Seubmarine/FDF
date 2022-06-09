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
#include <math.h>
typedef struct s_mat4x4
{
	float m[4][4];
} t_mat4x4;

t_mat4x4    mat4x4_product(t_mat4x4 a, t_mat4x4 b);
t_mat4x4    set_paralel_matrix(float right, float left, float top, float bottom, float far, float near);
t_mat4x4    set_projection_matrix(float near, float far, float fov,
    float aspect_ratio);
t_mat4x4    mat4x4_scale(float x, float y, float z);
t_mat4x4    mat4x4_rotate_y(float rad);
t_mat4x4    mat4x4_rotate_x(float rad);
//void		mat4x4_printf(t_mat4x4 m);
#endif