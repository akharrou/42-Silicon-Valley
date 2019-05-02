/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdiv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 19:57:44 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/01 19:57:47 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/string_42.h"
#include "../Includes/macros_42.h"

char		*ft_strdiv(char *numstr, char *base, int divider)
{
	int		intbase;
	int		carry;
	char	tmp;
	int		i;

	intbase = ft_strlen(base);
	i = -1;
	while (numstr[++i] && numstr[i] != '.')
	{
		tmp = numstr[i];
		numstr[i] = base[carry + INT(numstr[i], base) / divider];
		carry = carry + INT(tmp, base) % divider * intbase;
	}
	if (carry && numstr[i] != '.')
		numstr = ft_strappend(numstr, ".", 1, 0);
	while (numstr[++i] || carry)
	{
		if (carry && numstr[i] == '\0')
			ft_strappend(numstr, "0", 1, 0);
		tmp = numstr[i];
		numstr[i] = base[carry + INT(numstr[i], base) / divider];
		carry = carry + INT(tmp, base) % divider * intbase;
	}
	return (numstr);
}
