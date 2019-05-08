/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_getindex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 09:58:18 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/01 21:48:50 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		dict_getindex(t_hashtable *table, char *key)
{
	if (table && key)
		if (dict_getitem(table, key))
			return (HASHCODE(key, table->num_buckets));
	return (-1);
}
