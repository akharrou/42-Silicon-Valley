/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_rehash_entry.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:37:12 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/07 17:24:29 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         hashtab_rehash_entry -- brief.
**
**    SYNOPSIS
**         #include "stdlib_42.h"
**         #include "hashtable.h"
**
**         int
**         hashtab_rehash_entry(t_hashtable **dest_table, t_entry **entry);
**
**    PARAMETERS
**
**         t_hashtable **dest_table       Pointer to a pointer to the
**                                      destination hashtable for the
**                                      rehashed entry.
**
**         t_entry **entry              Pointer to an entry that is to
**                                      be rehashed.
**
**    DESCRIPTION
**         The entry is rehashed and the output is modulo'ed with the
**         size of the (*dest_table) size and stored at that index in the
**         hashtable that (*dest_table) points to.
**
**    RETURN VALUES
**         If successful returns 0; otherwise -1.
*/

#include "../Includes/stdlib_42.h"
#include "../Includes/hashtable.h"

int				hashtab_rehash_entry(t_hashtable **dest_table, t_entry **entry)
{
	unsigned int	index;

	if (dest_table && *dest_table && entry && *entry)
	{
		index = HASHCODE((*entry)->key, (*dest_table)->num_buckets);
		(*entry)->next = ((*dest_table)->bucket_list)[index];
		((*dest_table)->bucket_list)[index] = (*entry);
		(*dest_table)->entries += 1;
		return (0);
	}
	return (-1);
}
