/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:29:48 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/18 23:23:33 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "ft_printf.h"

/*
**    DESCRIPTION
**         TODO.
*/

t_dispatch table[] =
{
	{  '%',  NULL,        },
	{  'c',  NULL,        },
	{  'd',  NULL,        },
	{  'i',  NULL,        },
	{  'f',  NULL,        },
	{  'o',  NULL,        },
	{  'u',  NULL,        },
	{  'x',  NULL,        },
	{  'X',  NULL,        },
	{  's',  &s_handler,  },
	{  'p',  NULL,        },
	{   0,   NULL,        }
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
**         If the 'length' field is not specified, then the
**         corresponding default size is assigned to the field.
**
**    RETURN VALUES
**         A (t_format) structure containing all the related
**         information about the parsed out format specifier.
*/

t_format		parse_format(const char *format, va_list *args)
{
	t_int8		i;
	t_format	info;

	i = 0;
	info = (t_format) {
		parse_flags(format, &i),
		parse_width(format, args, &i),
		parse_precison(format, args, &i),
		parse_length(format, &i),
		parse_specifier(format, &i),
		i,
		va_arg(*args, t_data)
	};
	return (info);
}

/*
**    NAME
**         formatted_string -- TODO
**
**    SYNOPSIS
**         #include <libft.h>
**
**         t_char *
**         formatted_string(const char **buf, va_list *args);
**
**    PARAMETERS
**
**         const char *format        A formatted string.
**
**    DESCRIPTION
**         TODO.
**
**    RETURN VALUES
**         TODO.
*/

t_char			*formatted_string(const char **format, va_list *args)
{
	t_int32		i;
	t_format	info;
	t_char		*fstr;

	fstr = NULL;
	info = parse_format((*format) + 1, args);
	if (info.specifier == NONE)
		fstr = ft_strndup(*format, info.format_length + 1);
	else
	{
		i = -1;
		while (table[++i].specifier)
			if (info.specifier == table[i].specifier)
			{
				fstr = table[i].handler(info);
				break;
			}
		if (!fstr)
			exit(-1);
	}
	(*format) += info.format_length + 1;
	return (fstr);
}
