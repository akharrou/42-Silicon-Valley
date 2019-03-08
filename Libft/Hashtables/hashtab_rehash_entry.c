/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_rehash_entry.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:37:12 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/07 10:06:48 by akharrou         ###   ########.fr       */
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
**         hashtab_rehash_entry(t_hashtable **table_to, t_entry **entry);
**
**    PARAMETERS
**
**         PARAM 1                 Brief
**
**         PARAM 2                 Brief
**
**         PARAM 3                 Brief
**
**    DESCRIPTION
**         Description.
**
**    RETURN VALUES
**         If successful returns 0; otherwise -1.
*/

#include "../Includes/stdlib_42.h"
#include "../Includes/hashtable.h"

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
