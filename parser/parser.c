/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 04:18:57 by tbousque          #+#    #+#             */
/*   Updated: 2022/05/31 06:56:22 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

enum e_file_format
{
	format_unsuported,
	format_fdf,
	format_obj,
};

enum e_file_format	get_file_format(char *filename)
{
	const size_t	len = ft_strlen(filename);
	char			*begin_format;

	if (len <= 4)
		return (format_unsuported);
	begin_format = &filename[len - 4];
	if (!ft_strncmp(begin_format, ".fdf", 4))
		return (format_fdf);
	else if (!ft_strncmp(begin_format, ".obj", 4))
		return (format_obj);
	return (format_unsuported);
}

char	**get_file_lines(char *filename)
{
	char	*m_file;
	char	**lines;

	m_file = get_file_str(filename);
	if (m_file == NULL)
	{
		printf("Error opening file\n");
		return (NULL);
	}
	lines = get_lines_of_file(m_file);
	if (!lines)
	{
		free(m_file);
		printf("Error when transforming files in lines");
		return (NULL);
	}
	return (lines);
}

size_t	str_count_word(char *str)
{
	size_t	word_count;
	size_t	i;

	word_count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			word_count++;
			while (str[i] != '\0' && str[i] != ' ')
				i++;
		}
		else
			i++;
	}
	return (word_count);
}

t_mesh	*parse_file_to_mesh(char *filename)
{
	t_mesh				*mesh;
	char				**lines;
	enum e_file_format	format;

	mesh = NULL;
	format = get_file_format(filename);
	if (format == format_unsuported)
	{
		printf("File %s is not .fdf or .obj\n", filename);
		return (NULL);
	}
	lines = get_file_lines(filename);
	if (lines == NULL)
		return (NULL);
	if (format == format_obj)
		mesh = parse_format_obj(lines);
	free(*lines);
	free(lines);
	return (mesh);
}
