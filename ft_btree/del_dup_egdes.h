/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_dup_egdes.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 07:47:50 by tbousque          #+#    #+#             */
/*   Updated: 2022/06/02 07:50:21 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEL_DUP_EDGES_H
# define DEL_DUP_EDGES_H
# include <stdio.h>
# include "ft_btree.h"
# include "mesh.h"
t_edge	*remove_egdes_double(t_edge *edges, size_t *egdes_size);
# endif