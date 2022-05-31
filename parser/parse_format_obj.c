/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format_obj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 22:15:14 by tbousque          #+#    #+#             */
/*   Updated: 2022/05/31 17:37:36 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

size_t	count_line_begin_with(char	**lines, const char *cmp, size_t cmp_size)
{
	size_t	i;
	size_t	count;
	char	*line;

	count = 0;
	i = 0;
	while (lines[i])
	{
		line = lines[i];
		if (!ft_strncmp(line, cmp, cmp_size))
			count++;
		i++;
	}
	return (count);
}

//WARNING: CHANGE TO OWN STRTOF IMPLEMENTATION
static void	parse_vertices(char **lines, t_vec3d *vertices)
{
	char	*line;
	size_t	i;

	i = 0;
	while (*lines)
	{
		if (ft_strncmp(*lines, "v ", 2) == 0)
		{
			line = *lines + 1;
			vertices[i].x = strtof(line, &line);
			vertices[i].y = strtof(line, &line);
			vertices[i].z = strtof(line, &line);
			i++;
		}
		lines++;
	}
}

size_t	count_edges(char **lines)
{
	size_t	edge_count;

	edge_count = 0;
	while (*lines)
	{
		if (ft_strncmp(*lines, "f ", 2) == 0)
			edge_count += str_count_word(*lines + 1) + 1;
		lines++;
	}
	return (edge_count);
}

t_edge	*parse_edges(char **lines, t_edge *edges)
{
	char	*line;
	size_t	e_index;
	size_t	*first_vertex_index;

	e_index = 0;
	while (*lines)
	{
		if (ft_strncmp(*lines, "f ", 2) == 0)
		{
			line = *lines + 1;
			first_vertex_index = &(edges[e_index].e[0]);
			while (line && *line)
			{
				edges[e_index].e[0] = ft_strtoll(line, &line, 10) - 1;
				line = ft_strchr(line, ' ');
				if (line != NULL)
				{
					edges[e_index].e[1] = ft_strtoll(line, NULL, 10) - 1;
					while (*line != '\0' && *line == ' ')
						line++;
				}
				e_index++;
			}
			edges[e_index - 1].e[1] = *first_vertex_index;
		}
		lines++;
	}
	return (edges);
}

t_mesh	*parse_format_obj(char **lines)
{
	const size_t	vertices_size = count_line_begin_with(lines, "v ", 2);
	t_vec3d			*vertices;
	const size_t	edges_size = count_edges(lines);
	t_edge			*edges;
	t_mesh			*mesh;

	edges = malloc(sizeof(*edges) * edges_size);
	ft_bzero(edges, sizeof(*edges) * edges_size);
	if (edges == NULL)
		return (NULL);
	vertices = malloc(sizeof(*vertices) * vertices_size);
	ft_bzero(vertices, sizeof(*vertices) * vertices_size);
	if (vertices == NULL)
	{
		free(edges);
		return (NULL);
	}
	parse_edges(lines, edges);
	parse_vertices(lines, vertices);
	mesh = mesh_init(vertices_size, vertices, edges_size, edges);
	free(vertices);
	free(edges);
	return (mesh);
}
