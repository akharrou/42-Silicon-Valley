/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_destroy.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:34:32 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/07 11:09:31 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         hashtab_destroy -- remove and free all entries of a hashtable and
**                            then free the hashtable itself.
**
**    SYNOPSIS
**         #include "stdlib_42.h"
**         #include "hashtable.h"
**
**         int
**         hashtab_destroy(t_hashtable **table, void (*free_item)(void *));
**
**    PARAMETERS
**
**         t_hashtable **table           Address of a pointer to a hashtable.
**
**
**    DESCRIPTION
**         Removes and frees all entries contained in the hashtable pointed to
**         by (*table), then frees the hashtable itself and sets (*table) to
**         NULL.
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

int				hashtab_destroy(t_hashtable **table)
{
	unsigned int	i;

	if (table)
	{
		if (*table)
		{
			if ((*table)->bucket_list)
			{
				i = 0;
				while (i < (*table)->num_buckets)
				{
					if (((*table)->bucket_list)[i])
						bucket_free_(&((*table)->bucket_list)[i]);
					i++;
				}
				free((*table)->bucket_list);
				(*table)->bucket_list = NULL;
			}
			free(*table);
			(*table) = NULL;
		}
		return (0);
	}
	return (-1);
}
