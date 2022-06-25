/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snullbase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 01:02:21 by tbousque          #+#    #+#             */
/*   Updated: 2022/01/28 09:36:39 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//put a number in dest, dest_size is size including '\0', radix is size of base
//ex: dest[7]; ft_snullbase(dest, 7, 42, "01", 2); dest == "101010"
//if the number in string is bigger than dest_size - 1 it will be truncated
//ex: dest[4]; ft_snullbase(dest, 4, 42, "01", 2); dest == "101"
//return number of digits it putted in dest
int	ft_snullbase(char *dest, size_t dest_size, unsigned long long n,
	const char *base)
{
	char	temp_array[64];
	int		len;
	size_t	i;
	int		radix;

	if (!dest || !base || dest_size == 0)
		return (-1);
	radix = ft_strlen(base);
	if (radix < 2)
		return (-1);
	len = (n == 0);
	if (n == 0)
		temp_array[0] = base[0];
	while (n)
	{
		temp_array[len++] = base[n % radix];
		n /= radix;
	}
	i = 0;
	while (i < dest_size - 1 && len)
		dest[i++] = temp_array[len-- - 1];
	dest[i] = '\0';
	return (i);
}
