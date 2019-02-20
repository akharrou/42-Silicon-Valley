/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 07:25:53 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/19 14:37:33 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_itoa(int n)
{
	int		i;
	int		quotient;
	long	col;
	char	*buf;

	if (!(buf = (char *)malloc(ft_intlen(n) + 1)))
		return (NULL);
	if (n == INT_MIN || n == 0)
		return (n == 0) ? ft_strcpy(buf, "0") : ft_strcpy(buf, "-2147483648");
	i = 0;
	if (n < 0)
	{
		buf[i++] = '-';
		n = -n;
	}
	col = ft_pow(10, ft_intlen(n));
	while (col > 1)
	{
		col /= 10;
		quotient = (n / col);
		buf[i++] = quotient + ((quotient < 10) ? '0' : 'W');
		n -= (quotient * col);
	}
	buf[i] = '\0';
	return (buf);
}
