/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 07:25:17 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/25 23:50:56 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/stdlib_42.h"
#include "../Includes/string_42.h"

char		*ft_strnjoin(char const *dst, char const *src, size_t len)
{
	char	*new_str;
	size_t	dst_len;
	size_t	src_len;

	if (len < 1 && (!dst && !src))
		return (NULL);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (len > dst_len + src_len)
		len = dst_len + src_len;
	if (!(new_str = malloc(len + 1)))
		return (NULL);
	new_str = ft_strncat(new_str, dst, len);
	if (len - dst_len > 0)
		new_str = ft_strncat(new_str, src, len - dst_len);
	return (new_str);
}
