/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:29:45 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/16 03:09:33 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**    NAME
**         parse_flags -- parses the 'flags' field in the formatted string
**
**    SYNOPSIS
**         #include <libft.h>
**
**         t_uint8
**         parse_flags(const char *format, t_uint32 *i);
**
**    PARAMETERS
**
**         const char *format      Formatted string.
**
**         t_uint32 *i             Current index in the formatted
**                                 string.
**
**    DESCRIPTION
**         Parses for the 'flags' field in the formatted string.
**
**         We iterate through the formatted string turning on bits in an
**         integer. Each bit in the integer is mapped to a certain flag,
**         the mapping is found in the 'e_flags' enum (defined in ft_printf.h).
**
**         At the end we end up with a mask that corresponds to the activated
**         flags.
**
**    RETURN VALUES
**         Returns a mask representing the specified flags.
*/

t_int8	parse_flags(const char *format, t_uint32 *i)
{
	t_uint8		flags;

	flags = 0;
	while (ft_ischarset(format[*i], FLAGS))
	{
		if (format[*i] == '+')
			flags |= PLUS;
		else if (format[*i] == '-')
			flags |= MINUS;
		else if (format[*i] == ' ')
			flags |= SPACE;
		else if (format[*i] == '#')
			flags |= HASH;
		else if (format[*i] == '0')
			flags |= ZERO;
		++(*i);
	}
	return (flags);
}

/*
**    NAME
**         parse_width -- parse the 'width' field in the formatted string
**
**    SYNOPSIS
**         #include <libft.h>
**
**         t_uint8
**         parse_width(const char *format, t_uint32 *i);
**
**    PARAMETERS
**
**         const char *format      Formatted string.
**
**         t_uint32 *i             Current index in the formatted
**                                 string.
**
**    DESCRIPTION
**         Parses for the 'width' field in the formatted string.
**
**         Starting from the first character after the flags field in
**         the formatted string, we parse out digits until the first
**         non-digit character (using ft_atoi).
**
**         If 'width' is greater than 0, we increment the index by the
**         length (in characters) of the obtained integer.
**
**    RETURN VALUES
**         Returns an unsigned 8 bit integer representing the width
**         specified.
*/

t_int8	parse_width(const char *format, t_uint32 *i)
{
	t_uint8		width;

	width = ft_atoi(format + (*i));
	if (width)
		(*i) += ft_intlen(width);
	return (width);
}

/*
**    NAME
**         parse_precison -- parse the 'precision' field of the formatted
**                           string
**
**    SYNOPSIS
**         #include <libft.h>
**
**         t_uint8
**         parse_precison(const char *format, t_uint32 *i);
**
**    PARAMETERS
**
**         const char *format      Formatted string.
**
**         t_uint32 *i             Current index in the formatted
**                                 string.
**
**    DESCRIPTION
**         Parses for the 'precision' field in the formatted string.
**
**         First we check if a '.' dot is specified, if so then,
**         parsing ensues; else the default precision is assumed.
**
**         If a '.' was present, we first skip all '0's if any,
**         then we parse out digits until the first non-digit
**         character (using ft_atoi).
**
**         If 'precision' is greater than 0, we increment the index
**         by the length (in characters) of the obtained integer.
**
**         If no 'precision' is specified, the index stays the same
**         and NONE (-1) is returned.
**
**    RETURN VALUES
**         Returns an unsigned 8 bit integer representing the precision
**         specified or NONE (-1, macro defined in ft_printf.h) to
**         indicate that no precision was specified.
*/

t_int8	parse_precison(const char *format, t_uint32 *i)
{
	t_uint8		precision;

	if (format[*i] == '.')
	{
		++(*i);
		while (format[*i] == '0')
			++(*i);
		precision = ft_atoi(format + (*i));
		if (precision)
			(*i) += ft_intlen(precision);
		return (precision);
	}
	return (NONE);
}

/*
**    NAME
**         parse_length -- parse the 'length' field in the formatted string
**
**    SYNOPSIS
**         #include <libft.h>
**
**         t_uint8
**         parse_length(const char *format, t_uint32 *i);
**
**    PARAMETERS
**
**         const char *format      Formatted string.
**
**         t_uint32 *i             Current index in the formatted
**                                 string.
**
**    DESCRIPTION
**         Parses for the 'length' field in the formatted string.
**
**         We check for an exact match of 'h', 'l', 'L', 'hh', or
**         'll' with a series of if/else if statements.
**
**         The index 'i' is incremented accordingly.
**
**         If no 'length' is specified, the index stays the same
**         and NONE (-1) is returned.
**
**    RETURN VALUES
**         Returns an unsigned 8 bit integer representing the specified
**         length or NONE (-1, macro defined in ft_printf.h) to indicate
**         that the defaults should be use.
*/

t_int8	parse_length(const char *format, t_uint32 *i)
{
	(*i) +=1;
	if (format[(*i) - 1] == 'h'  && format[*i] != 'h')
		return (H);
	else if (format[(*i) - 1] == 'l'  && format[*i] != 'l')
		return (L);
	else if (format[*i] == 'L')
		return (LLL);
	else if (format[(*i) - 1] == 'h' && format[*i] == 'h')
	{
		(*i) += 1;
		return (HH);
	}
	else if (format[(*i) - 1] == 'l' && format[*i] == 'l')
	{
		(*i) += 1;
		return (LL);
	}
	else
	{
		(*i) -= 1;
		return (NONE);
	}
}

/*
**    NAME
**         parse_specifier -- parse the 'specifier' field of the formatted
**                            string
**
**    SYNOPSIS
**         #include <libft.h>
**
**         t_uint8
**         parse_specifier(const char *format, t_uint32 *i);
**
**    PARAMETERS
**
**         const char *format      Formatted string.
**
**         t_uint32 *i             Current index in the formatted
**                                 string.
**
**    DESCRIPTION
**         Parses for the 'specifier' field in the formatted string.
**
**         We check if the character we are on is part of the (handled)
**         specifiers. If the specifier is valid, it is returned (as an
**         8 bit integer); otherwise NONE (-1) is returned.
**
**         The index 'i' is incremented accordingly.
**
**    RETURN VALUES
**         Returns the obtained specifier (as an 8 bit integer) or NONE (-1,
**         macro defined in ft_printf.h) to indicate that no valid specifier
**         was specified.
*/

t_int8	parse_specifier(const char *format, t_uint32 *i)
{
	return (
		(ft_ischarset(format[*i], SPECIFIERS) ? format[*i++] : NONE)
	);
}
