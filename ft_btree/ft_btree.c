/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:12:58 by tbousque          #+#    #+#             */
/*   Updated: 2022/06/03 23:07:22 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->item = item;
	new->left = NULL;
	new->right = NULL;
	return new;
}

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	applyf(root->item);
	if (root->left)
		btree_apply_prefix(root->left, applyf);
	if (root->right)
		btree_apply_prefix(root->right, applyf);
}

void	btree_apply_sufix(t_btree *root, void (*applyf)(void *))
{
	if (root->left)
		btree_apply_sufix(root->left, applyf);
	if (root->right)
		btree_apply_sufix(root->right, applyf);
	applyf(root->item);
}

void	btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (root->left)
		btree_apply_infix(root->left, applyf);
	applyf(root->item);
	if (root->right)
		btree_apply_infix(root->right, applyf);
}

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	if (!*root)
	{
		*root = btree_create_node(item);
		return ;
	}
	if (cmpf(item, (*root)->item) < 0)
		btree_insert_data(&(*root)->left, item, cmpf);
	else
		btree_insert_data(&(*root)->right, item, cmpf);
}

//cmpf return -1 to go to the left, 1 to the right and 0 if equal
t_btree *btree_search_node(t_btree *root, void *data_ref, int (*cmpf)(void *, void *))
{
	t_btree	*target;
	int		comparaison;

	target = NULL;
	comparaison = cmpf(data_ref, root->item);
	if (root->left && comparaison < 0)
		target = btree_search_node(root->left, data_ref, cmpf);
	else if (root->right && comparaison > 0)
		target = btree_search_node(root->right, data_ref, cmpf);
	else if (comparaison == 0)
		target = root;
	return (target);
}

void	btree_free(t_btree *root)
{
	if (root == NULL)
		return ;
	btree_free(root->left);
	btree_free(root->right);
	free(root);
}