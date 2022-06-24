/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:21:50 by tbousque          #+#    #+#             */
/*   Updated: 2022/06/24 18:03:30 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
# include "vec3d.h"
# include "matrix.h"
# include "radian.h"

enum e_proj_mode {
	mode_perspective,
	mode_paralel
};

typedef struct s_camera
{
	t_vec3d	pos;
	t_vec3d	look_dir;
	float	yaw;
}	t_camera;

typedef struct s_projection
{
	enum e_proj_mode	mode;
	t_mat4x4			perspective;
	t_mat4x4			isometric;
}	t_projection;

t_mat4x4		get_projection_matrix(t_projection container);
t_projection	set_all_proj(float near, float far, float fov,
					float aspect_ratio);
void			switch_projection_mode(t_projection *p);
t_mat4x4		get_view_mat(t_camera *camera);

#endif