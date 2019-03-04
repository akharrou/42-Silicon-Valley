/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 09:55:34 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/04 10:32:17 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/dict.h"

int		dict_insert(t_hashtable **table, char *key, void *item)
{
	if (table)
	{
		if (!(*table))
		{
			(*table) = hashtab_alloc_table(INIT_HASHTABLE_SIZE);
			if (!(*table))
				return (-1);
		}
		return (hashtab_insert_entry(table, key, item));
	}
	return (-1);
}