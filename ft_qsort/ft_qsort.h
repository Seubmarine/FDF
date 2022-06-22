/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:50:47 by tbousque          #+#    #+#             */
/*   Updated: 2022/06/22 23:08:58 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QSORT_H
# define FT_QSORT_H

# include "stddef.h"
# include "stdint.h"

struct s_qsort_args
{
	size_t	type_size;
	int		(*compar)(const void *, const void *);
};

void	ft_qsort(void *base, size_t nmemb, size_t size,
			int (*compar)(const void *, const void *));

#endif