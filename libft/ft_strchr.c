/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 07:16:20 by tbousque          #+#    #+#             */
/*   Updated: 2021/10/15 01:20:03 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{	
	if (*s == (unsigned char) c)
		return ((char *)s);
	while (*s++)
		if (*s == (unsigned char) c)
			return ((char *)s);
	return (NULL);
}
