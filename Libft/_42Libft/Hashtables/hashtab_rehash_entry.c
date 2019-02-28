/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_rehash_entry.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:37:12 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/27 16:44:47 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int				hashtab_rehash_entry(t_hashtable **table_to, t_entry **entry)
{
	unsigned int	index;

	if (table_to && *table_to && entry && *entry)
	{
		index = HASHCODE((*entry)->key, (*table_to)->num_buckets);
		(*entry)->next = ((*table_to)->bucket_list)[index];
		((*table_to)->bucket_list)[index] = (*entry);
		(*table_to)->entries += 1;
		return (0);
	}
	return (-1);
}
