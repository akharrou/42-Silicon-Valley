/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_delelem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 20:24:43 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/24 20:26:07 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         list_delelem --
**
**    SYNOPSIS
**         #include <libft.h>
**
**         int
**         list_delelem(t_list **head, const void *item_ref, int (*cmp)());
**
**    PARAMETERS
**
**         t_list *head             Pointer to the first element of a list.
**
**         const void *item_ref     A reference to find the element.
**
**         int (*cmp)()             A comparasion function to compare the
**                                  current item and the item reference.
**
**    DESCRIPTION
**         Iterates through a list until the specified item reference is
**         matched according to the comparative function.
**
**    RETURN VALUES
**         If successfully found, the element containing the item is
**         returned; otherwise NULL is returned.
*/

#include <stdlib.h>
#include "libft.h"

int		list_delelem(t_list **head, const void *item_ref,
			int (*cmp)())
{
	if (head && cmp && item_ref)
	{
		while (cmp(item_ref, head->item) != 0)
		{
			if (head->successor)
				head = head->successor;
			else
				return (NULL);
		}
		return (head);
	}
	return (NULL);
}
