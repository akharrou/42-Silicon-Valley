/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_multiply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 10:23:10 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/30 10:24:41 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/string_42.h"

char	*ft_str_multiply(char *numstr, char *base, int multiplier)
{
	int	carry_over;
	int	prev_carry;
	int	intbase;
	int	i;

	intbase = ft_strlen(base);
	i = ft_strlen(numstr);
	carry_over = 0;
	while (--i >= 0)
	{
		prev_carry = (numstr[i] - '0') * multiplier / intbase;
		numstr[i] = base[
			((numstr[i] - '0') * multiplier % intbase + carry_over) % intbase];
		carry_over = prev_carry;
	}
	if (carry_over)
	{
		numstr = ft_strprepend(numstr, "0", 1, 0);
		numstr[0] = base[carry_over % intbase];
	}
	return (numstr);
}
