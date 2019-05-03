/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdiv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 19:57:44 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/02 17:50:55 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         ft_strdiv -- divide a number (that is in the form of a string)
**
**    SYNOPSIS
**         #include <libft.h>
**
**         char *
**         ft_strdiv(char *numstr, char *base, int divider);
**
**    PARAMETERS
**
**         char *numstr          Brief
**
**         char *base            Brief
**
**         int divider           Brief
**
**    DESCRIPTION
**         Description.
**
**    RETURN VALUES
**         If successful returns 0; otherwise -1.
*/

#include "../Includes/string_42.h"
#include "../Includes/stdlib_42.h"
#include "../Includes/macros_42.h"

char		*ft_strdiv(char *numstr, char *base, int divider)
{
	int		intbase;
	int		carry;
	int		i;
	char	tmp;

	numstr = ft_strdup(numstr);
	intbase = ft_strlen(base);
	carry = 0;
	i = -1;
	while (numstr[++i] && numstr[i] != '.')
	{
		tmp = numstr[i];
		numstr[i] = base[(carry + INT(numstr[i], base)) / divider];
		carry = (carry + INT(tmp, base)) % divider * intbase;
	}
	if (carry && numstr[i] != '.')
		numstr = ft_strappend(numstr, ".", 1, 0);
	i += (numstr[i] == '.');
	while (numstr[i] || carry)
	{
		if (carry && numstr[i] == '\0')
			numstr = ft_strappend(numstr, "0", 1, 0);
		tmp = numstr[i];
		numstr[i] = base[(carry + INT(numstr[i], base)) / divider];
		carry = (carry + INT(tmp, base)) % divider * intbase;
		++i;
	}
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

char		*ft_strdivfre(char *numstr, char *base, int divider,
				int free_numstr)
{
	char	*res;

	res = ft_strdiv(numstr, base, divider);
	if (free_numstr && numstr)
		free((void *)numstr);
	return (res);
}
