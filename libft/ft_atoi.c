/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:31:32 by tbousque          #+#    #+#             */
/*   Updated: 2021/10/30 22:35:49 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	number;
	int	sign;

	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	number = 0;
	while (*nptr && ft_isdigit(*nptr))
		number = (number * 10) + (*nptr++ - 48);
	number *= sign;
	if (sign == 1 && number < 0)
		return (-1);
	else if (sign == -1 && number > 0)
		return (0);
	return (number);
}
