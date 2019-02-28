/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_last_item.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:36:04 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/27 16:44:08 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         list_last_item -- get the last item of a list.
**
**    SYNOPSIS
**         #include <../libft.h>
**
**         t_lst *
**         list_last_item(t_lst *head);
**
**    PARAMETERS
**
**         t_lst *head      Pointer to the first element of
**                           a list.
**
**    DESCRIPTION
**         Traverses the list until it finds the last element of
**         the list then returns a pointer to its item.
**
**    RETURN VALUES
**         If successful returns a pointer to the last element
**         item.
*/

#include "../libft.h"

void		*list_last_item(t_lst *head)
{
	t_lst	*last_elem;

	last_elem = list_last_elem(head);
	if (last_elem)
		return (last_elem->item);
	return (NULL);
}
