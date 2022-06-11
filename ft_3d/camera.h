/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:21:50 by tbousque          #+#    #+#             */
/*   Updated: 2022/06/11 13:25:11 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
# include "vec3d.h"
typedef struct s_camera 
{
	t_vec3d pos;
	t_vec3d	look_dir;
	float yaw;
	float pitch;
} t_camera;
#endif