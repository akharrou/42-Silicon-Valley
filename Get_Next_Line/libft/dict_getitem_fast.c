/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_getitem_fast.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 21:30:19 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/01 10:45:43 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*dict_getitem_fast(t_hashtable *table, char *key, int table_index)
{
	t_entry *entry;

	if (table_index > -1)
	{
		entry = dict_getentry_fast(table, key, table_index);
		if (entry)
			return (entry->item);
	}
	return (NULL);
}
