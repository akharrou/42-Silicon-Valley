/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop_item_at.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 07:00:41 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/27 16:44:08 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         list_pop_item_at -- pop an item at a specific index.
**
**    SYNOPSIS
**         #include <../libft.h>
**
**         void *
**         list_pop_item_at(t_lst **head, unsigned int i);
**
**    PARAMETERS
**
**         t_lst **head          Pointer to a pointer to the
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

#include "../libft.h"

void	*list_pop_item_at(t_lst **head, unsigned int i)
{
	void			*item;
	t_lst			*current;
	t_lst			*previous;
	unsigned int	index;

	if (head && (*head))
	{
		index = 0;
		current = (*head);
		while (i > index++)
		{
			if (!(current->next))
				return (NULL);
			previous = current;
			current = current->next;
		}
		if (current == (*head))
			(*head) = current->next;
		else
			previous->next = current->next;
		item = current->item;
		free(current);
		return (item);
	}
	return (NULL);
}
