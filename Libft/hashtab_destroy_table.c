/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_destroy_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:34:32 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/22 08:12:51 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void		entry_free_(t_entry **entry)
{
	if (entry && *entry)
	{
		if ((*entry)->key)
			free((*entry)->key);
		if ((*entry)->value)
			free((*entry)->value);
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
			(*head) = (*head)->successor;
			entry_free_(&temp);
		}
	}
}

int				hashtab_destroy_table(t_hashtable **table)
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
