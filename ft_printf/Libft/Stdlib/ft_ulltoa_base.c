/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 06:29:21 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/17 06:31:35 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/stdlib_42.h"
#include "../Includes/string_42.h"

char	*ft_ulltoa_base(unsigned long long n, char *base, int padding, char pad)
{
	unsigned short	intbase;
	unsigned short	col;
	char			*buf;

	if (!valid_base(base))
		return (NULL);
	col = ft_intlen_base(n, ft_strlen(base));
	padding = (padding - col > 0) ? padding - col : 0;
	col += padding;
	if (!(buf = malloc(col + 1)))
		return (NULL);
	buf = ft_memset(buf, pad, col);
	buf[col] = '\0';
	intbase = ft_strlen(base);
	while (col - padding > 0)
	{
		buf[--col] = base[n % intbase];
		n /= intbase;
	}
	return (buf);
}
