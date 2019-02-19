/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 07:11:34 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/18 14:30:17 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src < dst)
	{
		src = src + len - 1;
		dst = dst + len - 1;
		while (len-- > 0)
			((char *)dst)[len] = ((char *)src)[len];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
