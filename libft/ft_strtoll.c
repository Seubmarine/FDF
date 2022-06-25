/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:59:05 by tbousque          #+#    #+#             */
/*   Updated: 2022/04/30 13:44:45 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//put in dest the position of the given char in the base 
//"0123456789abcdefghijklmnpqrstuvwxyz"
//if dest is NULL the given char is not in the base
//uppercased are mapped to lowercase
static int	ft_atobase(int *dest, int c, int base_size)
{
	if (ft_isdigit(c))
	{
		*dest = c - '0';
		return (*dest < base_size);
	}
	else if (ft_islower(c))
	{
		*dest = c - 'a' + 10;
		return (*dest < base_size);
	}
	else if (ft_isupper(c))
	{
		*dest = c - 'A' + 10;
		return (*dest < base_size);
	}
	return (0);
}

long long int	ft_strtoll(const char *nptr, char **endptr, int base)
{
	int				current_in_base;
	int				sign;
	long long int	number;
	char			*has_read_num;
	const char		*nptr_copy = nptr;

	sign = 1;
	if (base < 2 || base > 36)
		return (0);
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	has_read_num = (char *)nptr;
	number = 0;
	while (ft_atobase(&current_in_base, *nptr++, base))
		number = (number * base) + current_in_base;
	if (has_read_num == --nptr)
		nptr = nptr_copy;
	if (endptr)
		*endptr = (char *)nptr;
	return (number * sign);
}
