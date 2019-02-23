/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:02:37 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/21 21:03:18 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_btree		*btree_create_node(void *item)
{
	t_btree *new_node;

	if (!(new_node = malloc(sizeof(t_btree))))
		return (NULL);
	new_node->item = item;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}
