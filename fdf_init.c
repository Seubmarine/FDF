/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:04:36 by tbousque          #+#    #+#             */
/*   Updated: 2022/06/11 17:30:48 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//6 motion notify, OL all
int	main(int argc, char **argv)
{
	t_mlx_info	mlx;

	if (argc < 2)
	{
		printf("No file provided\n");
		return (EXIT_FAILURE);
	}
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, SCREEN_X, SCREEN_Y, "FDF");
	mlx.img = image_create(mlx.mlx_ptr, SCREEN_X, SCREEN_Y);
	mlx.map = parse_file_to_mesh(argv[1]);
	mlx.camera.pos = vec3d(0, 0, 0);
	mlx.camera.look_dir = vec3d(0, 0, 1);
	mlx.camera.pitch = 0.0f;
	mlx.camera.yaw = 0.0f;
	mlx.map->transform = mat4x4_identity();
	if (mlx.map == NULL)
		return (EXIT_FAILURE);
	mlx.proj = set_projection_matrix(0.1f, 1000.0f, 90.f, (float)mlx.img.y / (float)mlx.img.x);
	mlx_do_key_autorepeaton(mlx.mlx_ptr);
	//mlx_key_hook(mlx.win_ptr, &key_event, &mlx);
	mlx_hook(mlx.win_ptr, 2, 1L<<0, &key_event, &mlx);
	mlx_hook(mlx.win_ptr, 6, 1L<<6, &mouse_event, &mlx);
	mlx_hook(mlx.win_ptr, 17, 1L<<0, &mlx_context_free, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
