/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop_item_at.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 07:00:41 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/25 09:28:40 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         list_pop_item_at -- pop an item at a specific index.
**
**    SYNOPSIS
**         #include <libft.h>
**
**         void *
**         list_pop_item_at(t_list **head, unsigned int i);
**
**    PARAMETERS
**
**         t_list **head          Pointer to a pointer to the
**                                first element of a list.
**
**         unsigned int i         Index at which to pop the
**                                item.
**
**    DESCRIPTION
**         Traverses a list until its i'th element is reached, then
**         removes it from the list, frees its memory, stitches the
**         list back together and returns the popped element's item.
**
**         If the popped element is the first element of the list,
**         then (*head), after popping, is updated to point
**         to the new first element of the list.
**
**    RETURN VALUES
**         If successful returns the popped item; otherwise NULL.
*/

#include <stdlib.h>
#include "libft.h"

void	*list_pop_item_at(t_list **head, unsigned int i)
{
	void			*item;
	t_list			*current;
	t_list			*previous;
	unsigned int	index;

	if (head && (*head))
	{
		index = 0;
		current = (*head);
		while (i > index++)
		{
			if (!(current->successor))
				return (NULL);
			previous = current;
			current = current->successor;
		}
		if (current == (*head))
			(*head) = current->successor;
		else
			previous->successor = current->successor;
		item = current->item;
		free(current);
		return (item);
	}
	return (NULL);
}
