/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 07:40:24 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/02 15:16:00 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/stdlib_42.h"

char	*ft_padding(size_t size, char c)
{
	char	*buf;
	size_t	i;

	buf = NULL;
	if (size > 0)
	{
		buf = malloc(size + 1);
		if (!buf)
			return (NULL);
		i = 0;
		while (size > i)
			buf[i++] = c;
		buf[i++] = '\0';
	}
	return (buf);
}
