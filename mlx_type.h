/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_type.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 05:05:39 by tbousque          #+#    #+#             */
/*   Updated: 2022/06/10 21:05:33 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_TYPE_H
# define MLX_TYPE_H
# include "mesh.h"

typedef struct s_mlx_info
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_mesh	*map;
	t_mat4x4 proj;
	t_vec3d camera_pos;
	t_vec3d	look_dir;
	t_img img;
} t_mlx_info;

#endif