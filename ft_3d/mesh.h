/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 06:21:27 by tbousque          #+#    #+#             */
/*   Updated: 2022/05/26 05:36:55 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESH_H
# define MESH_H
# include <stddef.h>
# include <stdlib.h>
# include "matrix.h"
# include "vec3d.h"
# include "mlx_image.h"

typedef struct s_edge
{
	size_t e[2];
}	t_edge;

typedef struct s_mesh
{
	t_mat4x4 transform;
	size_t		edges_size;
	size_t		vertices_size;	
	t_edge		*edges;
	t_vec3d		*vertices;
	t_vec3d		*vertices_projected;
}	t_mesh;

t_mesh	*mesh_init(size_t vertices_size, t_vec3d *vertices, size_t edges_size, t_edge *edges);
t_mesh	*mesh_init_cube(void);
void	mesh_draw(t_mesh *mesh, t_img img, t_mat4x4 proj);
#endif