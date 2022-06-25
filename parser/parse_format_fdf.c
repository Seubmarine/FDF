/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format_fdf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 02:43:43 by tbousque          #+#    #+#             */
/*   Updated: 2022/06/25 21:29:52 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	get_lines_word_count(char **lines, size_t *word_per_line,
	size_t *line_count)
{
	size_t	last_line_i;

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
	return (1);
}

void	parse_vertices(char **lines, t_vec3d *vertices)
{
	char		*line;
	size_t		i;
	t_vec2di	v;

	i = 0;
	v.y = 0;
	while (*lines)
	{
		line = *lines;
		v.x = 0;
		while (*line)
		{
			vertices[i].z = (float) ft_strtoll(line, &line, 10);
			while (*line && *line != ' ')
				line++;
			while (*line && *line == ' ')
				line++;
			vertices[i].x = (float) v.x;
			v.x++;
			vertices[i].y = (float) v.y;
			i++;
		}
		v.y++;
		lines++;
	}
}

static void	parse_egdes_helper(t_edge *edges, size_t num_per_line, \
	size_t line_count)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < line_count)
	{
		x = 0;
		while (x < num_per_line - 1)
		{
			edges->e[0] = x + (y * num_per_line);
			edges->e[1] = x + (y * num_per_line) + 1;
			edges++;
			x++;
		}
		y++;
	}
}

void	parse_edges_fdf(t_edge *edges, size_t num_per_line, size_t line_count)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < num_per_line)
	{
		y = 0;
		while (y < line_count - 1)
		{
			edges->e[0] = x + (y * num_per_line);
			edges->e[1] = x + ((y + 1) * num_per_line);
			edges++;
			y++;
		}
		x++;
	}
	parse_egdes_helper(edges, num_per_line, line_count);
}

t_mesh	*parse_format_fdf(char **lines)
{
	t_format_fdf_helper	t;

	if (!get_lines_word_count(lines, &t.word_per_line, &t.line_count))
		return (NULL);
	t.vertices_size = t.line_count * t.word_per_line;
	t.vertices = malloc(sizeof(*t.vertices) * t.vertices_size);
	if (t.vertices == NULL)
		return (NULL);
	t.edges_size = (((t.word_per_line - 1) * t.line_count) + \
		((t.line_count - 1) * t.word_per_line));
	t.edges = malloc(sizeof(*t.edges) * t.edges_size);
	if (t.edges == NULL)
	{
		free(t.vertices);
		return (NULL);
	}
	ft_memset(t.edges, 0, sizeof(*t.edges) * t.edges_size);
	parse_vertices(lines, t.vertices);
	parse_edges_fdf(t.edges, t.word_per_line, t.line_count);
	t.mesh = mesh_init(t.vertices_size, t.vertices, t.edges_size, t.edges);
	if (t.mesh == NULL)
		return (NULL);
	free(t.vertices);
	free(t.edges);
	return (t.mesh);
}
