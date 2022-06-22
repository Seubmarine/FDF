/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_dup_edges.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 07:47:50 by tbousque          #+#    #+#             */
/*   Updated: 2022/06/23 00:50:57 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEL_DUP_EDGES_H
# define DEL_DUP_EDGES_H
# include "ft_qsort.h"
# include "mesh.h"

t_edge	*remove_edges_double(t_edge *edges, size_t *egdes_size);
#endif