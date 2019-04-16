/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:29:48 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/16 11:35:51 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "ft_printf.h"

t_dispatch table[] =
{
	{'c', &c_specifier_handler},
	{'s', &s_specifier_handler},
	{'p', &p_specifier_handler},
	{'d', &d_specifier_handler},
	{'i', &i_specifier_handler},
	{'f', &f_specifier_handler},
	{'o', &o_specifier_handler},
	{'u', &u_specifier_handler},
	{'x', &x_specifier_handler},
	{'X', &X_specifier_handler}
};

/*
**    NAME
**         parse_format -- parse out an entire format specifier
**
**    SYNOPSIS
**         #include <libft.h>
**
**         t_format
**         parse_format(const char *format);
**
**    PARAMETERS
**
**         const char *format        A formatted string.
**
**    DESCRIPTION
**         Parses out a format specifier and stores all related
**         information in a (t_format) structure that will be used
**         later on.
**
**    RETURN VALUES
**         A (t_format) structure containing all the related
**         information about the parsed out format specifier.
*/

t_format	parse_format(const char *format)
{
	t_uint32 i;
	t_format info;

	i = 0;
	info = (t_format) {
		parse_flags(format, &i),
		parse_width(format, &i),
		parse_precison(format, &i),
		parse_length(format, &i),
		parse_specifier(format, &i),
		i
	};
	return (info);
}

t_char		*get_formatted_string(const char **buf, va_list *args)
{
	t_uint32 i;
	t_format info;
	t_uint32 bytes_written;
	t_uint32 num_specifiers;

	info = parse_format(++(*buf));
	if (!info.specifier)
		bytes_written = write(filedes, (*buf), info.format_length);

	i = 0;
	num_specifiers = ft_strlen(SPECIFIERS);
	while (num_specifiers > i)
		if (info.specifier == table[i].specifier)
			bytes_written = table[i].flag_handler(info, args);
	return (bytes_written);

	(void)i;
	(void)filedes;
	(void)args;

	(*buf) += info.format_length;
	return (bytes_written);
}

/* HANDLER FUNCTION */
	/* GET ARG HERE */
	/* GET LENGTH OF ARG HERE */
	/* DO MODIFIER STUFF HERE */
	/* DO HANDLER STUFF HERE*/
	/* DO MODIFIER STUFF HERE */


/**
 * HANDLERS:
 * do actions corresponding to options
 * print variable
 * return tt_bytes_written
 */
