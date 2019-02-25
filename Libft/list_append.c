/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_append.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:19:47 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/24 21:05:07 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         list_append -- adds a new element to the end of a list.
**
**    SYNOPSIS
**         #include <libft.h>
**
**         t_list *
**         list_append(t_list **head, const void *item);
**
**    PARAMETERS
**
**         t_list **head          Pointer to a pointer to the
**                                first element of a list
**                                (that said, it could be a
**                                pointer to any element of
**                                a list since the list will
**                                be traversed in any case).
**
**         const void *item       Data that will be stored in
**                                the new list element.
**
**    DESCRIPTION
**         Creates a new list element, storing 'item' as its item, then
**         adds the element to the end of the list (that (*head) points
**         to).
**
**         If the list does not exist the newly created element is made
**         to be the first/last element of the list.
**
**         (*head) stays pointing to whatever it originally pointed to.
**
**    RETURN VALUES
**         Returns 0 if successful; otherwise -1.
*/

#include "libft.h"

int		list_append(t_list **head, const void *item)
{
	t_list	*probe;
	t_list	*new_elem;

	if (head && (new_elem = list_newelem(item)))
	{
		if (*head)
		{
			probe = (*head);
			while (probe->successor)
				probe = probe->successor;
			probe->successor = new_elem;
		}
		else
			(*head) = new_elem;
		return (0);
	}
	return (-1);
}
