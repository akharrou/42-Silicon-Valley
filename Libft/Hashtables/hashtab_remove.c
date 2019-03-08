/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_remove.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:33:09 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/07 11:35:09 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         hashtab_remove -- remove and free an entry from a hashtable.
**
**    SYNOPSIS
**         #include "stdlib_42.h"
**         #include "string_42.h"
**         #include "hashtable.h"
**
**         int
**         hashtab_remove(t_hashtable **table, char *key);
**
**    PARAMETERS
**
**         t_hashtable **table           Address of a pointer to a
**                                       hashtable.
**
**         char *key                     Key corresponding to a
**                                       value.
**
**    DESCRIPTION
**         Looks for an entry based on the 'key', if it exists deletes/frees
**         it and everything it contains, including its item otherwise does
**         nothing and returns -1.
**
**    RETURN VALUES
**         If successful returns 0; otherwise -1.
*/

#include "../Includes/stdlib_42.h"
#include "../Includes/string_42.h"
#include "../Includes/hashtable.h"

/*
**  Helper function used to free an entry and all that it contains.
*/

static void		entry_free__(t_entry **entry)
{
	if (entry && *entry)
	{
		if ((*entry)->key)
			free((*entry)->key);
		if ((*entry)->item)
			free((*entry)->item);
		free(*entry);
		(*entry) = NULL;
	}
}

int				hashtab_remove(t_hashtable **table, char *key)
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
