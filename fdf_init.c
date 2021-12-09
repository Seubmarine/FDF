/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:04:36 by tbousque          #+#    #+#             */
/*   Updated: 2021/12/09 11:04:58 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	void	*mlx_ptr = NULL;
	void	*win_ptr;

	(void) argc;
	(void) argv;

	mlx_ptr = mlx_init();

	if(mlx_ptr == NULL)
	{
		printf("error mlx_init");
		return (1);
	}
	#if DEBUG
		printf("mlx_inited!\n");
	#endif
	win_ptr = mlx_new_window(mlx_ptr, 620, 400, "FDF");
	#if DEBUG
		printf("window pointer is set to : %p\n", win_ptr);
	#endif
	mlx_destroy_window(mlx_ptr, win_ptr);
	return (0);
}
