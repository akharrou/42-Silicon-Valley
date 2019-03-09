/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_grow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 11:25:07 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/09 08:53:38 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         hashtab_grow -- grow a hashtable (to HTAB_MULTIPLIER times the size).
**
**    SYNOPSIS
**         #include "stdlib_42.h"
**         #include "hashtable.h"
**
**         int
**         hashtab_grow(t_hashtable **table);
**
**    PARAMETERS
**
**         t_hashtable **table          Pointer to a pointer to a hashtable.
**
**    DESCRIPTION
**         Allocates a new hashtable, the size of the current hashtable
**         multipled by HTAB_MULTIPLIER (+ a little more is added to it
**         to get to the closest prime number). Then all entries of the
**         current hashtable are rehashed and stored into it the new
**         hashtable. Finally, the current hashtable is destroyed/free'd.
**
**    RETURN VALUES
**         If successful returns 0; otherwise -1.
*/

#include "../Includes/stdlib_42.h"
#include "../Includes/hashtable.h"

int	hashtab_grow(t_hashtable **table)
{
	t_hashtable		*new_table;

	if (table && *table)
	{
		new_table = hashtab_new((*table)->num_buckets * HTAB_MULTIPLIER);
		if (new_table)
		{
			if (hashtab_rehash_table(table, &new_table) == 0)
			{
				hashtab_destroy(table);
				(*table) = new_table;
				return (0);
			}
		}
	}
	return (-1);
}
