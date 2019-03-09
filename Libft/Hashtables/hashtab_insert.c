/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:26:22 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/09 11:25:53 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         hashtab_insert -- insert a key-value pair as an entry into a
**                           hashtable.
**
**    SYNOPSIS
**         #include "string_42.h"
**         #include "stdlib_42.h"
**         #include "hashtable.h"
**
**         int
**         hashtab_insert(t_hashtable **table, char *key, void *item);
**
**    PARAMETERS
**
**         t_hashtable **table      Pointer to a pointer to a hashtable.
**
**         char *key                Key.
**
**         void *item               Value.
**
**    DESCRIPTION
**         A key-value pair is taken as input, turned into an entry, then
**         inserted into the hashtable pointed to by (*table).
**
**    RETURN VALUES
**         If successful, returns the index of the inserted entry in the
**         hashtable; otherwise -1.
*/

#include "../Includes/string_42.h"
#include "../Includes/stdlib_42.h"
#include "../Includes/hashtable.h"

/*
**  Helper function that creates an entry out of a key-value pair.
**  Note, a copy of the key is made; free'ing it is taken care of.
*/

static t_entry	*entry_create_(char *key, void *item)
{
	t_entry *new_entry;

	if (key && item)
	{
		if (!(new_entry = (t_entry *)malloc(sizeof(t_entry))))
			return (NULL);
		new_entry->key = ft_strdup(key);
		new_entry->item = item;
		new_entry->next = NULL;
		return (new_entry);
	}
	return (NULL);
}

int				hashtab_insert(t_hashtable **table, char *key, void *item)
{
	t_entry			*entry;
	unsigned int	index;

	if (table && key && item)
	{
		if (!(*table))
			(*table) = hashtab_new(INIT_HASHTABLE_SIZE);
		if (*table)
		{
			if (hashtab_set_appropriate_load_factor(table) == -1)
				return (-1);
			if (!(entry = entry_create_(key, item)))
				return (-1);
			index = HASHCODE(key, (*table)->num_buckets);
			entry->next = ((*table)->buckets)[index];
			((*table)->buckets)[index] = entry;
			(*table)->entries += 1;
			return (index);
		}
	}
	return (-1);
}
