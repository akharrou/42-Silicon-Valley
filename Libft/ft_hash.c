/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:43:35 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/22 07:29:27 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Algorithm produced by Professor Daniel J. Bernstein.
** All rights reserved.
*/

unsigned int	ft_hash(const char *str)
{
	unsigned int i;
	unsigned int hash;
	unsigned int length;

	i = 0;
	hash = 5381;
	length = ft_strlen(str);
	while (i < length)
	{
		hash = ((hash << 5) + hash) + (*str);
		++str;
		++i;
	}
	return (hash);
}
