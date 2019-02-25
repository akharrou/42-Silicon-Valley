/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:31:32 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/25 09:42:52 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         list_iter -- iterate through a list applying a function to every
**                      item of the list.
**
**    SYNOPSIS
**         #include <libft.h>
**
**         void
**         list_iter(t_list *head, void (*f)(void *item));
**
**    PARAMETERS
**
**         t_list *head              Pointer to the first element
**                                   of a list.
**
**         void (*f)(void *item)     A pointer to a function that
**                                   takes a list item as parameter.
**
**    DESCRIPTION
**         Iterates through a list applying the function 'f()' to all
**         of its items.
**
**    RETURN VALUES
**         Returns nothing.
*/

#include "libft.h"

void		list_iter(t_list *head, void (*f)(void *item))
{
	if (f)
	{
		while (head)
		{
			f(head->item);
			head = head->successor;
		}
	}
}
