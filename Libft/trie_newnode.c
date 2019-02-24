/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_newnode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 11:38:12 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/23 15:59:43 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_trie		*trie_newnode(void)
{
	t_trie			*new_node;
	unsigned int	i;

	if (!(new_node = malloc(sizeof(t_trie))))
		return (NULL);
	new_node->item = NULL;
	i = 0;
	while (i < SIZE_OF_ARRAY)
		(new_node->children)[i++] = NULL;
	return (new_node);
}
