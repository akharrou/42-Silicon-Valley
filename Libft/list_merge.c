/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_merge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:33:34 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/25 14:29:45 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         list_merge -- append one list to the end of another.
**
**    SYNOPSIS
**         #include <libft.h>
**
**         int
**         list_merge(t_list **lst1, t_list *lst2);
**
**    PARAMETERS
**
**         t_list **lst1          Pointer to a pointer to a destination
**                                list.
**
**         t_list *lst2           Pointer
**
**    DESCRIPTION
**         Description.
**
**    RETURN VALUES
**         Returns 0 if successful; otherwise -1.
*/

#include "libft.h"

int		list_merge(t_list **lst1, t_list *lst2)
{
	t_list *last;

	if (!(lst1) || (!(*lst1) && !(lst2)))
		return (-1);
	else if (!(*lst1) && lst2)
		(*lst1) = lst2;
	else
	{
		last = list_last_elem(*lst1);
		if (!last)
			return (-1);
		last->successor = lst2;
	}
	return (0);
}
