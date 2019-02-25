/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 09:55:34 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/22 10:22:13 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		dict_insert(t_hashtable **table, char *key, void *value,
					unsigned int num_entries)
{
	if (table)
	{
		if (*table)
			return (hashtab_insert_entry(table, key, value));
		if (!((*table) = hashtab_alloc_table(num_entries)))
			return (-1);
		return (hashtab_insert_entry(table, key, value));
	}
	return (-1);
}
