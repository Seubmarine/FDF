/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 02:07:22 by tbousque          #+#    #+#             */
/*   Updated: 2022/06/23 21:03:49 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_EVENT_H
# define MLX_EVENT_H
# include "mlx_type.h"
# include "vec2di.h"
# include "parser.h"
# define KEY_L 108
# define KEY_W 119
# define KEY_D 100
# define KEY_S 115
# define KEY_A 97
# define KEY_SPACE 32
# define KEY_C 99
# define KEY_Q 113
# define KEY_P 112
# define MOVE_SPEED 0.2f

int		key_event(int keycode, t_mlx_info *info);
int		mouse_event(int x, int y, t_mlx_info *info);
int		mlx_context_free(t_mlx_info *context);

#endif