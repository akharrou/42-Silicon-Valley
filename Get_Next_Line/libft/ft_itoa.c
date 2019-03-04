/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 07:25:53 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/01 10:45:43 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	int		i;
	int		quotient;
	long	col;
	char	*buf;

	col = ft_intlen(n);
	if (!(buf = (char *)malloc(col + ((n <= 0) ? 1 : 0) + 1)))
		return (NULL);
	if (n == INT_MIN)
		return (ft_strcpy(buf, "-2147483648"));
	i = 0;
	buf[i] = (n < 0) ? '-' : '0';
	i = (n <= 0) ? 1 : 0;
	n = (n < 0) ? -n : n;
	col = ft_pow(10, col);
	while (col > 1)
	{
		col /= 10;
		quotient = (n / col);
		buf[i++] = quotient + '0';
		n -= (quotient * col);
	}
	buf[i] = '\0';
	return (buf);
}
