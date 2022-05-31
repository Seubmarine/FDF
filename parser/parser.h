/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 02:27:10 by tbousque          #+#    #+#             */
/*   Updated: 2022/05/31 03:07:31 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  4096
# endif
# include <stddef.h>
# include <fcntl.h>
# include "libft.h"
# include "mesh.h"
# include <stdio.h>

char	**get_lines_of_file(char *str);
char	*get_file_str(char *path);
t_mesh	*parse_format_obj(char **lines);
t_mesh	*parse_file_to_mesh(char *filename);
#endif
