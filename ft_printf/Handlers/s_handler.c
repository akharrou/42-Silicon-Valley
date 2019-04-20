/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:51:50 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/20 12:39:01 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
**    NAME
**         s_handler -- formatted string conversion
**
**    SYNOPSIS
**         #include <libft.h>
**
**         t_char	*
**         s_handler(t_format format);
**
**    PARAMETERS
**
**         t_format format         Structure containing the variable
**                                 and information about how it must
**                                 be formatted.
**
**    DESCRIPTION
**         Handles the '%s' specifier like the libc 'printf()' function.
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

t_char	*s_handler(t_format format)
{
	t_char	*fstr;

	fstr = (format.data.str != NULL) ?
		ft_strdup(format.data.str):
		ft_strdup("(null)");
	if (format.precision != NONE)
		if (0 < format.precision && format.precision < (long)ft_strlen(fstr))
			fstr[format.precision] = '\0';
	return (fstr);
}
