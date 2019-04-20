/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:51:50 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/20 15:37:03 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#include "../ft_printf.h"

t_char	*r_handler(t_format format)
{
	t_int32 i;
	t_char	*fstr;

	if (format.data.str == NULL)
		return (ft_strdup("(null)"));
	i = -1;
	fstr = NULL;
	if (format.precision == NONE)
		format.precision = ft_strlen(format.data.str);
	while (format.data.str[++i] && i < format.precision)
	{
		if (ISPRINT(format.data.str[i]))
			fstr = ft_strappend(
				fstr, ft_strndup(format.data.str + i, 1), 1, 1);
		else
			fstr = ft_strappend(
				fstr,
				ft_strprepend(
					ft_itoa_base(format.data.str[i], HEX_LOWER_BASE, 2),
					"\\x",
					1, 0),
				1, 1);
	}
	return (fstr);
}
