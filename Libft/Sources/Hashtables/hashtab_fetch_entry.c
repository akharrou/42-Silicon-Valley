/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_fetch_entry.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:31:25 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/04 10:36:58 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/string_42.h"
#include "../../Includes/stdlib_42.h"
#include "../../Includes/hashtable.h"

t_entry			*hashtab_fetch_entry(t_hashtable *table, char *key)
{
	t_entry			*cur_entry;
	unsigned int	index;

	if (table && key)
	{
		index = HASHCODE(key, table->num_buckets);
		cur_entry = (table->bucket_list)[index];
		while (cur_entry)
		{
			if (ft_strcmp(cur_entry->key, key) == 0)
				return (cur_entry);
			cur_entry = cur_entry->next;
		}
	}
	return (NULL);
}