/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_extend_tail.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 21:53:19 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/25 11:13:53 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         list_extend_tail -- appends multiple new elements to a list and
**                             (*tail) is made to point to the last element
**                             of the list.
**
**    SYNOPSIS
**         #include <libft.h>
**
**         int
**         list_extend_tail(t_list **tail, const void **item_vector);
**
**    PARAMETERS
**
**         t_list **tail                 Pointer to a pointer to
**                                       any element of the list
**                                       other than the last.
**
**         const void **item_vector      Vector containing items
**                                       to add to the end of the
**                                       list.
**
**    DESCRIPTION
**         Creates new list elements using the items in the item
**         vector and adds the newly created list elements to the
**         end of the list (that (*tail) points to).
**
**         (*tail) is made to point to the last element of the list.
**
**    RETURN VALUES
**         Returns 0 if successful; otherwise -1.
*/

#include "libft.h"

int		list_extend_tail(t_list **tail, const void **item_vector)
{
	if (tail && item_vector)
	{
		while (*item_vector)
		{
			if ((list_append_tail(tail, *item_vector)) == -1)
				return (-1);
			item_vector++;
		}
		return (0);
	}
	return (-1);
}
