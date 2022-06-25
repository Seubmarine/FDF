/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 02:27:10 by tbousque          #+#    #+#             */
/*   Updated: 2022/06/23 00:50:27 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4194304
# endif
# include <stddef.h>
# include <fcntl.h>
# include "libft.h"
# include "mesh.h"
# include "del_dup_edges.h"

typedef struct s_format_fdf_helper
{
	size_t	word_per_line;
	size_t	line_count;
	t_edge	*edges;
	size_t	edges_size;
	t_vec3d	*vertices;
	size_t	vertices_size;
	t_mesh	*mesh;
}	t_format_fdf_helper;


char	**get_lines_of_file(char *str);
char	*get_file_str(char *path);
size_t	str_count_word(char *str);
t_mesh	*parse_format_obj(char **lines);
t_mesh	*parse_format_fdf(char **lines);
t_mesh	*parse_file_to_mesh(char *filename);
#endif
