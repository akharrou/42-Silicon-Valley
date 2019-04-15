/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:37:37 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/20 16:55:05 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/string_42.h"

char	*ft_strchr(const char *s, int c)
{
	if (s)
	{
		while (*s)
		{
			if (*s == (unsigned char)c)
				return ((char *)s);
			s++;
		}
		if (*s == (unsigned char)c)
			return ((char *)s);
	}
	return (NULL);
}
