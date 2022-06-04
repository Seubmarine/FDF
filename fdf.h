/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 08:14:04 by tbousque          #+#    #+#             */
/*   Updated: 2022/06/04 05:59:02 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "mlx_type.h"
# include "get_next_line.h"
# include "ft_3d.h"
# include <stddef.h>
# include <stdlib.h>
# include "mlx_event.h"
# include "mlx_image.h"
# include "parser.h"
# define DEBUG 1
# if DEBUG
#  include<stdio.h>
# endif
# define SCREEN_X 1280
# define SCREEN_Y 652

unsigned int	rgb(char t, char r, char g, char b);
#endif
