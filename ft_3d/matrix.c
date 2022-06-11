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

t_mat4x4    mat4x4_product(t_mat4x4 a, t_mat4x4 b)
{
    t_mat4x4    new = {};
    int         i;
    int         j;
    int         k;

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

t_mat4x4    mat4x4_scale(float x, float y, float z)
{
    t_mat4x4 m = {};
    m.m[0][0] = x;
    m.m[1][1] = y;
    m.m[2][2] = z;
    m.m[3][3] = 1;
    return (m);
}

t_mat4x4    mat4x4_rotate_y(float rad)
{
    t_mat4x4 m = {};
    float cos = cosf(rad);
    float sin = sinf(rad);

    m.m[0][0] = cos;
    m.m[0][2] = -sin;
    m.m[1][1] = 1.0f;
    m.m[2][0] = sin;
    m.m[2][2] = cos;
    m.m[3][3] = 1.0f;
    return (m);
}

t_mat4x4    mat4x4_rotate_x(float rad)
{
    t_mat4x4 m = {};
    float cos = cosf(rad);
    float sin = sinf(rad);

    m.m[0][0] = 1.0f;
    m.m[1][1] = cos;
    m.m[1][2] = -sin;
    m.m[2][1] = sin;
    m.m[2][2] = cos;
    m.m[3][3] = 1.0f;
    return (m);
}

static t_mat4x4	construct_pointat(t_vec3d newright, t_vec3d newup, t_vec3d newforward, t_vec3d pos)
{
    t_mat4x4 m;
	
	m.m[0][0] = newright.x;
	m.m[0][1] = newright.y;
	m.m[0][2] = newright.z;
	m.m[0][3] = 0.0f;
	m.m[1][0] = newup.x;
	m.m[1][1] = newup.y;
	m.m[1][2] = newup.z;
	m.m[1][3] = 0.0f;
	m.m[2][0] = newforward.x;
	m.m[2][1] = newforward.y;
	m.m[2][2] = newforward.z;
	m.m[2][3] = 0.0f,
	m.m[3][0] = pos.x;
	m.m[3][1] = pos.y;
	m.m[3][2] = pos.z;
	m.m[3][3] = 1.0f;
    return (m);
}

t_mat4x4 mat4x4_lookat(t_mat4x4 *m)
{
	t_mat4x4 matrix;
	matrix.m[0][0] = m->m[0][0]; matrix.m[0][1] = m->m[1][0]; matrix.m[0][2] = m->m[2][0]; matrix.m[0][3] = 0.0f;
	matrix.m[1][0] = m->m[0][1]; matrix.m[1][1] = m->m[1][1]; matrix.m[1][2] = m->m[2][1]; matrix.m[1][3] = 0.0f;
	matrix.m[2][0] = m->m[0][2]; matrix.m[2][1] = m->m[1][2]; matrix.m[2][2] = m->m[2][2]; matrix.m[2][3] = 0.0f;
	matrix.m[3][0] = -(m->m[3][0] * matrix.m[0][0] + m->m[3][1] * matrix.m[1][0] + m->m[3][2] * matrix.m[2][0]);
	matrix.m[3][1] = -(m->m[3][0] * matrix.m[0][1] + m->m[3][1] * matrix.m[1][1] + m->m[3][2] * matrix.m[2][1]);
	matrix.m[3][2] = -(m->m[3][0] * matrix.m[0][2] + m->m[3][1] * matrix.m[1][2] + m->m[3][2] * matrix.m[2][2]);
	matrix.m[3][3] = 1.0f;
	return matrix;
}

t_mat4x4    mat4x4_pointat(t_vec3d *pos, t_vec3d *target, t_vec3d *up)
{
    t_vec3d newforward;
    t_vec3d a;
    t_vec3d newup;
    t_vec3d newright;
    
    newforward = vec3d_sub(target, pos);
    newforward = vec3d_normalize(&newforward);
    a = vec3d_mul(&newforward, vec3d_dotproduct(up, &newforward));
    newup = vec3d_sub(up, &a);
    newup = vec3d_normalize(&newup);
    newright = vec3d_crossproduct(&newup, &newforward);
	return (construct_pointat(newright, newup, newforward, *pos));
}

t_vec3d	vec3d_projected(t_vec3d i, t_mat4x4 m)
{
	t_vec3d	o;
	float	w;

	o.x = i.x * m.m[0][0] + i.y * m.m[1][0] + i.z * m.m[2][0] + m.m[3][0];
	o.y = i.x * m.m[0][1] + i.y * m.m[1][1] + i.z * m.m[2][1] + m.m[3][1];
	o.z = i.x * m.m[0][2] + i.y * m.m[1][2] + i.z * m.m[2][2] + m.m[3][2];
	w = i.x * m.m[0][3] + i.y * m.m[1][3] + i.z * m.m[2][3] + m.m[3][3];
	if (w != 0.0f)
	{
		o.x /= w;
		o.y /= w;
		o.z /= w;
	}
	return (o);
}

t_mat4x4 mat4x4_identity(void)
{
	t_mat4x4 m = {};
	m.m[0][0] = 1;
	m.m[1][1] = 1;
	m.m[2][2] = 1;
	m.m[3][3] = 1;
	return (m);
}

/*
void mat4x4_printf(t_mat4x4 m)
{
    int x;
    int y;

    y = 0;
    while (y < 4)
    {
        x = 0;
        while (x < 4)
        {
            printf("%.0f,",m.elem[y][x]);
            x++;
        }
        printf("\n");
        y++;
    }
    printf("\n");
}
*/