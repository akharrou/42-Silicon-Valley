/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_grow_table.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:36:30 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/06 11:48:48 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				hashtab_grow_table(t_hashtable **table)
{
	t_hashtable		*new_table;

	if (table && *table)
	{
		new_table = hashtab_alloc_table((*table)->num_buckets * 2);
		if (new_table == NULL)
			return (-1);
		if (hashtab_rehash_table(table, &new_table) == -1)
			return (-1);
		hashtab_destroy_table(table);
		(*table) = new_table;
		return (0);
	}
	return (-1);
}
