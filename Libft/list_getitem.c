/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_getitem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:26:10 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/24 19:25:22 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         list_getitem -- retrieve an item found at a specific reference.
**
**    SYNOPSIS
**         #include <libft.h>
**
**         void *
**         list_getitem(t_list *head, const void *item_ref, int (*cmp)());
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
**         If successfully found, the item is returned; otherwise NULL is
**         returned.
*/

#include "libft.h"

void	*list_getitem(t_list *head, const void *item_ref, int (*cmp)())
{
	return ((list_getelem(head, item_ref, cmp))->item);
}
