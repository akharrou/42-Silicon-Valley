/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:29:48 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/17 00:00:23 by akharrou         ###   ########.fr       */
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
	{  '%',  &mod_specifier_handler,  sizeof(int)           },
	{  'c',  &s_specifier_handler,    sizeof(int)           },
	{  'd',  &d_specifier_handler,    sizeof(int)           },
	{  'i',  &i_specifier_handler,    sizeof(int)           },
	{  'f',  &f_specifier_handler,    sizeof(double)        },
	{  'o',  &o_specifier_handler,    sizeof(unsigned int)  },
	{  'u',  &u_specifier_handler,    sizeof(unsigned int)  },
	{  'x',  &x_specifier_handler,    sizeof(unsigned int)  },
	{  'X',  &x_specifier_handler,    sizeof(unsigned int)  },
	{  's',  &c_specifier_handler,    sizeof(char *)        },
	{  'p',  &p_specifier_handler,    sizeof(void *)        }
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

t_format		parse_format(const char *format)
{
	t_int8		i;
	t_int8		num_specifiers;
	t_format	info;

	i = 0;
	info = (t_format) {
		parse_flags(format, &i),
		parse_width(format, &i),
		parse_precison(format, &i),
		parse_length(format, &i),
		parse_specifier(format, &i),
		i
	};
	if (info.length == NONE && info.specifier != NONE)
	{
		i = -1;
		while (N_SPECIFIERS > ++i)
			if (info.specifier == table[i].specifier)
			{
				info.length = table[i].default_size;
				break ;
			}
	}
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

t_char			*formatted_string(const char **buf, va_list *args)
{
	t_int32		i;
	t_format	info;
	t_char		*fstr;
	t_int32		num_specifiers;

	info = parse_format((*buf) + 1);
	if (info.specifier == NONE)
		fstr = ft_strndup(*buf, info.format_length + 1);
	else
	{
		i = -1;
		while (N_SPECIFIERS > ++i)
			if (info.specifier == table[i].specifier)
				fstr = table[i].handler(info, args);
		// handle_width();
	}
	(*buf) += info.format_length + 1;
	return (fstr);
}
