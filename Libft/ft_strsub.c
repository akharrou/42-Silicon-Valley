/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 07:25:03 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/19 18:15:39 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int		i;
	unsigned int		end;
	char				*dst;

	end = start + len;
	if (!(dst = (char *)malloc(end - start + 1)))
		return (NULL);
	i = 0;
	while (start < end)
		dst[i++] = s[start++];
	dst[i] = '\0';
	return (dst);
}
