/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 09:48:40 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/02 18:09:52 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

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
		res = ft_strmulfre(res, base, 2, 1);
		printf("%s\n", res);
		--num.exponent;
	}
	while (num.exponent++ < 0)
	{
		res = ft_strdivfre(res, base, 2, 1);
		printf("%s\n", res);
	}
	res = ft_strround(ft_str_lstrip(res, "0"), base, precision);
	res = ft_strprepend(res, ft_padding(width - ft_strlen(res), '0'), 1, 1);
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

int	main(void)
{

	printf("\nOURS: %s\n", ft_ldtoa_base(-15615616500604605640465156702785215045627502678025401562756107861275617501756280675801561685401675127802.106577568068517810765107851705167, DECIMAL_BASE, 0, 0));
	printf("REAL: %.f\n", -15615616500604605640465156702785215045627502678025401562756107861275617501756280675801561685401675127802.106577568068517810765107851705167);

	return (0);
}
