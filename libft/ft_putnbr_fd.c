/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:19:27 by tbousque          #+#    #+#             */
/*   Updated: 2022/01/17 02:31:36 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;
	char	c;

	nbr = n;
	if (nbr < 0)
	{
		(void)!write(fd, "-", 1);
		nbr = -nbr;
	}
	if (nbr / 10)
		ft_putnbr_fd(nbr / 10, fd);
	c = (nbr % 10) + '0';
	(void)!write(fd, &c, 1);
}
