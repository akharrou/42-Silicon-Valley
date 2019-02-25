/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_getelem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:29:18 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/24 19:21:02 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         list_getelem -- retrieve the element that contains a certain item.
**
**    SYNOPSIS
**         #include <libft.h>
**
**         t_list *
**         list_getelem(t_list *head, const void *item_ref, int (*cmp)());
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

#include "libft.h"

t_list	*list_getelem(t_list *head, const void *item_ref, int (*cmp)())
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
