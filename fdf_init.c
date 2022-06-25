/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:04:36 by tbousque          #+#    #+#             */
/*   Updated: 2022/06/24 18:04:44 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//6 motion notify, OL all
int	main(int argc, char **argv)
{
	t_mlx_info	mlx;

	if (argc < 2)
	{
		ft_putstr_fd("No file provided\n", 1);
		return (EXIT_FAILURE);
	}
	mlx.map = parse_file_to_mesh(argv[1]);
	if (mlx.map == NULL)
		return (EXIT_FAILURE);
	mlx.map->transform = mat4x4_identity();
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, SCREEN_X, SCREEN_Y, "FDF");
	mlx.img = image_create(mlx.mlx_ptr, SCREEN_X, SCREEN_Y);
	mlx.camera.pos = vec3d(0, 0, 0);
	mlx.camera.look_dir = vec3d(0, 0, 1);
	mlx.camera.yaw = 0.0f;
	mlx.proj = set_all_proj(0.1f, 1000.0f, 90.f, \
		(float)mlx.img.y / (float)mlx.img.x);
	mlx_hook(mlx.win_ptr, 2, 1L << 0, &key_event, &mlx);
	mlx_hook(mlx.win_ptr, 6, 1L << 6, &mouse_event, &mlx);
	mlx_hook(mlx.win_ptr, 17, 1L << 0, &mlx_context_free, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
