/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:51:50 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/20 13:12:57 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
**    NAME
**         r_handler -- formatted printable string conversion
**
**    SYNOPSIS
**         #include <libft.h>
**
**         t_char	*
**         r_handler(t_format format);
**
**    PARAMETERS
**
**         t_format format         Structure containing the variable
**                                 and information about how it must
**                                 be formatted.
**
**    DESCRIPTION
**         Handles the '%r' specifier; prints a string of non-printable.
**         Non printable characters are printed as hexadecimal digits.
**
**         Note: the only flags and fields that apply to this specifier
**         are the following:
**
**             Flags: '-'
**             Width: defined or '*'
**             Precision: defined or '*'
**
**
**    RETURN VALUES
**         If successful, returns a formatted string that follows the
**         specified format; otherwise exits with a -1 on error.
*/

#include "../Libft/String/ft_strndup.c"
#include "../Libft/String/ft_strjoinfre.c"
#include "../Libft/String/ft_strappend.c"

t_char	*r_handler(t_format format)
{
	t_int32 i;
	t_char	*fstr;

	i = -1;
	fstr = NULL;
	while (format.data.str[++i])
	{
		if (ISPRINT(format.data.str[i]))
			fstr = ft_strappend(
				fstr, ft_strndup(format.data.str + i, 1), 1, 1);
		else
			fstr = ft_strappend(
				fstr,
				ft_strappend(ft_itoa_base(
					(int)format.data.str[i], HEX_LOWER_BASE, 2), 1, 1);, "\\x")
	}
	if (!fstr)
		exit(-1);
	if (format.precision != NONE)
		if (0 < format.precision && format.precision < (long)ft_strlen(fstr))
			fstr[format.precision] = '\0';
	return (fstr);
}
