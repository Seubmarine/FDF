/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 02:06:56 by tbousque          #+#    #+#             */
/*   Updated: 2021/11/05 19:04:47 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*first_in_list;

	(void) (*del);
	if (!lst || !f)
		return (NULL);
	new_list = ft_lstnew((*f)(lst->content));
	first_in_list = new_list;
	lst = lst->next;
	while (lst)
	{
		new_list->next = ft_lstnew((*f)(lst->content));
		new_list = new_list->next;
		lst = lst->next;
	}
	return (first_in_list);
}
