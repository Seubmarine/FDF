/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:30:07 by tbousque          #+#    #+#             */
/*   Updated: 2022/06/24 17:48:24 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat4x4	mat4x4_translate(float x, float y, float z)
{
	t_mat4x4	m;

	m = mat4x4_identity();
	m.m[0][3] = x;
	m.m[1][3] = y;
	m.m[2][3] = z;
	return (m);
}

t_mat4x4	mat4x4_scale(float x, float y, float z)
{
	t_mat4x4	m;

	m = mat4x4_empty();
	m.m[0][0] = x;
	m.m[1][1] = y;
	m.m[2][2] = z;
	m.m[3][3] = 1;
	return (m);
}
