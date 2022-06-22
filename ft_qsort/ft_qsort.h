/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:50:47 by tbousque          #+#    #+#             */
/*   Updated: 2022/06/22 19:08:36 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QSORT_H
# define FT_QSORT_H

# include "stdio.h" //TO REMOVE
# include "stddef.h"

static struct s_qsort_args
{
	size_t	right;
	size_t	left;
	int		(*compar)(const void *, const void *);
};

void	ft_qsort(void *base, size_t nmemb, size_t size,
			int (*compar)(const void *, const void *));

#endif