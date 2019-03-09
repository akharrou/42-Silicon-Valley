/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_rehash_table.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:37:28 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/06 11:48:35 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		hashtab_rehash_table(t_hashtable **table_from,
				t_hashtable **table_to)
{
	t_entry			*cur_entry;
	t_entry			*temp;
	unsigned int	i;

	if (table_from && *table_from && table_to && *table_to)
	{
		i = 0;
		while (i < (*table_from)->num_buckets)
		{
			if (((*table_from)->bucket_list)[i])
			{
				cur_entry = ((*table_from)->bucket_list)[i];
				while (cur_entry)
				{
					temp = cur_entry->next;
					if (hashtab_rehash_entry(table_to, &cur_entry) == -1)
						return (-1);
					cur_entry = temp;
				}
				((*table_from)->bucket_list)[i] = NULL;
			}
			i++;
		}
	}
	return (((*table_to)->entries == (*table_from)->entries) ? 0 : -1);
}
