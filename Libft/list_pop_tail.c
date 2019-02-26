/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop_tail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 21:20:39 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/25 11:12:43 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         list_pop_tail -- removes the last element of a list and returns
**                          the item it contains and (*tail) is made to point
**                          to the last element of the list.
**
**    SYNOPSIS
**         #include <libft.h>
**
**         void *
**         list_pop_tail(t_list **tail);
**
**    PARAMETERS
**
**         t_list **tail        Pointer to a pointer to any element
**                              of the list other than the last.
**
**    DESCRIPTION
**         Removes and frees the last element of the list, that (*tail)
**         points to, updates the new last element of the list to point
**         to NULL and (*tail) to point to the new last element of the
**         list. Finally, it returns the item that was contained by the
**         last element of the list.
**
**         If the list had a single element, (*tail), after popping the
**         last element, will be made to point to NULL.
**
**    RETURN VALUES
**         If successful returns the item from the popped element of the
**         list; otherwise NULL.
*/

#include <stdlib.h>
#include "libft.h"

void		*list_pop_tail(t_list **tail)
{
	void	*item;
	t_list	*current;
	t_list	*previous;

	if (tail && (*tail))
	{
		previous = NULL;
		current = (*tail);
		while (current->successor)
		{
			previous = current;
			current = current->successor;
		}
		if (previous)
		{
			previous->successor = current->successor;
			(*tail) = previous;
		}
		else
			(*tail) = NULL;
		item = current->item;
		free(current);
		return (item);
	}
	return (NULL);
}
