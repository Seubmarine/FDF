/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2di.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:51:23 by tbousque          #+#    #+#             */
/*   Updated: 2022/05/24 06:56:40 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC2DI_H
# define VEC2DI_H
# include <math.h>
typedef struct s_vec2di
{
	int	x;
	int	y;
}	t_vec2di;

t_vec2di	vec2di(int x, int y);

t_vec2di	vec2di_add(t_vec2di a, t_vec2di b);

t_vec2di	vec2di_matrix(t_vec2di v, double mat[4]);

t_vec2di	vec2di_sub(t_vec2di a, t_vec2di b);

#endif