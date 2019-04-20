/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:52:39 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/17 06:57:33 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         p_handler -- formatted address conversion
**
**    SYNOPSIS
**         #include <libft.h>
**
**         t_char	*
**         p_handler(t_format format);
**
**    PARAMETERS
**
**         t_format format         Structure containing the variable
**                                 and information about how it must
**                                 be formatted.
**
**    DESCRIPTION
**         Handles the '%p' specifier like the libc 'printf()' function.
**
**         Note: the only flags and fields that apply to this specifier
**         are the following:
**
**             Flags: '-'
**             Width: defined or '*'
**
**
**    RETURN VALUES
**         If successful, returns a formatted string that follows the
**         specified format; otherwise exits with a -1 on error.
*/

#include "../ft_printf.h"

t_char	*p_handler(t_format format)
{
	t_char	*addr;

	addr = ft_utoa_base(
		(uintmax_t)format.data.ptr, HEX_LOWER_BASE, format.precision);
	addr = ft_strprepend(addr, "0x", 1, 0);
	if (!addr)
		exit (-1);
	return (addr);
}
