/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_elem_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:28:23 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/27 16:44:08 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         list_elem_at -- retrieve the i'th element of a list.
**
**    SYNOPSIS
**         #include <../libft.h>
**
**         t_lst *
**         list_elem_at(t_lst *head, unsigned int i);
**
**    PARAMETERS
**
**         t_lst *head          Pointer to the first element of
**                               a list.
**
**         unsigned int i        Index at which to find the element.
**
**    DESCRIPTION
**         Retrieves the list element found at the i'th index in the
**         list that 'head' points to.
**
**         If the given index goes past the end of the list, then NULL is
**         returned.
**
**    RETURN VALUES
**         If successful returns the element found at the specified index;
**         otherwise NULL.
*/

#include "../libft.h"

t_lst	*list_elem_at(t_lst *head, unsigned int i)
{
	unsigned int	index;

	if (head)
	{
		index = 0;
		while (i > index)
		{
			if (!(head->next))
				return (NULL);
			head = head->next;
			++index;
		}
		return (head);
	}
	return (NULL);
}
