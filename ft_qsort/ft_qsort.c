/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 22:34:46 by tbousque          #+#    #+#             */
/*   Updated: 2022/06/23 00:40:47 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_qsort.h"

void	qswap(void *v, size_t left, size_t right, size_t type_size)
{
	char	tmp;
	char	*a;
	char	*b;
	size_t	i;

	a = (char *)v + left * type_size;
	b = (char *)v + right * type_size;
	i = 0;
	while (i < type_size)
	{
		tmp = a[i];
		a[i] = b[i];
		b[i] = tmp;
		i++;
	}
}

void	_ft_qsort(void *v, size_t left, size_t right, struct s_qsort_args args)
{
	size_t	i;
	size_t	last;

	if (left >= right)
		return ;
	qswap(v, left, (left + right) / 2, args.type_size);
	last = left;
	i = left + 1;
	while (i <= right)
	{
		if (args.compar((char *)v + i * args.type_size, \
			(char *)v + left * args.type_size) < 0)
			qswap(v, ++last, i, args.type_size);
		i++;
	}
	qswap(v, left, last, args.type_size);
	if (last - 1 < last)
		_ft_qsort(v, left, last - 1, args);
	if (last + 1 > last)
		_ft_qsort(v, last + 1, right, args);
}

void	ft_qsort(void *base, size_t nmemb, size_t size,
			int (*compar)(const void *, const void *))
{
	struct s_qsort_args	args;

	args.type_size = size;
	args.compar = compar;
	_ft_qsort(base, 0, nmemb - 1, args);
}
