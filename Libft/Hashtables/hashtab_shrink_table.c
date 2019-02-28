/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_shrink_table.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:36:52 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/27 16:44:47 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int				hashtab_shrink_table(t_hashtable **table)
{
	t_hashtable		*new_table;

	if (table && *table)
	{
		if ((*table)->num_buckets > 1)
		{
			new_table = hashtab_alloc_table((*table)->num_buckets / 2);
			if (new_table == NULL)
				return (-1);
			if (hashtab_rehash_table(table, &new_table) == -1)
				return (-1);
			hashtab_destroy_table(table);
			(*table) = new_table;
			return (0);
		}
		return (0);
	}
	return (-1);
}
