/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 04:18:57 by tbousque          #+#    #+#             */
/*   Updated: 2022/04/29 17:05:13 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "get_next_line.h"
#include "fcntl.h"

char	*strnappend(char **dest, size_t dest_len, char *append, size_t appendlen)
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
	int	fd;
	ssize_t	n_read;
	ssize_t	total_read;

	str = NULL;
	total_read = 0;
	fd = open(path, O_RDONLY);
	buf = malloc(sizeof(char) * BUFFER_SIZE);
	if (fd < 0 || !buf)
		return (NULL); //error: couldn't open file
	while (1)
	{
		n_read = read(fd, buf, BUFFER_SIZE);
		if (n_read == 0)
			break ;
		strnappend(&str, total_read, buf, n_read);
		total_read += n_read;
	}
	free(buf);
	return (str);
}

size_t get_row(char *str)
{
	size_t	i;
	size_t row;

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

char	**put_file_in_line(char *str)
{
	char	**line;
	size_t	i;
	size_t	line_index;
	size_t	row;

	row = get_row(str);
	i = 0;
	line_index = 0;
	line = malloc(sizeof(*line) * (row + 1));
	if (!line)
		return (NULL);
	line[line_index] = &str[i];
	line_index++;
	while (line_index < row)
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			i++;
			line[line_index] = &str[i];
			line_index++;
		}
		i++;
	}
	line[line_index] = NULL;
	return (line);
}

size_t	get_num(char *line)
{
	size_t	i;
	size_t	num;
	
	i = 0;
	num = 0;
	while (line[i])
	{
		
		if (line[i] != ' ')
		{
			num++;
			//printf("(num++ = %li)\n", num);
			while (line[i] != ' ' && line[i])
			{
				printf("%c",line[i]);
				i++;
			}
			printf(" ");
		}
		else
			i++;
	}
	printf("\n");
	return (num);
}

typedef struct s_file_info
{	
	size_t wordcount;
	size_t newlinecount;
	size_t bytecount;
}	t_file_info;

t_file_info get_file_info(char *file)
{
	size_t i = 0;
	t_file_info file_info = {};
	
	while (file[i])
	{
		if (file[i] == '\n')
			file_info.newlinecount++;
		i++;
	}
	i = 0;
	while (file[i])
	{
		if (!ft_isspace(file[i]))
		{
			file_info.wordcount++;
			while (!ft_isspace(file[i]) && file[i])
			{
				i++;
			}
		}
		else
			i++;
	}
	file_info.bytecount = ft_strlen(file);
	return (file_info);
}

#include <string.h>
int test_parse(char *path)
{
	char	*file;
	//char	**line;
	//size_t	line_index;
	//size_t	total_number;

	file = NULL;
	file = get_file_str(path);
	if (!file)
		return (1);
	t_file_info info = get_file_info(file);
	printf("info:   nl : %li   word : %li   byte : %li", info.newlinecount, info.wordcount, info.bytecount);
	int *points = malloc(sizeof(*points) * info.wordcount);
	free(file);
	return (0);
}
