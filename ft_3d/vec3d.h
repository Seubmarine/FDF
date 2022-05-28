/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 06:24:20 by tbousque          #+#    #+#             */
/*   Updated: 2022/05/26 04:47:01 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3D_H
# define VEC3D_H
# include "matrix.h"

typedef struct s_vec3d
{
	float x;
	float y;
	float z;
}	t_vec3d;

t_vec3d	vec3d(float x, float y, float z);
t_vec3d vec3d_projected(t_vec3d i, t_mat4x4 m);

#endif 