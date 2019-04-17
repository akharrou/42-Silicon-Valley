/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 07:25:53 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/17 01:47:13 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/stdlib_42.h"
#include "../Includes/string_42.h"
#include "../Includes/math_42.h"
#include "../Includes/macros.h"

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


char	*ft_itoa(long long n)
{
	char	*head;
	char	*buf;
	int		col;

	col = ft_intlen(n) + ((n <= 0) ? 1 : 0);
	buf = malloc(col + 1);
	if (!buf)
		return (NULL);
	head = buf;
	if (n >= 0)
		n = n * -1;
	else
	{
		*buf++ = '-';
		col--;
	}
	*(buf + col) = '\0';
	while (col > 0)
	{
		*(buf + col - 1) = ((n % 10) * -1) + '0';
		n = n / 10;
		col--;
	}
	return (head);
}
