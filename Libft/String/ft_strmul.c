/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 19:57:25 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/02 18:13:47 by akharrou         ###   ########.fr       */
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

	numstr = ft_strdup(numstr);
	intbase = ft_strlen(base);
	carry = 0;
	i = ft_strlen(numstr);
	while (--i >= 0)
	{
		if (numstr[i] == '.')
			--i;
		tmp = numstr[i];
		numstr[i] = base[(INT(numstr[i], base) * multiplier + carry) % intbase];
		carry = ((INT(tmp, base) * multiplier) + carry) / intbase;
	}
	if (carry)
		numstr = ft_strprepend(numstr, ft_itoa(carry), 1, 1);
	return (numstr);
}

/*
**    DESCRIPTION
**         Wrapper function that allows to clean up & free certain variables
**         after function execution.
**
**    PARAMETERS
**
**         int free_numstr         Integer (boolean) to signal whether
**                                 or not to free the variable(s).
**
**    FREE'D PARAMETERS
**
**         - char *numstr
*/

char		*ft_strmulfre(char *numstr, char *base, int multiplier,
				int free_numstr)
{
	char	*res;

	res = ft_strmul(numstr, base, multiplier);
	if (free_numstr && numstr)
		free((void *)numstr);
	return (res);
}
