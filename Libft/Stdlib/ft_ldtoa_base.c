/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 09:48:40 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/30 10:32:32 by akharrou         ###   ########.fr       */
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
	char			*result_str;

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
	result_str = ft_utoa_base(num.mantissa, DECIMAL_BASE, 0);
	while (num.exponent > 0)
	{
		result_str = ft_str_multiply(result_str, base, 2);
		--num.exponent;
	}
	while (num.exponent++ < 0)
		result_str = ft_str_divide(result_str, base, 2);
	result_str = ft_strtrim(result_str, "0");
	result_str = ft_str_round(result_str, base);
	result_str = ft_strprepend(result_str, ft_padding(width, '0'), 1, 1);
	return (result_str);
}

/** TODO
 *
 * 	get rid of leading zeros
 *  round number at precision with the digit before it
 *  truncate at specified precision
 * 	norm
 *  test
 *
 *  do the doubles version
 *
 *
 *  fix width with '0' / precision with pointer specifier
 */
