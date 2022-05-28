/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 06:55:16 by tbousque          #+#    #+#             */
/*   Updated: 2022/05/26 19:41:24 by tbousque         ###   ########.fr       */
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

t_mat4x4    set_projection_matrix(float near, float far, float fov,
    float aspect_ratio)
{
    const float fovrad = 1.0f / tanf(fov * 0.5f / 180.0f * 3.14159f);
    t_mat4x4      proj = {};
    proj.m[0][0] = aspect_ratio * fovrad;
    proj.m[1][1] = fovrad;
    proj.m[2][2] = far / (far - near);
    proj.m[3][2] = (-far * near) / (far - near);
    proj.m[2][3] = 1.0f;
    proj.m[3][3] = 0.0f;
    return (proj);
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