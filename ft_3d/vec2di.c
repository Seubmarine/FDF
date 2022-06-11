/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2di.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:18:33 by tbousque          #+#    #+#             */
/*   Updated: 2022/06/11 19:35:17 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec2di.h"

t_vec2di	vec2di(int x, int y)
{
	return ((t_vec2di){x, y});
}

t_vec2di	vec2di_add(t_vec2di a, t_vec2di b)
{
	return ((t_vec2di){a.x + b.x, a.y + b.y});
}

t_vec2di	vec2di_matrix(t_vec2di v, double mat[4])
{
	t_vec2di	new_vec;

	new_vec.x = (v.x * mat[0]) + (v.y * mat[1]);
	new_vec.y = (v.x * mat[3]) + (v.y * mat[2]);
	return (new_vec);
}

t_vec2di	vec2di_sub(t_vec2di a, t_vec2di b)
{
	return ((t_vec2di){a.x - b.x, a.y - b.y});
}
