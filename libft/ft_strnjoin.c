/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 23:38:10 by tbousque          #+#    #+#             */
/*   Updated: 2022/01/20 07:41:01 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//need length of the two string
char	*ft_strnjoin(char const *s1, char const *s2, size_t s1len, size_t s2len)
{
	size_t	i;
	char	*str;

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
