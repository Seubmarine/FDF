/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 01:00:58 by tbousque          #+#    #+#             */
/*   Updated: 2022/01/20 06:56:03 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//false realoc, will defragment heap if used a lot.
void	*ft_realloc(void *ptr, size_t size, size_t previous_size)
{
	void	*newptr;

	if (size == 0)
	{
		if (ptr)
			free(ptr);
		return (NULL);
	}
	if (!ptr)
		return (malloc(size));
	newptr = malloc(size);
	if (newptr == NULL)
	{
		if (ptr)
			free(ptr);
		return (NULL);
	}
	if (size > previous_size)
		size = previous_size;
	if (ptr)
		ft_memcpy(newptr, ptr, size);
	free(ptr);
	return (newptr);
}
