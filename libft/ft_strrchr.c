/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 07:33:53 by tbousque          #+#    #+#             */
/*   Updated: 2021/10/15 01:20:42 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = NULL;
	if (*s == (unsigned char)c)
		ptr = (char *)s;
	while (*s++)
	{
		if (*s == (unsigned char)c)
			ptr = (char *)s;
	}
	return (ptr);
}
