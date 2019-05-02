/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 19:57:25 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/01 19:57:28 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/stdlib_42.h"
#include "../Includes/string_42.h"
#include "../Includes/macros_42.h"

char		*ft_strmul(char *numstr, char *base, int multiplier)
{
	int		intbase;
	int		carry;
	char	tmp;
	int		i;

	intbase = ft_strlen(base);
	carry = 0;
	i = ft_strlen(numstr);
	while (--i >= 0)
	{
		if (numstr[i] == '.')
			--i;
		tmp = numstr[i];
		numstr[i] = (INT(numstr[i], base) * multiplier + carry) % intbase;
		carry = ((INT(tmp, base) * multiplier) + carry) / intbase;
	}
	if (carry)
		numstr = ft_strappend(numstr, ft_itoa(carry), 1, 1);
	return (numstr);
}
