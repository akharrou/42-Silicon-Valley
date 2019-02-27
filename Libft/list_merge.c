/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_merge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:33:34 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/26 20:04:20 by akharrou         ###   ########.fr       */
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
**         list_merge(t_list **dest, t_list *src);
**
**    PARAMETERS
**
**         t_list **dest          Pointer to a pointer to a
**                                destination list.
**
**         t_list *src            Pointer to a list that is
**                                that will be appended to
**                                the (*dest) list.
**
**    DESCRIPTION
**         Appends the (*dest) list to the end of the 'src' list.
**
**    RETURN VALUES
**         Returns 0 if successful; otherwise -1.
*/

#include "libft.h"

int		list_merge(t_list **dest, t_list *src)
{
	t_list *last;

	if (!dest || (!(*dest) && !src))
		return (-1);
	else if (!(*dest) && src)
		(*dest) = src;
	else
	{
		last = list_last_elem(*dest);
		if (!last)
			return (-1);
		last->successor = src;
	}
	return (0);
}
