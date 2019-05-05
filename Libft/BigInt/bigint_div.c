/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_div.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 19:57:44 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/04 19:48:25 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/string_42.h"
#include "../Includes/stdlib_42.h"
#include "../Includes/macros_42.h"

#include "../Includes/bigint.h"

/* FIXME norm function, get under 25 lines */
t_bigint	bigint_div(t_bigint num, char *base, int divider)
{
	int		intbase;
	int		carry;
	int		sum;
	int		i;

	num = ft_strdup(num);
	intbase = ft_strlen(base);
	carry = 0;
	i = 0;
	while (num[i] && num[i] != '.')
	{
		sum = carry + INT(num[i], base);
		num[i++] = base[sum / divider];
		carry = sum % divider * intbase;
	}
	if (carry && num[i] != '.')
		num = ft_strappend(num, ".", 1, 0);
	i += (num[i] == '.');
	while (num[i] || carry)
	{
		if (carry && num[i] == '\0')
			num = ft_strappend(num, "0", 1, 0);
		sum = carry + INT(num[i], base);
		num[i++] = base[sum / divider];
		carry = sum % divider * intbase;
	}
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
**         - t_bigint num
*/

t_bigint	bigint_divfre(t_bigint num, char *base, int divider,
				int free_num)
{
	t_bigint	res;

	res = bigint_div(num, base, divider);
	if (free_num && num)
		free((void *)num);
	return (res);
}
