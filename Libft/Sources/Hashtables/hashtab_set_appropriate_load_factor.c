/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_set_appropriate_load_factor.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:35:59 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/04 10:39:36 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/hashtable.h"

int				hashtab_set_appropriate_load_factor(t_hashtable **table)
{
	if (table && *table)
	{
		if ((float)(*table)->entries / (float)(*table)->num_buckets
			> MAX_LOAD_FACTOR)
		{
			if (hashtab_grow_table(table) == -1)
				return (-1);
			return (0);
		}
		if ((float)(*table)->entries / (float)(*table)->num_buckets
			< MIN_LOAD_FACTOR)
		{
			if (hashtab_shrink_table(table) == -1)
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
