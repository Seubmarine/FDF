/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:51:23 by tbousque          #+#    #+#             */
/*   Updated: 2022/05/13 19:01:41 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2_H
# define VECTOR2_H
# include <math.h>
typedef struct s_vector2
{
	int	x;
	int	y;
}	t_vector2;

t_vector2	vector2(int x, int y);

t_vector2	vector2_add(t_vector2 a, t_vector2 b);

t_vector2	vector2_matrix(t_vector2 v, double mat[4]);

t_vector2	vector2_sub(t_vector2 a, t_vector2 b);

#endif