/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_array.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 01:59:18 by tbousque          #+#    #+#             */
/*   Updated: 2022/06/02 03:02:37 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIT_ARRAY_H
# define BIT_ARRAY_H
# include <stddef.h>
# include <string.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
typedef struct s_bit_array
{
	char *ptr;
	size_t real_size;
	size_t bit_size;
} t_bit_array;

size_t		hash(size_t a, size_t b);
t_bit_array	bit_array_init(size_t size);
void		bit_array_insert(t_bit_array arr, size_t index, bool value);
bool		bit_array_get(t_bit_array arr, size_t index);
#endif