/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:53:04 by tbousque          #+#    #+#             */
/*   Updated: 2021/11/23 16:42:18 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	dst_end_index;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	dst_end_index = dst_len;
	if (dst_len >= size)
		return (src_len + size);
	while (dst_end_index < size - 1 && *src)
	{
		dst[dst_end_index] = *src++;
		dst_end_index++;
	}
	dst[dst_end_index] = '\0';
	return (src_len + dst_len);
}
