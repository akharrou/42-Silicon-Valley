/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_round.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 10:26:49 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/04 19:32:48 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/string_42.h"
#include "../Includes/stdlib_42.h"
#include "../Includes/macros_42.h"

#include "../Includes/bigint.h"

t_bigint	bigint_round(t_bigint num, char *base, int precision)
{
	char	*incrementor;
	char	*decimalpt;
	int		decimals;
	int		len;

	num = ft_strdup(num);
	if (!ft_strchr(num, '.'))
		num = ft_strappend(num, ".000000", 1, 0);
	len = ft_strlen(num);
	decimalpt = ft_strchr(num, '.');
	decimals = (len - 1) - (decimalpt - num);
	if (precision < 1)
		return (ft_strndupfre(num, len - (decimals + 1), 1));
	else if (decimals <= precision)
		num = ft_strappend(
			num, ft_padding(precision - decimals, '0'), 1, 1);
	else if (INT(decimalpt[precision + 1], base) >= (long)ft_strlen(base) / 2)
	{
		incrementor = ft_strappend(ft_strappend(
			ft_strdup("0."), ft_padding(precision - 1, '0'), 1, 1), "1", 1, 0);
		num = bigint_addfre(num, incrementor, base, 3);
	}
	num[(ft_strchr(num, '.') - num) + 1 + precision] = '\0';
	return (num);
}

/*
**    DESCRIPTION
**         Wrapper function that allows to clean up & free certain variables
**         after function execution.
**
**    PARAMETERS
**
**         int free_num         Integer (boolean) to signal whether
**                                 or not to free the variable(s).
**
**    FREE'D PARAMETERS
**
**         - bigint num
*/

t_bigint		bigint_roundfre(t_bigint num, char *base, int precision,
					int free_num)
{
	t_bigint	res;

	res = bigint_round(num, base, precision);
	if (free_num && num)
		free((void *)num);
	return (res);
}
