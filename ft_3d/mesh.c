/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 06:39:08 by tbousque          #+#    #+#             */
/*   Updated: 2022/05/24 06:39:20 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh.h"
#include "string.h"
#include <stdio.h>

t_mesh	*mesh_init(size_t vertices_size, t_vec3d *vertices, size_t edges_size, t_edge *edges)
{
	t_mesh	*mesh;
	const size_t m_byte = sizeof(*mesh);
	const size_t v_byte = sizeof(*mesh->vertices) * vertices_size * 2;
	const size_t e_byte = sizeof(*mesh->edges) * edges_size;
	const size_t t_byte = m_byte + v_byte + e_byte;

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

void debug_mesh(t_mesh m)
{
	printf("edges:\n");
	for(size_t i = 0; i < m.edges_size; i++)
	{
		t_edge e = m.edges[i];
		printf("{%lu, %lu}, ", e.e[0], e.e[1]);
	}
	printf("\nvertices:\n");
	for(size_t i = 0; i < m.vertices_size; i++)
	{
		t_vec3d v = m.vertices[i];
		printf("{%.0f, %.0f, %.0f}, ", v.x, v.y, v.z);
	}
	printf("\n");
}


int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	t_vec3d cubev[] = {
		{0, 0, 0},
		{0, 1, 0},
		{1, 1, 0},
		{1, 0, 0},
		{0, 0, 1},
		{0, 1, 1},
		{1, 1, 1},
		{1, 0, 1}
	};

	t_edge cubee[] = {
		{{0, 1}},
		{{1, 2}},
		{{2, 3}},
		{{3, 0}},
		{{4, 5}},
		{{5, 6}},
		{{6, 7}},
		{{7, 4}},

		{{0, 4}},
		{{1, 5}},
		{{2, 6}},
		{{3, 7}},
	};

	t_mesh *mesh = mesh_init(8, cubev, 12, cubee);
	//printf("mesh: %p\n\tedges: %p\n\tvertices: %p\n", mesh, mesh->edges, mesh->vertices);
	//debug_mesh(*mesh);
	free(mesh);
}
