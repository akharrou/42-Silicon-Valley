/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:41:09 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/27 19:43:11 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/stdlib_42.h"
#include "../Includes/string_42.h"

#define FRONT_DIGITS 20
#define SENTINAL 1
#define DOT 1

char	*get_precision(long double n, char *base, int precision)
{
	int		i;
	int		val;
	int		intbase;
	char	*precision_str;

	precision_str = ft_memalloc(DOT + precision + SENTINAL);
	if (!precision_str)
		return (NULL);
	precision_str[0] = '.';
	intbase = ft_strlen(base);
	val = 0;
	i = 0;
	while (precision > i++)
	{
		n = (n - val) * intbase;
		val = (int)n;
		if (precision == i)
			val = val + ((int)((n - val) * intbase > 5) ? 1 : 0);
		precision_str[i] = base[val % intbase];
	}
	return (precision_str);
}

char	*ft_ftoa_base(long double n, char *base, int width, int precision)
{
	unsigned long long	val;
	int					bodylen;
	int					sign;
	char				*fltstr;

	sign = (n < 0);
	n = (n < 0) ? -n : n;
	val = (unsigned long long)n;
	precision = ((precision >= 0) ? precision : 6);
	bodylen = sign + ft_uintmaxlen_base(val, 10) + precision;
	width -= (width - bodylen > 0) ? width - bodylen : 0;
	if (!(fltstr = ft_memalloc(width + bodylen + SENTINAL)))
		return (NULL);
	fltstr[0] = '-';
	ft_memset(fltstr + sign, '0', width);
	fltstr = ft_strcpyfre(
		fltstr + sign + width, ft_utoa_base(val, base, -1), 0, 1);
	if (precision)
		fltstr = ft_strcat(
			fltstr, get_precision(n - val, base, precision));
	return (fltstr);
}
