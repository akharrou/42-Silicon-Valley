/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:20:16 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/18 11:41:35 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/stdlib_42.h"
#include "../Includes/string_42.h"
#include "../Includes/math_42.h"

long double		ft_round(long double n)
{
	long double tmp;

	tmp = n / 10;
	tmp -= (unsigned long long)tmp;
	tmp = (tmp < 0) ? -tmp : tmp;
	if (tmp >= 0.5)
		return (n + 1);
	return (n);
}

char	*ft_ftoa_base(long double n, char *base, int width, int precision)
{
	unsigned long long	val;
	int					sign;
	char				*float_str;
	char				*tmp_str;
	char				*pad_str;

	float_str = NULL;
	sign = (n < 0);
	n = (n < 0) ? -n : n;
	val = (unsigned long long)n;
	float_str = ft_strjoin(float_str, ft_ulltoa_base(val, base, -1));
	tmp_str = float_str;
	precision = ((precision >= 0) ? precision : 6);
	if (precision)
	{
		float_str = ft_strjoin(float_str, ".");
		free(tmp_str);
		tmp_str = float_str;
		val = ((n - (unsigned long long)n)) * ft_powl(10, precision);
		val = ft_round((long double)val);
		float_str = ft_strjoin(float_str, ft_ulltoa_base(val, base, precision));
		free(tmp_str);
		tmp_str = float_str;
	}
	pad_str = ft_padding(width - ft_strlen(float_str) - sign, '0');
	float_str = ft_strjoin(pad_str, float_str);
	free(pad_str);
	free(tmp_str);
	tmp_str = float_str;
	float_str = ft_strjoin((sign) ? "-" : "", float_str);
	free(tmp_str);
	return (float_str);
}

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

	printf("%s\n", ft_ftoa_base((long double)12.126, "0123456789", 0, 18));
	printf("%00.18Lf\n", (long double)12.126);

	(void)ac;
	(void)av;

	return (0);
}
