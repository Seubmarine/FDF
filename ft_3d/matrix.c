/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 06:55:16 by tbousque          #+#    #+#             */
/*   Updated: 2022/06/10 19:34:06 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat4x4	mat4x4_empty(void)
{
	t_mat4x4	m;

	m.m[0][0] = 0;
	m.m[0][1] = 0;
	m.m[0][2] = 0;
	m.m[0][3] = 0;
	m.m[1][0] = 0;
	m.m[1][1] = 0;
	m.m[1][2] = 0;
	m.m[1][3] = 0;
	m.m[2][0] = 0;
	m.m[2][1] = 0;
	m.m[2][2] = 0;
	m.m[2][3] = 0;
	m.m[3][0] = 0;
	m.m[3][1] = 0;
	m.m[3][2] = 0;
	m.m[3][3] = 0;
	return (m);
}

t_mat4x4	mat4x4_product(t_mat4x4 a, t_mat4x4 b)
{
	t_mat4x4	new;
	int			i;
	int			j;
	int			k;

	new = mat4x4_empty();
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			new.m[i][j] = 0;
			while (k < 4)
			{
				new.m[i][j] += a.m[i][k] * b.m[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (new);
}

t_mat4x4	mat4x4_rotate_y(float rad)
{
	t_mat4x4	m;
	const float	cos = cosf(rad);
	const float	sin = sinf(rad);

	m = mat4x4_empty();
	m.m[0][0] = cos;
	m.m[0][2] = sin;
	m.m[1][1] = 1.0f;
	m.m[2][0] = -sin;
	m.m[2][2] = cos;
	m.m[3][3] = 1.0f;
	return (m);
}

t_mat4x4	mat4x4_rotate_x(float rad)
{
	t_mat4x4	m;
	const float	cos = cosf(rad);
	const float	sin = sinf(rad);

	m = mat4x4_empty();
	m.m[0][0] = 1.0f;
	m.m[1][1] = cos;
	m.m[1][2] = -sin;
	m.m[2][1] = sin;
	m.m[2][2] = cos;
	m.m[3][3] = 1.0f;
	return (m);
}

t_mat4x4	mat4x4_rotate_z(float rad)
{
	t_mat4x4	m;
	const float	cos = cosf(rad);
	const float	sin = sinf(rad);

	m = mat4x4_empty();
	m.m[0][0] = cos;
	m.m[0][1] = -sin;
	m.m[1][0] = sin;
	m.m[1][1] = cos;
	m.m[2][2] = 1.0f;
	m.m[3][3] = 1.0f;
	return (m);
}