/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:09:36 by tbousque          #+#    #+#             */
/*   Updated: 2022/06/25 20:11:21 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_event.h"

void	load_new_file(t_mlx_info *info)
{
	static char	file_to_load[255] = "";
	ssize_t		end;
	t_mesh		*new_mesh;

	end = read(STDIN_FILENO, file_to_load, 255);
	file_to_load[end] = '\0';
	if (end >= 1 && file_to_load[end - 1] == '\n')
		file_to_load[end - 1] = '\0';
	new_mesh = parse_file_to_mesh(file_to_load);
	if (new_mesh)
	{
		free(info->map);
		info->map = new_mesh;
	}
}

int	mlx_context_free(t_mlx_info *context)
{
	free(context->map);
	mlx_destroy_image(context->mlx_ptr, context->img.ptr);
	mlx_destroy_window(context->mlx_ptr, context->win_ptr);
	mlx_destroy_display(context->mlx_ptr);
	free(context->mlx_ptr);
	exit(0);
	return (0);
}