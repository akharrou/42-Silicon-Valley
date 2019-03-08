/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_shrink.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 11:25:00 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/07 17:33:29 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         hashtab_grow -- shrink a hashtable (to HTAB_DIVISER times less the
**                         size).
**
**    SYNOPSIS
**         #include "stdlib_42.h"
**         #include "hashtable.h"
**
**         int
**         hashtab_shrink(t_hashtable **table);
**
**    PARAMETERS
**
**         t_hashtable **table          Pointer to a pointer to a hashtable.
**
**    DESCRIPTION
**         Allocates a new hashtable, the size of the current hashtable size
**         divided by HTAB_DIVISER (+ a little more is added to it inorder to
**         get to the closest prime number). Then all entries of the current
**         hashtable are rehashed and stored into it the new hashtable. Finally,
**         the current hashtable is destroyed/free'd and (*table) is made to
**         the new hashtable.
**
**    RETURN VALUES
**         If successful returns 0; otherwise -1.
*/

#include "../Includes/stdlib_42.h"
#include "../Includes/hashtable.h"

int		hashtab_shrink(t_hashtable **table)
{
	t_hashtable		*new_table;

	if (table && *table)
	{
		if ((*table)->num_buckets > 1)
		{
			new_table = hashtab_new((*table)->num_buckets / 2);
			if (new_table == NULL)
				return (-1);
			if (hashtab_rehash_table(table, &new_table) == -1)
				return (-1);
			hashtab_destroy(table);
			(*table) = new_table;
			return (0);
		}
		return (0);
	}
	return (-1);
}
