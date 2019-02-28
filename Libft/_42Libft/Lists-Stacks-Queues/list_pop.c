/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:30:38 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/27 16:44:08 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         list_pop -- removes the last element of a list and returns the item
**                     it contains.
**
**    SYNOPSIS
**         #include <../libft.h>
**
**         void *
**         list_pop(t_lst **head);
**
**    PARAMETERS
**
**         t_lst **head          Pointer to a pointer to the first
**                                element of a list.
**
**    DESCRIPTION
**         Removes and frees the last element of the list, that (*head)
**         points to, updates the NEW last element of the list to point
**         to NULL and returns the item it contains.
**
**         If the list had a single element, (*head), after popping the
**         last element, will be made to point to NULL.
**
**    RETURN VALUES
**         If successful returns the item from the popped element of the
**         list; otherwise NULL.
*/

#include "../libft.h"

void		*list_pop(t_lst **head)
{
	void	*item;
	t_lst	*current;
	t_lst	*previous;

	if (head && (*head))
	{
		previous = NULL;
		current = (*head);
		while (current->next)
		{
			previous = current;
			current = current->next;
		}
		if (previous)
			previous->next = current->next;
		else
			(*head) = NULL;
		item = current->item;
		free(current);
		return (item);
	}
	return (NULL);
}
