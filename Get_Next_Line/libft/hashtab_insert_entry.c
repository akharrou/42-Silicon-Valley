/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_insert_entry.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:28:03 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/06 11:58:17 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_entry	*entry_create_(char *key, void *item)
{
	t_entry *new_entry;

	if (key && item)
	{
		if (!(new_entry = malloc(sizeof(t_entry))))
			return (NULL);
		new_entry->key = ft_strdup(key);
		new_entry->item = item;
		new_entry->next = NULL;
		return (new_entry);
	}
	return (NULL);
}

/*
** If successful, returns the index of the inserted entry; otherwise -1.
*/

int				hashtab_insert_entry(t_hashtable **table, char *key, void *item)
{
	t_entry			*entry;
	unsigned int	index;

	if (table && *table && key && item)
	{
		if (hashtab_set_appropriate_load_factor(table) == -1)
			return (-1);
		if (!(entry = entry_create_(key, item)))
			return (-1);
		index = HASHCODE(key, (*table)->num_buckets);
		entry->next = ((*table)->bucket_list)[index];
		((*table)->bucket_list)[index] = entry;
		(*table)->entries += 1;
		return (index);
	}
	return (-1);
}
