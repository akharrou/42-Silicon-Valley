/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 09:48:40 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/05 22:27:27 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/stdlib_42.h"
#include "../Includes/string_42.h"
#include "../Includes/stdint_42.h"
#include "../Includes/macros_42.h"
#include "../Includes/bigint.h"

#define BIAS          1023
#define BITSIZE       52
#define _11BITS       2047
#define MAX_EXPONENT  2047 - BIAS - BITSIZE
#define EMPTY         9223372036854775808u

#define ZERO          (num.exponent == 0 - BIAS - BITSIZE && num.mantissa == 0)
#define INF           (num.exponent == MAX_EXPONENT && num.mantissa == EMPTY)
#define NAN_          (num.exponent == MAX_EXPONENT && num.mantissa != EMPTY)

/* TODO adjust the MACRO values to make it work. & test it */
/* TODO finish the printf and integrate it with the libft */
/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —  */
char	*parse_double(char *neg, int *exp, unsigned long long *man,
							t_float *a)
{
	*neg = a->num >> 63;
	*exp = ((a->num << 1) >> 53) - 1023 - 52;
	*man = (a->num & ((1L << 52) - 1));
	if (*exp == 2047 - 1023 - 52)
	{
		if (*man)
			return (ft_strdup("nan"));
		return (ft_strdup("inf"));
	}
	if (*exp != -1075)
		*man += 1L << 52;
	else
		(*exp)++;
	return (NULL);
}
/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —  */

char			*ft_dtoa_base(double n, char *base, int width, int precision)
{
	t_double	num;
	char		*res;

	num.sign = *(uintmax_t *)&n >> 63;
	num.exponent = (*(uintmax_t *)&n << 1 >> 53) - BIAS - BITSIZE;
	num.mantissa = *(uintmax_t *)&n << 12 >> 12;
	if (ZERO)
		return (bigint_roundfre(
			(num.sign) ? ft_strdup("-0") : ft_strdup("0"), base, precision, 1));
	else if (INF)
		return (ft_strdup("inf"));
	else if (NAN_)
		return (ft_strdup("nan"));
	res = ft_utoa_base(num.mantissa, DECIMAL_BASE, 0);
	if (num.exponent > 0)
		while (num.exponent-- > 0)
			res = bigint_mulfre(res, 2, base, 1);
	else
		while (num.exponent++ < 0)
			res = bigint_divfre(res, 2, base, 1);
	res = ft_strnlstrip(res, "0", ft_strchr(res, '.') - res - 1);
	res = bigint_round(res, base, precision);
	res = ft_strprepend(res, ft_padding(width - ft_strlen(res), '0'), 1, 1);
	return ((num.sign) ? ft_strprepend(res, "-", 1, 0) : res);
}

#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

int	main(void) /* TODO test function */
{

	// printf("\nOURS: %s\n", ft_ldtoa_base(0.237, DECIMAL_BASE, 0, 100));
	// printf("REAL: %.100f\n", 0.237);

	// printf("\nOURS: %s\n", ft_ldtoa_base(0.237230242307247273461251390614, DECIMAL_BASE, 0, 100));
	// printf("REAL: %.100f\n", 0.237230242307247273461251390614);

	// printf("\nOURS: %s\n", ft_ldtoa_base(237230242307247273461251390614.283762034623, DECIMAL_BASE, 0, 100));
	// printf("REAL: %.100f\n", 237230242307247273461251390614.283762034623);

	// printf("\nOURS: %s\n", ft_ldtoa_base(0.237, DECIMAL_BASE, 0, 4));
	// printf("REAL: %.4f\n", 0.237);

	// printf("\nOURS: %s\n", ft_ldtoa_base(-15615616500604605640465156702785215045627502678025401562756107861275617501756280675801561685401675127802.106577568068517810765107851705167, DECIMAL_BASE, 0, 1000));
	// printf("REAL: %.1000f\n", -15615616500604605640465156702785215045627502678025401562756107861275617501756280675801561685401675127802.106577568068517810765107851705167);

	// printf("\nOURS: %s\n", ft_ldtoa_base(-0.106577568068517810765107851705167, DECIMAL_BASE, 0, 1000));
	// printf("REAL: %.1000f\n", -0.106577568068517810765107851705167);

	// printf("\nOURS: %s\n", ft_ldtoa_base(-340282346638528859811704183484516925440.000000, DECIMAL_BASE, 0, 0));
	// printf("REAL: %.0f\n", -340282346638528859811704183484516925440.000000);

	// printf("\nOURS: %s\n", ft_ldtoa_base(LDBL_MAX, DECIMAL_BASE, 0, 0));
	// printf("REAL: %.0Lf\n", LDBL_MAX);

	// printf("\nOURS: %s\n", ft_ldtoa_base(LDBL_MIN, DECIMAL_BASE, 0, 2));
	// printf("REAL: %.2Lf\n", LDBL_MIN);

	// printf("\nOURS: %s\n", ft_ldtoa_base(1.0 / 0.0, DECIMAL_BASE, 0, 0));
	// printf("REAL: %.0f\n", 1.0 / 0.0);

	// printf("\nOURS: %s\n", ft_ldtoa_base(1.0 / 3.0, DECIMAL_BASE, 0, 0));
	// printf("REAL: %.0f\n", 1.0 / 3.0);

	// printf("\nOURS: %s\n", ft_ldtoa_base(0.0, DECIMAL_BASE, 0, 0));
	// printf("REAL: %.0f\n", 0.0);

	// printf("\nOURS: %s\n", ft_ldtoa_base(-0.0, DECIMAL_BASE, 0, 0));
	// printf("REAL: %.0f\n", -0.0);

	return (0);
}
