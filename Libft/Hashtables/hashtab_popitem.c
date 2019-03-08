/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_popitem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 11:17:09 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/07 12:57:48 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         hashtab_popitem -- pop an entry from a hashtable and get its item.
**
**    SYNOPSIS
**         #include "stdlib_42.h"
**         #include "string_42.h"
**         #include "hashtable.h"
**
**         void *
**         hashtab_popitem(t_hashtable **table, char *key);
**
**    PARAMETERS
**
**         t_hashtable **table       Address of a pointer to a
**                                   hashtable.
**
**         char *key                 Key corresponding to a
**                                   value.
**
**    DESCRIPTION
**         Looks for an entry based on the 'key', if it exists, its item is
**         saved, the entry is free'd and the item is returned.
**
**    RETURN VALUES
**         If successful returns a pointer to the item; otherwise NULL.
*/

#include "../Includes/stdlib_42.h"
#include "../Includes/string_42.h"
#include "../Includes/hashtable.h"

/*
**  Helper function used to free an entry and that which it contains
**  except for its item.
*/

static void		free_entry_except_item(t_entry **entry)
{
	if (entry && *entry)
	{
		if ((*entry)->key)
			free((*entry)->key);
		free(*entry);
		(*entry) = NULL;
	}
}

void			*hashtab_popitem(t_hashtable **table, char *key)
{
	t_entry			*prev_entry;
	t_entry			*cur_entry;
	unsigned int	index;
	void			*item;

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
				item = cur_entry->item;
				(*table)->entries -= 1;
				free_entry_except_item(&cur_entry);
				return (item);
			}
			prev_entry = cur_entry;
			cur_entry = cur_entry->next;
		}
	}
	return (NULL);
}
