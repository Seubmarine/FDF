/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format_fdf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 02:43:43 by tbousque          #+#    #+#             */
/*   Updated: 2022/06/04 07:43:34 by tbousque         ###   ########.fr       */
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
	*word_per_line = str_count_word(lines[*word_per_line]);
	while (lines[*line_count])
	{
		if (*word_per_line != str_count_word(lines[*line_count]))
			return (0);
		(*line_count)++;
	}
	//(*line_count)++;
	return (1);
}

t_mesh	*parse_format_fdf(char **lines)
{
	size_t word_per_line;
	size_t line_count;

	word_per_line = 0;
	line_count = 0;
	int r = get_lines_word_count(lines, &word_per_line, &line_count);
	printf(".fdf= ln:%lu wpl:%lu r:%d\n", line_count, word_per_line, r);
	// const size_t	vertices_size;
	// t_vec3d			*vertices;
	// size_t			edges_size;
	// t_edge			*edges;
	// t_mesh			*mesh;

	// edges_size = count_edges(lines);
	// edges = malloc(sizeof(*edges) * edges_size);
	// ft_bzero(edges, sizeof(*edges) * edges_size);
	// if (edges == NULL)
	// 	return (NULL);
	// vertices = malloc(sizeof(*vertices) * vertices_size);
	// ft_bzero(vertices, sizeof(*vertices) * vertices_size);
	// if (vertices == NULL)
	// {
	// 	free(edges);
	// 	return (NULL);
	// }
	// parse_vertices(lines, vertices);
	// parse_edges(lines, edges);
	// mesh = mesh_init(vertices_size, vertices, edges_size, edges);
	// free(vertices);
	// free(edges);
	return (NULL);
}