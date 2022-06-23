/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 06:39:08 by tbousque          #+#    #+#             */
/*   Updated: 2022/06/23 23:50:59 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh.h"

t_edge	edge(size_t a, size_t b)
{
	t_edge	e;

	e.e[0] = a;
	e.e[1] = b;
	return (e);
}

t_mesh	*mesh_init(size_t vertices_size, t_vec3d *vertices,
size_t edges_size, t_edge *edges)
{
	t_mesh			*mesh;
	const size_t	m_byte = sizeof(*mesh);
	const size_t	v_byte = sizeof(*mesh->vertices) * vertices_size * 2;
	const size_t	e_byte = sizeof(*mesh->edges) * edges_size;
	const size_t	t_byte = m_byte + v_byte + e_byte;

	printf("mesh total size in byte: %lu\n", t_byte);
	printf("\tmesh size: %lu\n", m_byte);
	printf("\tedge size: %lu, byte: %lu\n", e_byte / sizeof(t_edge), e_byte);
	printf("\tvert size: %lu, byte: %lu\n", v_byte / sizeof(t_vec3d) / 2, v_byte);
	mesh = malloc(t_byte);
	ft_bzero(mesh, t_byte);
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

t_mesh	*mesh_init_cube(void)
{
	t_mesh	*mesh;

	mesh = mesh_init(8,
			(t_vec3d []){{0, 0, 0}, {0, 1, 0}, {1, 1, 0}, {1, 0, 0},
		{0, 0, 1}, {0, 1, 1}, {1, 1, 1}, {1, 0, 1}},
			12,
			(t_edge []){
		{{0, 1}}, {{1, 2}}, {{2, 3}}, {{3, 0}}, {{4, 5}}, {{5, 6}},
		{{6, 7}}, {{7, 4}}, {{0, 4}}, {{1, 5}}, {{2, 6}}, {{3, 7}}
		});
	return (mesh);
}

void	mesh_project(t_mesh *mesh, t_img img, t_mat4x4 proj)
{
	size_t	i;
	t_vec3d	vertex;

	i = 0;
	while (i < mesh->vertices_size)
	{
		vertex = mesh->vertices[i];
		vertex = vec3d_projected(vertex, proj);
		vertex.x += 1.0f;
		vertex.y += 1.0f;
		vertex.x *= 0.5f * img.x;
		vertex.y *= 0.5f * img.y;
		mesh->vertices_projected[i] = vertex;
		i++;
	}
}

void	mesh_draw(t_mesh *mesh, t_img img)
{
	size_t	i;
	t_edge	current_edge;
	t_vec3d	v1;
	t_vec3d	v2;

	i = 0;
	while (i < mesh->edges_size)
	{
		current_edge = mesh->edges[i];
		v1 = mesh->vertices_projected[current_edge.e[0]];
		v2 = mesh->vertices_projected[current_edge.e[1]];
		if (!((v1.x < 0 || v1.x > img.x) || (v1.y < 0 || v1.y > img.y) || \
			(v2.x < 0 || v2.x > img.x) || (v2.y < 0 || v2.y > img.y) \
			|| (v1.z > 1.0 || v2.z > 1.0)))
			image_draw_line(img, v1.x, v1.y, v2.x, v2.y, 0xFF45b566);
		i++;
	}
}
