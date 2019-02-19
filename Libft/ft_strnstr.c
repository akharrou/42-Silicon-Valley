/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:21:41 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/18 17:42:23 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*anchor;

	if (!(*needle))
		return ((char *)haystack);
	i = -1;
	while (++i < len && haystack[i])
		if (haystack[i] == needle[0])
		{
			j = 0;
			anchor = ((char *)haystack + i);
			while (i < len && haystack[i] && needle[j] &&
				haystack[i] == needle[j])
			{
				if (needle[j + 1] == '\0')
					return (anchor);
				i++;
				j++;
			}
			if (haystack[i] == '\0')
				return (NULL);
		}
	return (NULL);
}
