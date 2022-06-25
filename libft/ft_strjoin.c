/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 23:38:10 by tbousque          #+#    #+#             */
/*   Updated: 2021/11/23 14:12:04 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1len;
	size_t	s2len;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1len + s2len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < s1len)
	{
		str[i] = s1[i];
		i++;
	}
	while (i - s1len < s2len)
	{
		str[i] = s2[i - s1len];
		i++;
	}
	str[i] = '\0';
	return (str);
}
