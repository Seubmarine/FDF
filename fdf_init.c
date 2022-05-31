/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:04:36 by tbousque          #+#    #+#             */
/*   Updated: 2022/05/31 17:02:24 by tbousque         ###   ########.fr       */
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
	if (mlx.map == NULL)
		return (EXIT_FAILURE);
	mlx.proj = set_projection_matrix(0.1f, 1000.0f, 90.f, (float)mlx.img.y / (float)mlx.img.x);
	mlx_key_hook(mlx.win_ptr, &key_event, &mlx);
	mlx_hook(mlx.win_ptr, 6, 1L<<6, &mouse_event, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
