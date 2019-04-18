/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 06:29:21 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/17 22:16:50 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/stdlib_42.h"
#include "../Includes/string_42.h"

size_t	ft_doublelen_base(double n, unsigned int base)
{
	double	num;
	size_t	length;

	length = 1;
	num = (n < 0) ? -n : n;
	while (num >= base)
	{
		num /= base;
		++length;
	}
	return (length);
}

char	*ft_dtoa_base(double n, char *base, int precision)
{
	unsigned long long	intbase;
	unsigned short		col;
	char				*buf;

	if (!valid_base(base))
		return (NULL);
	col = ft_doublelen_base(n, ft_strlen(base)) + (n < 0);
	precision = (precision - col > 0) ? precision - col : 0;
	col += precision;
	if (!(buf = malloc(col + 1)))
		return (NULL);
	buf = ft_memset(buf, '0', col);
	buf[col] = '\0';
	intbase = ft_strlen(base);
	n = (n < 0) ? -n : n;
	while (col - precision > 0)
	{
		buf[--col] = base[(unsigned long long)n % intbase];
		n /= intbase;
	}
	if (n < 0)
		(*buf) = '-';
	return (buf);
}


/* FT_ITOA_BASE TESTING */

/*
 *
 * TEST MAIN
 *
 */

#include "../Includes/macros.h"
#include <stdio.h>

int		main(int ac, char *av[])
{
	if (ac != 5)
	{
		printf("Usage: ./a integer base_system padding pad\n");
		return (1);
	}

	printf("%s\n", ft_dtoa_base(USHORT_MAX, av[2], -1));
	printf("%s\n", ft_dtoa_base(UINT_MAX, av[2], -1));
	printf("%s\n", ft_dtoa_base(922337203685477580.0, av[2], -1));
	printf("%s\n", ft_dtoa_base(184467440737095516.0, av[2], -1));

	printf("\n");

	printf("%s\n", ft_dtoa_base(SHORT_MIN, av[2], -1));
	printf("%s\n", ft_dtoa_base(INT_MIN, av[2], -1));
	printf("%s\n", ft_dtoa_base(-9223372036854775808.0, av[2], -1));
	printf("%s\n", ft_dtoa_base(-184467440737095516.0, av[2], -1));

	printf("\n");

	printf("%f\n", 65535.0);
	printf("%f\n", 4294967295.0);
	printf("%f\n", 92233720368547798732.0);
	printf("%f\n", 184467440737095516241.0);

	printf("\n");

	printf("%f\n", -32768.0);
	printf("%f\n", -2147483648.0);
	printf("%f\n", -9223372036854775808.0);
	printf("%f\n", -184467440737095516167.0);


	// printf("%s\n", ft_itoa_base(2147483647, "01", 0, 0));
	// printf("%s\n", ft_itoa_base(2147483647, "01234567", 0, 0));
	// printf("%s\n", ft_itoa_base(2147483647, "0123456789", 0, 0));
	// printf("%s\n", ft_itoa_base(2147483647, "0123456789ABCDEF", 0, 0));

	// printf("%s\n", ft_itoa_base(-2147483648, "01", 0, 0));
	// printf("%s\n", ft_itoa_base(-2147483648, "01234567", 0, 0));
	// printf("%s\n", ft_itoa_base(-2147483648, "0123456789", 0, 0));
	// printf("%s\n", ft_itoa_base(-2147483648, "0123456789ABCDEF", 0, 0));

	// printf("%s\n", ft_itoa_base(90, "01", 5, '0'));
	// printf("%s\n", ft_itoa_base(90, "01234567", 5, '0'));
	// printf("%s\n", ft_itoa_base(90, "0123456789", 5, '0'));
	// printf("%s\n", ft_itoa_base(90, "0123456789ABCDEF", 5, '0'));

	// printf("%s\n", ft_itoa_base(-0, "0123456789", 0, 0));
	// printf("%s\n", ft_itoa_base(+0, "0123456789", 0, 0));
	// printf("%s\n", ft_itoa_base(+1, "0123456789", 0, 0));
	// printf("%s\n", ft_itoa_base(-1, "0123456789", 0, 0));
	// printf("%s\n", ft_itoa_base(+2, "0123456789", 0, 0));
	// printf("%s\n", ft_itoa_base(-2, "0123456789", 0, 0));
	// printf("%s\n", ft_itoa_base(+3, "0123456789", 0, 0));
	// printf("%s\n", ft_itoa_base(-3, "0123456789", 0, 0));

	// printf("%s\n", ft_itoa_base(+1000, "0123456789", 5, '_'));
	// printf("%s\n", ft_itoa_base(-1000, "0123456789", 5, '_'));

	(void)ac;
	(void)av;

	return (0);
}
