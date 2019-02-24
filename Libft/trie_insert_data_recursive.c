/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_insert_data_recursive.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 11:38:47 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/23 18:58:20 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			trie_insert_recursive(t_trie **root, char *hash,
				void *item, unsigned int (*char_to_index)(char c))
{
	unsigned int index;

	if (root && *root && hash)
	{
		if (*hash != '\0')
		{
			index = char_to_index(*hash);
			if (((*root)->children)[index] == NULL)
				((*root)->children)[index] = trie_newnode();
			trie_insert_recursive(
				(&((*root)->children)[index]), hash + 1, item, char_to_index);
		}
		else
			(*root)->item = item;
	}
}
