/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_extend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:56:13 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/07 16:26:14 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/dict.h"

/*
**  Add multiple items to a list.
*/

int		dict_extend(t_hashtable **table, char **key_vector, void **item_vector)
{
	int	ret;

	if (table && key_vector && item_vector && *key_vector && *item_vector)
	{
		if (!(*table))
			(*table) = hashtab_new(INIT_HASHTABLE_SIZE);
		if (*table)
		{
			while (*key_vector && *item_vector)
			{
				ret = hashtab_insert(table, *key_vector, *item_vector);
				if (ret == -1)
					return (-1);
			}
			return (0);
		}
	}
	return (-1);
}
