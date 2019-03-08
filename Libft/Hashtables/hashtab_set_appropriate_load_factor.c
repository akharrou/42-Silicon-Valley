/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_set_appropriate_load_factor.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:35:59 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/07 11:24:49 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         hashtab_set_appropriate_load_factor -- keep load factor of a
**                                                hashtable in check.
**
**                                                Grow or shrink hashtable
**                                                if necessary.
**
**    SYNOPSIS
**         #include "hashtable.h"
**
**         int
**         hashtab_set_appropriate_load_factor(t_hashtable **table);
**
**    PARAMETERS
**
**         t_hashtable **table      Address of a pointer to a hashtable.
**
**    DESCRIPTION
**         Checks that the current load factor is neither greater than
**         nor smaller than the desired max load factor and desired minimum
**         load factor respectively.
**
**         If either is the case, a procedure to realloc (grow) or dealloc
**         (shrink) the table will ensue.
**
**         If neither is the case, nothing happens.
**
**    RETURN VALUES
**         If nothing happens, or a successful reallocation or deallocation
**         happens, 0 is returned; otherwise -1 is returned.
*/

#include "../Includes/hashtable.h"

int				hashtab_set_appropriate_load_factor(t_hashtable **table)
{
	if (table && *table)
	{
		if ((float)(*table)->entries / (float)(*table)->num_buckets
			> MAX_LOAD_FACTOR)
		{
			if (hashtab_grow(table) == -1)
				return (-1);
			return (0);
		}
		if ((float)(*table)->entries / (float)(*table)->num_buckets
			< MIN_LOAD_FACTOR)
		{
			if (hashtab_shrink(table) == -1)
				return (-1);
			return (0);
		}
		else
		{
			return (0);
		}
	}
	return (-1);
}
