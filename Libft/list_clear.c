/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:29:53 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/24 19:36:12 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         list_clear -- free an entire list and all the items it conains.
**
**    SYNOPSIS
**         #include <libft.h>
**
**         int
**         list_clear(t_list **head, void free_item(void *));
**
**    PARAMETERS
**
**         t_list **head              Pointer to a pointer to the
**                                    first element of a list.
**
**         void free_item(void *)     A function that frees an item
**                                    of the list.
**
**    DESCRIPTION
**         Frees all the elements and items of a list.
**
**    RETURN VALUES
**         Returns 0 if successful; otherwise -1.
*/

#include <stdlib.h>
#include "libft.h"

int		list_clear(t_list **head, void free_item(void *))
{
	t_list	*tmp;

	if (head && free_item)
	{
		while (*head)
		{
			tmp = (*head);
			(*head) = (*head)->successor;
			free_item(tmp->item);
			free(tmp);
		}
		(*head) = NULL;
		return (0);
	}
	return (-1);
}
