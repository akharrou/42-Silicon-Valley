/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 09:48:40 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/02 15:13:49 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/stdlib_42.h"
#include "../Includes/string_42.h"
#include "../Includes/stdint_42.h"
#include "../Includes/macros_42.h"

#define BIAS          16383
#define BITSIZE       63
#define _15BITS       32767
#define MAX_EXPONENT  32767

#define ZERO          (num.exponent == 0 && num.mantissa == 0)
#define INF           (num.exponent == MAX_EXPONENT && num.mantissa == 0)
#define NAN_          (num.exponent == MAX_EXPONENT && num.mantissa != 0)

char	*ft_ldtoa_base(long double n, char *base, int width, int precision)
{
	t_long_double	num;
	char			*res;

	num.ldbl_.val = n;
	num.sign = num.ldbl_.body[9] >> 7 != 0;
	num.exponent = (*(short *)&num.ldbl_.body[8] & _15BITS) - BIAS - BITSIZE;
	num.mantissa = *(intmax_t *)num.ldbl_.body;
	if (ZERO)
		return ((num.sign) ? ft_strdup("0") : ft_strdup("-0"));
	if (INF)
		return ((num.sign) ? ft_strdup("inf") : ft_strdup("-inf"));
	if (NAN_)
		return (ft_strdup("nan"));
	res = ft_utoa_base(num.mantissa, DECIMAL_BASE, 0);
	while (num.exponent > 0)
	{
		res = ft_strmul(res, base, 2);
		--num.exponent;
	}
	while (num.exponent++ < 0)
		res = ft_strdiv(res, base, 2);
	res = ft_strround(ft_str_lstrip(res, "0"), base, precision);
	res = ft_strprepend(res, ft_padding(width, '0'), 1, 1);
	res = (num.sign) ? ft_strprepend(res, "-", 1, 0) : res;
	return (res);
}

/** TODO
 *
 * 	norm
 *  test
 *
 *  do the doubles version
 */

/*
 *
 * TEST MAIN
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

int		main(int ac, char *av[])
{
	if (ac != )
	{
		printf("Usage: ./a \n");
		return (1);
	}


	printf("%s\n", );


	return (0);
}
