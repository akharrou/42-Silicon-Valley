/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_rehash_table.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:37:28 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/09 08:54:08 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         hashtab_rehash_table -- rehash all entries of hashtable.
**
**    SYNOPSIS
**         #include <libft.h>
**
**         int
**         hashtab_rehash_table(t_hashtable **src_table,
**                 t_hashtable **dest_table);
**
**    PARAMETERS
**
**         t_hashtable **src_table          Pointer to a pointer to the
**                                          hashtable whose entries are
**                                          to be rehashed.
**
**         t_hashtable **dest_table         Pointer to a pointer to the
**                                          destination hashtable that
**                                          will store the rehashed entries.
**
**    DESCRIPTION
**         Rehashes all entries of the 'src_table' hashtable into the
**         'dest_table' hashtable. The output of the hash function is
**         modulo'ed with the size of the 'dest_table' hashtable.
**
**    RETURN VALUES
**         If successful returns 0; otherwise -1.
*/

#include "../Includes/stdlib_42.h"
#include "../Includes/hashtable.h"

int	hashtab_rehash_table(t_hashtable **src_table,
			t_hashtable **dest_table)
{
	t_entry			*cur_entry;
	t_entry			*temp;
	unsigned int	i;

	if (src_table && *src_table && dest_table && *dest_table)
	{
		i = 0;
		while (i < (*src_table)->num_buckets)
		{
			if (((*src_table)->bucket_list)[i])
			{
				cur_entry = ((*src_table)->bucket_list)[i];
				while (cur_entry)
				{
					temp = cur_entry->next;
					if (hashtab_rehash_entry(dest_table, &cur_entry) == -1)
						return (-1);
					cur_entry = temp;
				}
				((*src_table)->bucket_list)[i] = NULL;
			}
			i++;
		}
	}
	return (((*dest_table)->entries == (*src_table)->entries) ? 0 : -1);
}
