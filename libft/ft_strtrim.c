/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 01:58:05 by tbousque          #+#    #+#             */
/*   Updated: 2021/11/05 19:06:46 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*trimedstr;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	while (ft_isset(s1[i], set) && s1[i])
		i++;
	if (!s1[i])
	{
		trimedstr = malloc(sizeof(char));
		trimedstr[0] = '\0';
		return (trimedstr);
	}
	start = i;
	i = ft_strlen(s1) - 1;
	while (ft_isset(s1[i], set) && (i > 0))
		i--;
	end = i;
	trimedstr = ft_substr(s1, start, end - start + 1);
	return (trimedstr);
}
