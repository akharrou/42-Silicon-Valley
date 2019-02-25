/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_getkey.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 09:58:18 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/22 10:00:10 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		dict_getkey(t_hashtable *table, char *key)
{
	if (table && key)
		return (HASHCODE(key, table->num_buckets));
	return (-1);
}
