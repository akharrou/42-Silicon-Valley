/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_clear.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:34:32 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/07 11:09:31 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         hashtab_clear -- remove and free all entries of a hashtable without
**                          free'ing the hashtable itself.
**
**    SYNOPSIS
**         #include "stdlib_42.h"
**         #include "hashtable.h"
**
**         int
**         hashtab_clear(t_hashtable **table, void (*free_item)(void *));
**
**    PARAMETERS
**
**         t_hashtable **table           Address of a pointer to a hashtable.
**
**    DESCRIPTION
**         Removes and frees all entries contained in the hashtable pointed to
**         by (*table) without free'ing the hashtable itself.
**
**    RETURN VALUES
**         If successful returns 0; otherwise -1.
*/

#include "../Includes/stdlib_42.h"
#include "../Includes/hashtable.h"

static void		entry_free_(t_entry **entry)
{
	if (entry && *entry)
	{
		if ((*entry)->key)
			free((*entry)->key);
		if ((*entry)->item)
			free((*entry)->item);
		free(*entry);
		(*entry) = NULL;
	}
}

static void		bucket_free_(t_entry **head)
{
	t_entry	*temp;

	if (head)
	{
		while (*head)
		{
			temp = (*head);
			(*head) = (*head)->next;
			entry_free_(&temp);
		}
	}
}

int				hashtab_clear(t_hashtable **table)
{
	unsigned int	i;

	if (table)
	{
		if (*table)
		{
			if ((*table)->bucket_list)
			{
				i = 0;
				while ((*table)->num_buckets > i)
				{
					if (((*table)->bucket_list)[i])
						bucket_free_(&((*table)->bucket_list)[i]);
					i++;
				}
				(*table)->entries = 0;
				return (0);
			}
		}
	}
	return (-1);
}
