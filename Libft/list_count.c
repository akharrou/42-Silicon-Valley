/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:32:18 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/25 09:53:16 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         list_count -- count the number of elements in a list.
**
**    SYNOPSIS
**         #include <libft.h>
**
**         unsigned int
**         list_count(t_list *head);
**
**    PARAMETERS
**
**         t_list *head         Pointer to the first element
**                              of a list.
**
**    DESCRIPTION
**         Iterates through a list counting the number of elements
**         it contains, then returns the count.
**
**    RETURN VALUES
**         Returns the number of elements in the list.
*/

#include "libft.h"

unsigned int	list_count(t_list *head)
{
	unsigned int i;

	i = 0;
	while (head)
	{
		head = head->successor;
		++i;
	}
	return (i);
}
