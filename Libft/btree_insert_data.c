/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:05:04 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/21 21:05:10 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_insert_data(t_btree **root, void *item,
	int (*cmpf)(void *, void *))
{
	t_btree *probe;

	if (!root || !(*root))
	{
		if (root)
			(*root) = btree_create_node(item);
		return ;
	}
	probe = (*root);
	if ((*cmpf)(item, probe->item) < 0)
	{
		if (probe->left)
			btree_insert_data(&(probe->left), item, cmpf);
		else
			probe->left = btree_create_node(item);
	}
	else
	{
		if (probe->right)
			btree_insert_data(&(probe->right), item, cmpf);
		else
			probe->right = btree_create_node(item);
	}
}
