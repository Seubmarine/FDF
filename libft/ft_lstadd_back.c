/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 21:20:34 by tbousque          #+#    #+#             */
/*   Updated: 2021/10/30 22:38:24 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//NEED TESTING
void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*l;

	if (!alst)
	{
		alst = &new;
		return ;
	}
	l = ft_lstlast(*alst);
	if (!l)
	{
		*alst = new;
		return ;
	}
	l->next = new;
}
