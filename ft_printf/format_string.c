/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:29:48 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/19 11:51:18 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**    DESCRIPTION
**         Dispatch table associating every single format specifier to
**         its handler.
**
**         The idea is to make the hanlders sort of plugins to the 'printf()'
**         function as opposed to intertwined with it.
*/

t_dispatch table[] =
{
	{   '%',    &mod_handler,   },
	{   'c',    &c_handler,     },
	{   'i',    &i_handler,     },
	{   'd',    &d_handler,     },
	{   'f',    &f_handler,     },
	{   'o',    &o_handler,     },
	{   'u',    &u_handler,     },
	{   'x',    &x_handler,     },
	{   'X',    &x_handler,     },
	{   'b',    &b_handler,     },
	{   's',    &s_handler,     },
	{   'p',    &p_handler,     },
	{   '\0',   NULL,           }
};

/*
**    NAME
**         parse_format -- parse out format
**
**    SYNOPSIS
**         #include <libft.h>
**
**         t_format
**         parse_format(const char *format, va_list *args);
**
**    PARAMETERS
**
**         const char *format        A formatted string.
**
**         va_list *args             A variable argument list.
**
**    DESCRIPTION
**         Extracts variable from the variable argument list, parses
**         out a format and stores its information in a (t_format)
**         structure.
**
**    RETURN VALUES
**         The function returns a (t_format) structure containing
**         all the related information about the parsed out format
**         specifier.
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
		{(intmax_t)0},
		' ',
		i
	};
	if (info.specifier != 'f')
		info.data = va_arg(*args, t_data);
	else
		info.data.dble = va_arg(*args, double);
	if (info.precision == NONE && info.flags & ZERO)
		info.pad = '0';
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
		while (table[++i].specifier != '\0')
			if (info.specifier == table[i].specifier)
			{
				fstr = table[i].handler(info);
				info.width = info.width - ft_strlen(fstr);
				if (info.width > 0)
					fstr = (info.flags & MINUS) ?
					ft_strappend(fstr, ft_padding(info.width, info.pad), 1, 1) :
					ft_strprepend(fstr, ft_padding(info.width, info.pad), 1, 1);
				break;
			}
	}
	(*format) += info.format_length + 1;
	return (fstr);
}
