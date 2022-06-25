/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:06:28 by tbousque          #+#    #+#             */
/*   Updated: 2022/01/20 08:46:09 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4194304
# endif

char	*get_next_line(int fd);
#endif
