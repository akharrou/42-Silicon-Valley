/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:56:25 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/21 12:00:40 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         b_handler -- formatted binary number conversion
**
**    SYNOPSIS
**         #include <libft.h>
**
**         t_char	*
**         b_handler(t_format format);
**
**    PARAMETERS
**
**         t_format format         Structure containing the variable
**                                 and information about how it must
**                                 be formatted.
**
**    DESCRIPTION
**         Handles the '%b' specifier; binary number conversion, similar
**         to the hexadecimal or octal or decimal conversions.
**
**         Note: the only flags and fields that apply to this specifier
**         are the following:
**
**             Flags: '-', '+', ' ', '0', '#'
**             Width: defined or '*'
**             Precision: defined or '*'
**             Length: 'hh', 'h', 'l', 'll'
**
**
**    RETURN VALUES
**         If successful, returns a formatted string that follows the
**         specified format; otherwise exits with a -1 on error.
*/

#include "../ft_printf.h"

t_char	*b_handler(t_format format)
{
	t_char	*intstr;

	intstr = (format.length < L) ?
		ft_itoa_base(format.data.intgr, BINARY_BASE, format.precision) :
		ft_itoa_base(format.data.intmax_t, BINARY_BASE, format.precision);
	if (format.flags & PLUS && !ft_strchr(intstr, '-'))
		intstr = ft_strprepend(intstr, "+", 1, 0);
	if (format.flags & SPACE && !ft_strchr(intstr, '-'))
		intstr = ft_strprepend(intstr, " ", 1, 0);
	if (format.flags & HASH)
		intstr = ft_strprepend(intstr, "0b", 1, 0);
	return (intstr);
}
