/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_alloc_table.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:26:47 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/27 16:44:47 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_hashtable		*hashtab_alloc_table(unsigned int num_entries)
{
	t_hashtable		*table;
	unsigned int	i;

	if (num_entries < 1)
		return (NULL);
	if (!(table = malloc(sizeof(t_hashtable))))
		return (NULL);
	num_entries = (unsigned int)ft_find_next_prime(num_entries);
	if (!(table->bucket_list =
			malloc(sizeof(t_entry*) * num_entries)))
	{
		free(table);
		return (NULL);
	}
	table->num_buckets = num_entries;
	table->entries = 0;
	i = 0;
	while (i < num_entries)
		(table->bucket_list)[i++] = NULL;
	return (table);
}
