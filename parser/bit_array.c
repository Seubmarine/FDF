/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 03:30:37 by tbousque          #+#    #+#             */
/*   Updated: 2022/06/02 05:41:03 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bit_array.h"

size_t	hash(size_t a, size_t b)
{
	if (a < b)
		return (a + b * b);
	return (a * a + a + b);
}

t_bit_array bit_array_init(size_t size)
{
	t_bit_array bitarr = {};

	if (size == 0)
		return (bitarr);
	bitarr.bit_size = size;
	bitarr.real_size = size / 8 + !!(size % 8);
	bitarr.ptr = malloc(bitarr.real_size);
	if (bitarr.ptr == NULL)
	{
		bitarr.bit_size = 0;
		bitarr.real_size = 0;
		return (bitarr);
	}
	memset(bitarr.ptr, 0, bitarr.bit_size);
	return (bitarr);
}

void	bit_array_insert(t_bit_array arr, size_t index, bool value)
{
	const long real_index = index / 8;
	const long remainder = index % 8;
	arr.ptr[real_index] ^= (-(unsigned long)value ^ arr.ptr[real_index]) & (1UL << remainder);
}

bool	bit_array_get(t_bit_array arr, size_t index)
{
	const long real_index = index / 8;
	const long remainder = index % 8;
	return (arr.ptr[real_index] ^ 1 << remainder);
}

void bit_array_print(t_bit_array bitarr)
{
	size_t i;
	int bit_i;
	unsigned int current_byte;

	i = 0;
	while (i < bitarr.real_size)
	{
		current_byte = bitarr.ptr[i];
		printf("byte:%u ", current_byte);
		bit_i = 7;
		while (bit_i >= 0)
		{
			printf("%u", (unsigned) current_byte >> bit_i & 1);
			bit_i--;
		}
		printf(" ");
		i++;
	}
	printf("\n");
}
