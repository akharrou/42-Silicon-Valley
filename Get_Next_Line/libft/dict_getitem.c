/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_getitem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 21:30:11 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/01 10:45:43 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*dict_getitem(t_hashtable *table, char *key)
{
	t_entry *entry;

	entry = hashtab_fetch_entry(table, key);
	if (entry)
		return (entry->item);
	return (NULL);
}
