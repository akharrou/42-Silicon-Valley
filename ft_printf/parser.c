/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:29:45 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/21 12:59:28 by akharrou         ###   ########.fr       */
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
**         t_int8
**         parse_flags(const char *format, t_int8 *i);
**
**    PARAMETERS
**
**         const char *format      Formatted string.
**
**         t_int8 *i               Current index in the formatted
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
*/s

t_int8			parse_flags(const char *format, t_int8 *i)
{
	t_int8		flags;

	flags = 0;
	while (format[*i])
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
		else
			break ;
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
**         t_int32
**         parse_width(const char *format, va_list *args, t_int8 *i);
**
**    PARAMETERS
**
**         const char *format      Formatted string.
**
**         va_list *args           Variable argument list.
**
**         t_int8 *i               Current index in the formatted
**                                 string.
**
**    DESCRIPTION
**         Parses for the 'width' field in the formatted string.
**
**         First we check if the '*' flag is present, in which case it
**         would indicate to us that this is a variable sized 'width'.
**         If the star is present, we extract a variable from the
**         va_list assigning it to the format's 'width' field.
**
**         Otherwise, starting from the first character after the flags
**         field in the formatted string, we parse out digits until the
**         first non-digit character (using ft_atoi).
**
**         If 'width' is greater than 0, we increment the index by the
**         length (in characters) of the obtained integer.
**
**    RETURN VALUES
**         Returns a signed 8 bit integer representing the width
**         specified.
*/

t_int32			parse_width(const char *format, va_list *args, t_int8 *i)
{
	t_int32		width;

	if (format[*i] == '*')
	{
		width = va_arg(*args, t_int32);
		++(*i);
	}
	else
	{
		width = ft_atoi(format + (*i));
		if (width)
			(*i) += ft_intlen(width);
	}
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
**         t_int32
**         parse_precison(const char *format, va_list *args, t_int8 *i);
**
**    PARAMETERS
**
**         const char *format      Formatted string.
**
**         va_list *args           Variable argument list.
**
**         t_int8 *i               Current index in the formatted
**                                 string.
**
**    DESCRIPTION
**         Parses for the 'precision' field in the formatted string.
**
**         First we check if a '.' dot is specified, if so then,
**         parsing ensues; otherwise NONE (i.e -1) is returned
**         specifying that no precision was specified.
**
**         If the '.' is present we then firstly check if the '*'
**         flag is present, in which case it would indicate to us
**         that this is a variable sized 'precision'. If the star
**         is present, we extract a variable from the va_list
**         assigning it to the format's 'precision' field.
**
**         Otherwise, we skip all '0's if any, then we parse out
**         digits until the first non-digit character (using ft_atoi).
**
**         If 'precision' is greater than 0, we increment the index
**         by the length (in characters) of the obtained integer.
**
**    RETURN VALUES
**         Returns a signed 8 bit integer representing the precision
**         specified or NONE (-1, macro defined in ft_printf.h) to
**         indicate that no precision was specified.
*/

t_int32			parse_precison(const char *format, va_list *args, t_int8 *i)
{
	t_int32		precision;

	if (format[*i] == '.')
	{
		++(*i);
		if (format[*i] == '*')
		{
			precision = va_arg(*args, t_int32);
			++(*i);
		}
		else
		{
			while (format[*i] == '0')
				++(*i);
			precision = ft_atoi(format + (*i));
			if (precision)
				(*i) += ft_intlen(precision);
		}
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
**         t_int8
**         parse_length(const char *format, t_int8 *i);
**
**    PARAMETERS
**
**         const char *format      Formatted string.
**
**         t_int8 *i               Current index in the formatted
**                                 string.
**
**    DESCRIPTION
**         Parses for the 'length' field in the formatted string.
**
**         We check for an exact match of 'h', 'l', 'L', 'hh', or
**         'll' with a series of if/else if statements.
**
**         (switch statements are not permitted with the school's
**         'norminette').
**
**         The index 'i' is incremented accordingly.
**
**         If no 'length' is specified, the index stays the same
**         and NONE (-1) is returned.
**
**    RETURN VALUES
**         Returns a signed 8 bit integer representing the specified
**         length or NONE (-1, macro defined in ft_printf.h) to indicate
**         that the defaults should be use.
*/

t_int8			parse_length(const char *format, t_int8 *i)
{
	(*i) += 2;
	if (format[(*i) - 2] == 'h' && format[(*i) - 1] == 'h')
		return (HH);
	else if (format[(*i) - 2] == 'l' && format[(*i) - 1] == 'l')
		return (LL);
	(*i) -= 1;
	if (format[(*i) - 1] == 'h')
		return (H);
	else if (format[(*i) - 1] == 'l')
		return (L);
	else if (format[(*i) - 1] == 'L')
		return (LLL);
	(*i) -= 1;
	return (NONE);
}

/*
**    NAME
**         parse_specifier -- parse the 'specifier' field in the formatted
**                            string
**
**    SYNOPSIS
**         #include <libft.h>
**
**         t_int8
**         parse_specifier(const char *format, t_int8 *i);
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

t_int8			parse_specifier(const char *format, t_int8 *i)
{
	if (ft_ischarset(format[*i], SPECIFIERS))
	{
		++(*i);
		return (format[(*i) - 1]);
	}
	return (NONE);
}
