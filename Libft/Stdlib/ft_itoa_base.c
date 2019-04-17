/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:08:52 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/17 06:31:56 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/stdlib_42.h"
#include "../Includes/string_42.h"

char	*ft_itoa_base(int n, char *base, int padding, char pad)
{
	unsigned short	intbase;
	unsigned short	col;
	unsigned int	val;
	char			*buf;

	if (!valid_base(base))
		return (NULL);
	col = ft_intlen_base(n, ft_strlen(base)) + (n < 0);
	padding = (padding - col > 0) ? padding - col : 0;
	col += padding;
	if (!(buf = malloc(col + 1)))
		return (NULL);
	buf = ft_memset(buf, pad, col);
	buf[col] = '\0';
	intbase = ft_strlen(base);
	val = (n < 0) ? -n : n;
	while (col - padding > 0)
	{
		buf[--col] = base[val % intbase];
		val /= intbase;
	}
	if (n < 0)
		(*buf) = '-';
	return (buf);
}
