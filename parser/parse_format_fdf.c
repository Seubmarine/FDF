/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format_fdf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 02:43:43 by tbousque          #+#    #+#             */
/*   Updated: 2022/06/04 09:40:31 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int get_lines_word_count(char **lines, size_t *word_per_line, size_t *line_count)
{
	size_t last_line_i;

	last_line_i = 0;
	while (lines[last_line_i])
		last_line_i++;
	if (last_line_i == 0)
		return (0);
	if (str_count_word(lines[--last_line_i]) == 0)
		lines[last_line_i] = NULL;
	if (lines == NULL)
		return (0);
	*line_count = 0;
	*word_per_line = str_count_word(lines[*line_count]);
	while (lines[*line_count])
	{
		if (*word_per_line != str_count_word(lines[*line_count]))
			return (0);
		(*line_count)++;
	}
	//(*line_count)++;
	return (1);
}

void	parse_vertices(char **lines, t_vec3d *vertices, size_t vertices_size)
{
	(void) vertices_size;
	char *line;
	size_t i;
	size_t x;
	size_t y;

	i = 0;
	y = 0;
	while (*lines)
	{
		line = *lines;
		x = 0;
		while (*line)
		{
			vertices[i].z = (float) ft_strtoll(line, &line, 10);
			while (*line && *line != ' ')
				line++;
			while (*line && *line == ' ')
				line++;
			vertices[i].x = (float) x;
			x++;
			vertices[i].y = (float) y;
			i++;
		}
		y++;
		lines++;
	}
}

void	parse_edges_fdf(t_edge *edges, size_t num_per_line, size_t line_count)
{
	size_t x;
	size_t y;

	y = 0;
	while (y < line_count)
	{
		x = 0;
		while (x < num_per_line - 1)
		{
			(*edges).e[0] = x + (y * num_per_line);
			(*edges).e[1] = x + (y * num_per_line) + 1;
			edges++;
			if (y < line_count - 1)
			{
				(*edges).e[0] = x + (y * num_per_line);
				(*edges).e[1] = ((y + 1) * num_per_line) + x;
				edges++;
				if (!(x + 1 < num_per_line - 1))
				{
					(*edges).e[0] = ++x + (y * num_per_line);
					(*edges).e[1] = ((y + 1) * num_per_line) + x;
					edges++;
				}
			}	
			x++;
		}
		y++;
	}
}

t_mesh	*parse_format_fdf(char **lines)
{
	size_t word_per_line;
	size_t line_count;
	t_edge *edges;
	t_vec3d *vertices;
	t_mesh *mesh;
	// word_per_line = 0;
	// line_count = 0;
	if(!get_lines_word_count(lines, &word_per_line, &line_count))
		return (NULL);
	size_t vertices_size = line_count * word_per_line;
	vertices = malloc(sizeof(*vertices) * vertices_size);
	if (vertices == NULL)
		return (NULL);
	size_t edges_size = (((word_per_line - 1) * line_count) + ((line_count - 1) * word_per_line));
	edges = malloc(sizeof(*edges) * edges_size);
	if (edges == NULL)
	{
		free(vertices);
		return (NULL);
	}
	ft_memset(edges, 0, sizeof(*edges) * edges_size);
	parse_vertices(lines, vertices, vertices_size);
	parse_edges_fdf(edges, word_per_line, line_count);
	mesh = mesh_init(vertices_size, vertices, edges_size, edges);
	if (mesh == NULL)
		return (NULL);
	free(vertices);
	free(edges);
	return (mesh);
}

	// size_t x = word_per_line;
	// size_t y = line_count;
	// printf("edges size = %lu", ((x-1) * y) + ((y - 1) * x));

// 4*3  ((4-1) * 3) + ((3 - 1) * 4) 
// x*y  ((x-1) * y) + ((y - 1) * x) 

// 1 - 1 - 1 - 1
// -   -   -   -
// 1 - 1 - 1 - 1
// -   -   -   -
// 1 - 1 - 1 - 1