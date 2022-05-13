/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:18:33 by tbousque          #+#    #+#             */
/*   Updated: 2022/05/13 19:04:33 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2.h"

t_vector2	vector2(int x, int y)
{
	return ((t_vector2){x, y});
}

t_vector2	vector2_add(t_vector2 a, t_vector2 b)
{
	return ((t_vector2){a.x + b.x, a.y + b.y});
}

t_vector2	vector2_matrix(t_vector2 v, double mat[4])
{
	t_vector2	new_vec;

	new_vec.x = (v.x * mat[0]) + (v.y * mat[1]);
	new_vec.y = (v.x * mat[3]) + (v.y * mat[2]);
	return (new_vec);
}

t_vector2	vector2_sub(t_vector2 a, t_vector2 b)
{
	return ((t_vector2){a.x - b.x, a.y - b.y});
}
