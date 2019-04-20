/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:52:28 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/18 21:57:14 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         f_handler -- formatted floating point number conversion
**
**    SYNOPSIS
**         #include <libft.h>
**
**         t_char	*
**         f_handler(t_format format);
**
**    PARAMETERS
**
**         t_format format         Structure containing the variable
**                                 and information about how it must
**                                 be formatted.
**
**    DESCRIPTION
**         Handles the '%f' specifier like the libc 'printf()' function.
**
**         Note: the only flags and fields that apply to this specifier
**         are the following:
**
**             Flags: '-', '+', ' ', '0'
**             Width: defined or '*'
**             Precision: defined or '*'
**             Length: 'L'
**
**
**    RETURN VALUES
**         If successful, returns a formatted string that follows the
**         specified format; otherwise exits with a -1 on error.
*/

#include "../ft_printf.h"

t_char	*f_handler(t_format format)
{
	t_char	*fltstr;

	fltstr = ft_ftoa_base(
		(long double)format.data.dble, DECIMAL_BASE, -1, format.precision);
	if (format.flags & PLUS && !ft_strchr(fltstr, '-'))
		fltstr = ft_strprepend(fltstr, "+", 1, 0);
	if (format.flags & SPACE && !ft_strchr(fltstr, '-'))
		fltstr = ft_strprepend(fltstr, " ", 1, 0);
	return (fltstr);
}
