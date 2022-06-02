/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:09:47 by tbousque          #+#    #+#             */
/*   Updated: 2022/06/02 08:29:48 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_btree.h"
// #include <stdio.h>
// void btree_print(void *item)
// {
// 	printf("%i\n", *(int *)item);
// }

// int cmp(int *i1, int *i2)
// {
// 	return (*i1 - *i2);
// }


// void main(int argc, char **argv)
// {
// 	t_btree	*mytree = NULL;
// 	int arr[] = {21, 9, 8, 42, 21, 56, 2, 7, 1, 5, 7, 4, 5};
// 	int len = sizeof(arr) / sizeof(arr[0]);
// 	int i = 0;

// 	while (i < len)
// 	{
// 		btree_insert_data(&mytree, &arr[i], (int (*) (void *, void *))&cmp);
// 		i++;
// 	}
// 	btree_apply_infix(mytree, &btree_print);
// 	int x = 0;
// 	while (x < 100)
// 	{
// 		t_btree *target = btree_search_node(mytree, &x,(int (*)(void *, void *)) cmp);
// 		if (target)
// 			printf("we found %i\n", *(int *)target->item);
// 		x++;
// 	}
// }
