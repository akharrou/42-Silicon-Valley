/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 11:37:44 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/23 15:59:43 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		trie_clear(t_trie **root)
{
	unsigned int i;

	if (root && *root)
	{
		i = 0;
		while (i < SIZE_OF_ARRAY)
		{
			if (((*root)->children)[i])
				if ((trie_clear(&(((*root)->children)[i]))) == -1)
					return (-1);
			i++;
		}
		if ((*root)->item)
		{
			free((*root)->item);
			(*root)->item = NULL;
		}
		free(*root);
		(*root) = NULL;
		return (0);
	}
	return (-1);
}
