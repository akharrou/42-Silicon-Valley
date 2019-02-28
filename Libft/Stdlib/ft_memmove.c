/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 07:11:34 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/27 16:43:49 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *src_chr_p;
	unsigned char *dst_chr_p;

	src_chr_p = (unsigned char *)src;
	dst_chr_p = (unsigned char *)dst;
	if (src < dst)
	{
		src_chr_p = src_chr_p + len - 1;
		dst_chr_p = dst_chr_p + len - 1;
		while (len-- > 0)
			*dst_chr_p-- = *src_chr_p--;
	}
	else
		while (len-- > 0)
			*dst_chr_p++ = *src_chr_p++;
	return (dst);
}
