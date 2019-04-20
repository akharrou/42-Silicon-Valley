/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:52:33 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/17 00:34:20 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         d_handler -- formatted decimal number conversion
**
**    SYNOPSIS
**         #include <libft.h>
**
**         t_char	*
**         d_handler(t_format format);
**
**    PARAMETERS
**
**         t_format format         Structure containing the variable
**                                 and information about how it must
**                                 be formatted.
**
**    DESCRIPTION
**         Handles the '%d' specifier like the libc 'printf()' function.
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

t_char	*d_handler(t_format format)
{
	return (i_handler(format));
}
