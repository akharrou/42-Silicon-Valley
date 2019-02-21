/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 19:34:58 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/20 20:55:29 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*prev;
	t_list	*head;

	head = NULL;
	if (lst && *f)
	{
		head = (*f)(lst);
		prev = head;
		lst = lst->next;
		while (lst)
		{
			new = (*f)(lst);
			prev->next = new;
			prev = new;
			lst = lst->next;
		}
		prev->next = NULL;
	}
	return (head);
}
