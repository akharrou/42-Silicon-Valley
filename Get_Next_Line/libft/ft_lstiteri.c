/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 09:14:33 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/20 09:17:45 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiteri(t_list *lst, void (*f)(unsigned int i, t_list *elem))
{
	unsigned int i;

	i = 0;
	while (lst)
	{
		(*f)(i, lst);
		lst = lst->next;
		i++;
	}
}
