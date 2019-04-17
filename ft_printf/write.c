/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:29:48 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/16 18:51:03 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "ft_printf.h"

int s_specifier_handler(t_format format, void *arg)
{
	return (0);
}

int c_specifier_handler(t_format format, void *arg)
{
	return (0);
}

int p_specifier_handler(t_format format, void *arg)
{
	return (0);
}

int d_specifier_handler(t_format format, void *arg)
{
	return (0);
}

int i_specifier_handler(t_format format, void *arg)
{
	return (0);
}

int f_specifier_handler(t_format format, void *arg)
{
	return (0);
}

int o_specifier_handler(t_format format, void *arg)
{
	return (0);
}

int u_specifier_handler(t_format format, void *arg)
{
	return (0);
}

int x_specifier_handler(t_format format, void *arg)
{
	return (0);
}

int X_specifier_handler(t_format format, void *arg)
{
	return (0);
}

t_dispatch table[] =
{
	{  's',  &s_specifier_handler,  sizeof(char *)        },
	{  'c',  &c_specifier_handler,  sizeof(int)           },
	{  'p',  &p_specifier_handler,  sizeof(void *)        },
	{  'd',  &d_specifier_handler,  sizeof(int)           },
	{  'i',  &i_specifier_handler,  sizeof(int)           },
	{  'f',  &f_specifier_handler,  sizeof(double)        },
	{  'o',  &o_specifier_handler,  sizeof(unsigned int)  },
	{  'u',  &u_specifier_handler,  sizeof(unsigned int)  },
	{  'x',  &x_specifier_handler,  sizeof(unsigned int)  },
	{  'X',  &X_specifier_handler,  sizeof(unsigned int)  }
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
	t_uint32	i;
	t_format	info;
	t_uint8		num_specifiers;

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
		i = 0;
		num_specifiers = ft_strlen(SPECIFIERS);
		while (num_specifiers > i)
			if (info.specifier == table[i].specifier)
			{
				info.length = table[i].default_size;
				break ;
			}
	}
	return (info);
}

t_char			*formatted_string(const char **buf, va_list *args)
{
	t_uint32	i;
	t_format	info;
	t_uint32	num_specifiers;
	t_char		*formatted_string;

	info = parse_format((*buf) + 1);
	if (!(formatted_string = ft_strdup("")))
		exit(-1);
	if (info.specifier == NONE)
		return (
			ft_strjoin(formatted_string,
				ft_strncpy((char *)*buf, *buf, info.format_length + 1)));
	i = 0;
	num_specifiers = ft_strlen(SPECIFIERS);
	while (num_specifiers > i)
		if (info.specifier == table[i].specifier)
			bytes_written = table[i].handler(info, va_arg(*args, info.length));
	(*buf) += info.format_length + 1;
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
