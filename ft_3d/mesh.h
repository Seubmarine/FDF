/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 06:21:27 by tbousque          #+#    #+#             */
/*   Updated: 2022/05/24 19:19:17 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESH_H
# define MESH_H
# include <stddef.h>
# include <stdlib.h>
# include "matrix.h"
# include "vec3d.h"

typedef struct s_edge
{
	size_t e[2];
}	t_edge;

typedef struct s_mesh
{
	size_t		edges_size;
	size_t		vertices_size;	
	t_edge		*edges;
	t_vec3d		*vertices;
	t_vec3d		*vertices_projected;
}	t_mesh;

typedef struct s_object3d
{
	t_mat4x4 transform;
	t_mesh mesh;
}	t_object3d;


t_mesh	*mesh_init(size_t vertices_size, t_vec3d *vertices, size_t edges_size, t_edge *edges);
#endif