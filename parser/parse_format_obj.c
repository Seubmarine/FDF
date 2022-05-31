/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format_obj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 22:15:14 by tbousque          #+#    #+#             */
/*   Updated: 2022/05/31 03:13:16 by tbousque         ###   ########.fr       */
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
static void	str_to_vec3d(char *str, t_vec3d *v)
{
	v->x = strtof(str, &str);
	v->y = strtof(str, &str);
	v->z = strtof(str, &str);
}

t_mesh	*parse_format_obj(char **lines)
{
	const size_t	vertices_size = count_line_begin_with(lines, "v ", 2);
	t_vec3d			*vertices;
	t_mesh			*mesh;
	size_t			v_index;

	vertices = malloc(sizeof(*vertices) * vertices_size);
	if (vertices == NULL)
		return (NULL);
	v_index = 0;
	while (*lines)
	{
		if (ft_strncmp(*lines, "v ", 2) == 0)
			str_to_vec3d(ft_strchr(*lines, ' '), &vertices[v_index++]);
		lines++;
	}
	mesh = mesh_init(vertices_size, vertices, 0, NULL);
	free(vertices);
	return (mesh);
}
