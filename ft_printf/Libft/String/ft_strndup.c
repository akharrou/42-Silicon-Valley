/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 12:23:59 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/16 12:33:28 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/stdlib_42.h"
#include "../Includes/string_42.h"

char	*ft_strndup(const char *src, size_t n)
{
	size_t	len;
	char	*dst;

	dst = NULL;
	if (src)
	{
		len = ft_strnlen(src, n);
		dst = (char *)malloc(len + 1);
		if (!dst)
			return (NULL);
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
