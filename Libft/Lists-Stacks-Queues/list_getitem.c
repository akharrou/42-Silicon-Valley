/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_getitem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:26:10 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/27 16:44:08 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         list_getitem -- retrieve an item found at a specific reference.
**
**    SYNOPSIS
**         #include <../libft.h>
**
**         void *
**         list_getitem(t_lst *head, const void *item_ref, int (*cmp)());
**
**    PARAMETERS
**
**         t_lst *head                  Pointer to the first element of
**                                       a list.
**
**         const void *item_ref          A reference to find the item.
**
**         int (*cmp)(void *, void *)    A comparasion function to compare the
**                                       current item and the item reference.
**                                       Returns 0 for a match.
**
**    DESCRIPTION
**         Iterates through a list until the specified item reference is
**         matched according to the comparative function, then returns
**         a pointer to the item.
**
**    RETURN VALUES
**         If successfully found, the item is returned; otherwise NULL is
**         returned.
*/

#include "../libft.h"

void	*list_getitem(t_lst *head, const void *item_ref,
			int (*cmp)(void *, void *))
{
	t_lst	*elem;

	elem = list_getelem(head, item_ref, cmp);
	if (elem)
		return (elem->item);
	return (NULL);
}
