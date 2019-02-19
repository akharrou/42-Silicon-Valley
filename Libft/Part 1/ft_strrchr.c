/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:08:43 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/18 17:14:43 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char *last_occurence;

	last_occurence = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
			last_occurence = (char *)s;
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	else
		return (last_occurence);
}
