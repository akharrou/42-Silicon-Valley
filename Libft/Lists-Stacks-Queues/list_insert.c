/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:25:52 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/27 16:44:08 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         list_insert -- inserts a new list element where it belongs in a list
**                        according to the comparasion function.
**
**    SYNOPSIS
**         #include <../libft.h>
**
**         int
**         list_insert(t_lst **head, const void *item,
**             int (*cmp)(void *, void *));
**
**    PARAMETERS
**
**         t_lst **head                  Pointer to a pointer to the
**                                        first element of a list.
**
**         const void *item               Data that will be stored in
**                                        the new list element.
**
**         int (*cmp)(void *, void *)     A pointer to a comparasion
**                                        function. It compares the
**                                        item reference to the current
**                                        item. Returns 0 for a match.
**
**    DESCRIPTION
**         Creates a new list element, storing 'item' as its item, then
**         traverses the list until the comparative function returns something
**         smaller or equal to 0, at which point the new list element is
**         inserted into the list where ever it happened to stop.
**
**         If the list does not exist the newly created element is made
**         to be the first element of the list.
**
**         (*head) is made to point to the first element of the list.
**
**    RETURN VALUES
**         Returns 0 if successful; otherwise -1.
*/

#include "../libft.h"

static void		list_insert_elem(t_lst **head, t_lst **new_elem,
					int (*cmp)(void *, void *))
{
	t_lst	*current;
	t_lst	*previous;

	current = (*head);
	while (cmp((void *)((*new_elem)->item), current->item) > 0)
	{
		if (current->next)
		{
			previous = current;
			current = current->next;
		}
		else
		{
			current->next = (*new_elem);
			return ;
		}
	}
	(*new_elem)->next = current;
	if (current == (*head))
		(*head) = (*new_elem);
	else
		previous->next = (*new_elem);
	return ;
}

int				list_insert(t_lst **head, const void *item,
					int (*cmp)(void *, void *))
{
	t_lst	*new_elem;

	if (head && cmp && (new_elem = list_newelem(item)))
	{
		if (*head)
			list_insert_elem(head, &new_elem, cmp);
		else
			(*head) = new_elem;
		return (0);
	}
	return (-1);
}