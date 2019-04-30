/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 09:48:40 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/29 19:26:40 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/stdlib_42.h"
#include "../Includes/string_42.h"

#define SENTINAL 1
#define DOT 1

// static char	*get_precision(long double n, char *base, int precision)
// {
// 	int		i;
// 	int		val;
// 	int		intbase;
// 	char	*precision_str;

// 	precision_str = ft_memalloc(DOT + precision + SENTINAL);
// 	if (!precision_str)
// 		return (NULL);
// 	precision_str[0] = '.';
// 	intbase = ft_strlen(base);
// 	val = 0;
// 	i = 0;
// 	while (precision > i++)
// 	{
// 		n = (n - val) * intbase;
// 		val = (int)n;
// 		if (precision == i)
// 			val = val + ((int)((n - val) * intbase > 5) ? 1 : 0);
// 		precision_str[i] = base[val % intbase];
// 	}
// 	return (precision_str);
// }

// char		*ft_dtoa_base(double n, char *base, int width, int precision)
// {
// 	unsigned long long	val;
// 	int					bodylen;
// 	int					sign;
// 	char				*fltstr;

// 	sign = (*(uintmax_t *)&n) >> 63;
// 	n = (sign) ? -n : n;
// 	val = (unsigned long long)n;
// 	precision = ((precision >= 0) ? precision : 6);
// 	bodylen = sign + ft_uintmaxlen_base(val, 10) + precision;
// 	width -= (width - bodylen > 0) ? width - bodylen : 0;
// 	if (!(fltstr = ft_memalloc(width + bodylen + SENTINAL)))
// 		return (NULL);
// 	fltstr[0] = '-';
// 	ft_memset(fltstr + sign, '0', width);
// 	fltstr = ft_strcpyfre(
// 		fltstr + sign + width, ft_utoa_base(val, base, -1), 0, 1);
// 	if (precision)
// 		fltstr = ft_strcatfre(
// 			fltstr, get_precision(n - val, base, precision), 0, 1);
// 	return (fltstr);
// }

















