/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:29:48 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/16 10:41:03 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "ft_printf.h"

// t_dispatch specifier_table[] =
// {
// 	{'c', &c_flag_handler},
// 	{'s', &s_flag_handler},
// 	{'p', &p_flag_handler},
// 	{'d', &d_flag_handler},
// 	{'i', &i_flag_handler},
// 	{'f', &f_flag_handler},
// 	{'o', &o_flag_handler},
// 	{'u', &u_flag_handler},
// 	{'x', &x_flag_handler},
// 	{'X', &X_flag_handler}
// };

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

t_format		parse_format(const char *format)
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

size_t		write_argument(int filedes, const char **buf, va_list *args)
{
	t_uint32 i;
	t_format info;

	info = parse_format(++(*buf));
	(*buf) += info.format_length;


	// if (!info.specifier)
	// 	return (write(filedes, (*buf)++, 1));
	// (*buf) += info.options;
	// i = ft_strlen(SPECIFIERS);
	// while (--i > -1)
	// 	if (info.specifier == specifier_table[i][0])
	// return (/* total bytes written */);

	(void)i;
	(void)filedes;
	(void)args;

	return (1);
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