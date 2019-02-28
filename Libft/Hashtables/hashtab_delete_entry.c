/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_delete_entry.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:33:09 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/27 16:44:47 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void			entry_free__(t_entry **entry)
{
	if (entry && *entry)
	{
		if ((*entry)->key)
			free((*entry)->key);
		if ((*entry)->value)
			free((*entry)->value);
		free(*entry);
		(*entry) = NULL;
	}
}

int					hashtab_delete_entry(t_hashtable **table, char *key)
{
	t_entry			*prev_entry;
	t_entry			*cur_entry;
	unsigned int	index;

	if (table && key)
	{
		index = HASHCODE(key, (*table)->num_buckets);
		cur_entry = ((*table)->bucket_list)[index];
		while (cur_entry)
		{
			if (ft_strcmp(cur_entry->key, key) == 0)
			{
				if (cur_entry == ((*table)->bucket_list)[index])
					((*table)->bucket_list)[index] = cur_entry->next;
				else
					prev_entry->next = cur_entry->next;
				entry_free__(&cur_entry);
				(*table)->entries -= 1;
				return (0);
			}
			prev_entry = cur_entry;
			cur_entry = cur_entry->next;
		}
	}
	return (-1);
}
