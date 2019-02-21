/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 19:34:58 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/20 17:39:37 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*head;

	head = NULL;
	while (lst)
	{
		tmp = (*f)(lst);
		if (!(tmp = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		ft_lstadd(&head, tmp);
		lst = lst->next;
	}
	return (head);
}
