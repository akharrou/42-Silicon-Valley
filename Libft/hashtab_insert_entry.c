/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_insert_entry.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:28:03 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/22 08:20:07 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static t_entry	*entry_create_(char *key, void *value)
{
	t_entry *new_entry;

	if (key && value)
	{
		if (!(new_entry = malloc(sizeof(t_entry))))
			return (NULL);
		new_entry->key = ft_strdup(key);
		new_entry->value = value;
		new_entry->successor = NULL;
		return (new_entry);
	}
	return (NULL);
}

int				hashtab_insert_entry(t_hashtable **table,
									char *key,
									void *value)
{
	t_entry			*entry;
	unsigned int	index;

	if (table && *table && key && value)
	{
		if (hashtab_set_appropriate_load_factor(table) == -1)
			return (-1);
		if (!(entry = entry_create_(key, value)))
			return (-1);
		index = HASHCODE(key, (*table)->num_buckets);
		entry->successor = ((*table)->bucket_list)[index];
		((*table)->bucket_list)[index] = entry;
		(*table)->entries += 1;
		return (0);
	}
	return (-1);
}
