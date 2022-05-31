/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 02:51:14 by tbousque          #+#    #+#             */
/*   Updated: 2022/05/31 02:59:57 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*strnappend(char **dest, size_t dest_len,
	char *append, size_t appendlen)
{
	char	*temp;

	temp = ft_strnjoin(*dest, append, dest_len, appendlen);
	if (*dest)
		free(*dest);
	*dest = temp;
	return (temp);
}

char	*get_file_str(char *path)
{
	char	*buf;
	char	*str;
	int		fd;
	ssize_t	n_read;
	ssize_t	total_read;

	str = NULL;
	total_read = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	buf = malloc(sizeof(char) * BUFFER_SIZE);
	if (buf == NULL)
		return (NULL);
	while (1)
	{
		n_read = read(fd, buf, BUFFER_SIZE);
		if (n_read == 0)
			break ;
		strnappend(&str, total_read, buf, n_read);
		total_read += n_read;
	}
	free(buf);
	close(fd);
	return (str);
}

size_t	file_count_row(char *str)
{
	size_t	i;
	size_t	row;

	i = 0;
	row = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			row++;
		i++;
	}
	return (row);
}

char	**get_lines_of_file(char *str)
{
	char	**line;
	size_t	i;
	size_t	line_index;
	size_t	row;

	row = file_count_row(str);
	i = 0;
	line_index = 0;
	line = malloc(sizeof(*line) * (row + 1));
	if (!line)
		return (NULL);
	line[line_index++] = &str[i++];
	while (line_index < row && str[i])
	{
		if (str[i] == '\n')
		{
			str[i++] = '\0';
			line[line_index++] = &str[i];
		}
		else
			i++;
	}
	line[line_index] = NULL;
	return (line);
}
