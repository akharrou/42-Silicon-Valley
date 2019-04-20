/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:51:50 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/20 12:13:12 by akharrou         ###   ########.fr       */
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

t_char	*r_handler(t_format format)
{
	t_char	*fstr;
	t_int32 i;

	i = 0;

	fstr = ft_strdup((t_char *)format.data.str);

	if (!fstr)
		exit(-1);
	if (format.precision != NONE)
		if (0 < format.precision && format.precision < (long)ft_strlen(fstr))
			fstr[format.precision] = '\0';
	return (fstr);
}
