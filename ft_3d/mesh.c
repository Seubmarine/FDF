/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 06:39:08 by tbousque          #+#    #+#             */
/*   Updated: 2022/05/26 19:37:00 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh.h"
#include "string.h"
#include <stdio.h>

t_mesh	*mesh_init(size_t vertices_size, t_vec3d *vertices,
size_t edges_size, t_edge *edges)
{
	t_mesh	*mesh;
	const size_t	m_byte = sizeof(*mesh);
	const size_t	v_byte = sizeof(*mesh->vertices) * vertices_size * 2;
	const size_t	e_byte = sizeof(*mesh->edges) * edges_size;
	const size_t	t_byte = m_byte + v_byte + e_byte;

	printf("mesh total size in byte: %lu\n", t_byte);
	printf("\tmesh size: %lu\n", m_byte);
	printf("\tedge size: %lu\n", e_byte);
	printf("\tvert size: %lu\n", v_byte);
	mesh = malloc(t_byte);
	if (!mesh)
		return (NULL);
	mesh->vertices_size = vertices_size;
	mesh->edges_size = edges_size;
	mesh->edges = (t_edge *)((char *)mesh + sizeof(*mesh));
	mesh->vertices = (t_vec3d *)(&mesh->edges[edges_size]);
	mesh->vertices_projected = (t_vec3d *)(&mesh->vertices[vertices_size]);
	memcpy(mesh->edges, edges, sizeof(*edges) * edges_size);
	memcpy(mesh->vertices, vertices, sizeof(*vertices) * vertices_size);
	return (mesh);
}

// void	debug_mesh(t_mesh m)
// {
// 	printf("edges:\n");
// 	for (size_t i = 0; i < m.edges_size; i++)
// 	{
// 		t_edge e = m.edges[i];
// 		printf("{%lu, %lu}, ", e.e[0], e.e[1]);
// 	}
// 	printf("\nvertices:\n");
// 	for(size_t i = 0; i < m.vertices_size; i++)
// 	{
// 		t_vec3d v = m.vertices[i];
// 		printf("{%.0f, %.0f, %.0f}, ", v.x, v.y, v.z);
// 	}
// 	printf("\n");
// }

t_mesh	*mesh_init_cube(void)
{
	t_vec3d	cubev[] = {{0, 0, 0}, {0, 1, 0}, {1, 1, 0},
		{1, 0, 0}, {0, 0, 1}, {0, 1, 1}, {1, 1, 1}, {1, 0, 1}};
	t_edge	cubee[] = {{{0, 1}}, {{1, 2}}, {{2, 3}}, {{3, 0}}, {{4, 5}},
		{{5, 6}}, {{6, 7}}, {{7, 4}}, {{0, 4}}, {{1, 5}}, {{2, 6}}, {{3, 7}}};
	t_mesh	*mesh = mesh_init(8, cubev, 12, cubee);
	return (mesh);
}

void mesh_draw(t_mesh *mesh, t_img img, t_mat4x4 proj)
{
	size_t	i;
	t_vec3d	vertex;
	t_edge	current_edge;
	t_vec3d	v1;
	t_vec3d	v2;

	//mesh->transform = mat4x4_scale(10,10,10);
	//proj = mat4x4_product(mesh->transform, proj);
	//mesh->transform = scale;
	//proj = mat4x4_product(proj, mesh->transform);
	i = 0;
	while (i < mesh->vertices_size)
	{
		vertex = mesh->vertices[i];
		vertex = vec3d_projected(vertex, mesh->transform);
		vertex.z += 3.0f;
		vertex = vec3d_projected(vertex, proj);
		vertex.x += 1.0f;
		vertex.y += 1.0f;
		vertex.x *= 0.5f * 620.0f;
		vertex.y *= 0.5f * 400.0f;
		mesh->vertices_projected[i] = vertex;
		i++;
	}
	i = 0;
	while (i < mesh->edges_size)
	{
		current_edge = mesh->edges[i];
		v1 = mesh->vertices_projected[current_edge.e[0]];
		v2 = mesh->vertices_projected[current_edge.e[1]];
		image_draw_line(img, v1.x, v1.y, v2.x, v2.y);
		i++;
	}	
}
// int	main(int argc, char **argv)
// {
// 	t_mesh *mesh = mesh_init_cube();
// 	(void) argc;
// 	(void) argv;
// 	free(mesh);
// }
