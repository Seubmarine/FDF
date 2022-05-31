/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 02:07:22 by tbousque          #+#    #+#             */
/*   Updated: 2022/05/31 02:30:42 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_EVENT_H
# define MLX_EVENT_H
# include "mlx_type.h"
# include "vec2di.h"

int		key_event(int keycode, t_mlx_info *info);
int		mouse_event(int x, int y, t_mlx_info *info);
void	mlx_context_free(t_mlx_info *context);

#endif