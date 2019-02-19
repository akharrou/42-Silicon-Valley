/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:16:10 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/18 17:27:21 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	char	*anchor;

	if (!(*needle))
		return ((char *)haystack);
	i = -1;
	while (haystack[++i])
		if (haystack[i] == needle[0])
		{
			j = 0;
			anchor = ((char *)haystack + i);
			while (haystack[i] && needle[j] && haystack[i] == needle[j])
			{
				if (needle[j + 1] == '\0')
					return (anchor);
				i++;
				j++;
			}
			if (!haystack[i])
				return (NULL);
		}
	return (NULL);
}
