/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:41:09 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/30 10:26:17 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/stdlib_42.h"
#include "../Includes/string_42.h"
#include "../Includes/math_42.h"
#include "../Includes/macros_42.h"

char	*ft_ftoa_base(float n, char *base, int width, int precision)
{
	unsigned long long	val;
	int					sign;
	char				*fltstr;

	fltstr = NULL;
	sign = (n < 0);
	n = (n < 0) ? -n : n;
	val = (unsigned long long)n;
	fltstr = ft_strappend(fltstr, ft_utoa_base(val, base, -1), 0, 1);
	precision = ((precision >= 0) ? precision : 6);
	if (precision)
	{
		fltstr = ft_strappend(fltstr, ".", 1, 0);
		val = ((n - (unsigned long long)n)) * ft_powl(
			10, precision + (precision < 20));
		if (precision < 20)
			val = ft_round_with_prior((float)val);
		fltstr = ft_strappend(
			fltstr, ft_utoa_base(val, base, precision), 1, 1);
	}
	fltstr = ft_strappend(
		fltstr, ft_padding(width - ft_strlen(fltstr) - sign, '0'), 1, 1);
	fltstr = ft_strprepend(fltstr, ((sign) ? "-" : ""), 1, 0);
	return (fltstr);
}
