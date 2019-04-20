/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_style.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 15:47:32 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/20 15:49:35 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         parse_style -- parse the 'style' field in the formatted string
**
**    SYNOPSIS
**         #include <libft.h>
**
**         t_char **
**         parse_style(const char *format, t_int8 *i);
**
**    PARAMETERS
**
**         const char *format      Formatted string.
**
**         t_int8 *i               Current index in the formatted
**                                 string.
**
**    DESCRIPTION
**         Parses for the 'specifier' field in the formatted string.
**
**         We check if the character we are on is part of the (handled)
**         specifiers. If the specifier is indeed part of them, then it
**         is returned (as an 8 bit integer); otherwise NONE (-1) is
**         returned.
**
**         The index 'i' is incremented accordingly.
**
**    RETURN VALUES
**         Returns the obtained specifier (as an 8 bit integer) or NONE (-1,
**         macro defined in ft_printf.h) to indicate that no valid specifier
**         was specified.
*/

#include "ft_printf.h"

t_char	**parse_style(const char *format, t_int8 *i)
{
	(void)format;
	(void)i;
	return (NULL);
}
