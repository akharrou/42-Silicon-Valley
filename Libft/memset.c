/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 17:45:50 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/17 20:16:53 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int i;

	if (b && len > 0)
	{
		i = 0;
		while (((char *)b)[i] != '\0' && i < len)
			((char *)b)[i++] = (unsigned char)c;
	}
	return (b);
}
