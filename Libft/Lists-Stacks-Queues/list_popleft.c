/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_popleft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:31:05 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/27 16:44:08 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         list_popleft -- removes the first element of a list and returns
**                         the item it contains.
**
**    SYNOPSIS
**         #include <../libft.h>
**
**         void *
**         list_popleft(t_lst **head);
**
**    PARAMETERS
**
**         t_lst **head          Pointer to a pointer to the first
**                                element of a list.
**
**    DESCRIPTION
**         Removes and frees the first element of the list, that (*head)
**         points to, updates (*head) to point to the new first element of
**         the list and returns the item that the first element contained.
**
**         If the list had a single element, (*head), after popping the
**         first element, will be made to point to NULL.
**
**    RETURN VALUES
**         If successful returns the item from the popped element of the
**         list; otherwise NULL.
*/

#include "../libft.h"

void		*list_popleft(t_lst **head)
{
	void	*item;
	t_lst	*tmp;

	if (head && (*head))
	{
		item = (*head)->item;
		tmp = (*head);
		(*head) = (*head)->next;
		free(tmp);
		return (item);
	}
	return (NULL);
}
