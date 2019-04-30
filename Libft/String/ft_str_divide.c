/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_divide.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 10:23:10 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/30 11:05:28 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/string_42.h"

char		*ft_str_divide(char *numstr, char *base, int divider)
{
	int		carry_over;
	int		prev_carry;
	int		intbase;
	int		len;
	int		i;

	intbase = ft_strlen(base);
	len = ft_strlen(numstr);
	carry_over = 0;
	i = -1;
	while (++i < len && numstr[i] != '.')
	{
		prev_carry = (numstr[i] - '0') % divider * intbase;
		numstr[i] = base[(numstr[i] - '0' + carry_over) / divider % intbase];
		carry_over = prev_carry;
	}
	if ((carry_over || i < len) && numstr[i] != '.')
		numstr = ft_strappend(numstr, ".", 1, 0);
	while (carry_over || ++i < len)
	{
		if (carry_over && numstr[i] == '\0')
			numstr = ft_strappend(numstr, "0", 1, 0);
		prev_carry = (numstr[i] - '0') % divider * intbase;
		numstr[i] = base[(numstr[i] - '0' + carry_over) / divider % intbase];
		carry_over = prev_carry;
	}
	return (numstr);
}
