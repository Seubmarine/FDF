/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 04:37:34 by tbousque          #+#    #+#             */
/*   Updated: 2021/11/24 20:06:18 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*mem;
	unsigned char		byte;

	mem = s;
	byte = (unsigned char) c;
	while (n > 0)
	{
		if (*mem == byte)
			return ((void *)mem);
		mem++;
		n--;
	}
	return (NULL);
}
