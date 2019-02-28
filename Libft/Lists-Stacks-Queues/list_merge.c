/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_merge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:33:34 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/27 16:44:08 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         list_merge -- append one list to the end of another.
**
**    SYNOPSIS
**         #include <../libft.h>
**
**         int
**         list_merge(t_lst **dest, t_lst *src);
**
**    PARAMETERS
**
**         t_lst **dest          Pointer to a pointer to a
**                                destination list.
**
**         t_lst *src            Pointer to a list that is
**                                that will be appended to
**                                the (*dest) list.
**
**    DESCRIPTION
**         Appends the (*dest) list to the end of the 'src' list.
**
**    RETURN VALUES
**         Returns 0 if successful; otherwise -1.
*/

#include "../libft.h"

int		list_merge(t_lst **dest, t_lst *src)
{
	t_lst *last;

	if (!dest || (!(*dest) && !src))
		return (-1);
	else if (!(*dest) && src)
		(*dest) = src;
	else
	{
		last = list_last_elem(*dest);
		if (!last)
			return (-1);
		last->next = src;
	}
	return (0);
}
