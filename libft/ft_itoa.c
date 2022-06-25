/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 02:39:38 by tbousque          #+#    #+#             */
/*   Updated: 2022/01/28 09:36:55 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_itoa(int n)
{
	long	n_long;
	char	temp_str[12];
	char	*result;

	n_long = n;
	temp_str[0] = '-';
	if (n_long < 0)
		ft_snullbase(temp_str + 1, 11, -n_long, "0123456789");
	else
		ft_snullbase(temp_str, 12, n_long, "0123456789");
	result = ft_strdup(temp_str);
	return (result);
}
