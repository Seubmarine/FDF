/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 06:55:16 by tbousque          #+#    #+#             */
/*   Updated: 2022/05/24 06:55:19 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat4x4    mat4x4_product(t_mat4x4 a, t_mat4x4 b)
{
    t_mat4x4    new;
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