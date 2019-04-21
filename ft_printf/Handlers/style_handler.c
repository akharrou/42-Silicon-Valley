/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   style_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:56:25 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/21 00:07:23 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
**    DESCRIPTION
**         Dispatch table associating every style to its ANSI code.
**
**         Note:
**
**            - light colors are preceded with an 'l'.
**            - background colors are preceded with an 'bg'.
**
**       - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
**
**         How to specify a style in the format string ?
**
**               After the regular specifier format
**               append to it, between two curly brackets
**               '{}', all the styles that you want to apply
**               to the output, by name, seperated by spaces.
**
**               Valid names of styles are only those found
**               in the styles dispatch table below in the
**               'style' field of each (t_style) element.
**
**         Examples:
**
**             "%s{red bgwhite underlined}"
**
**             "%r{inversed bold}"
**
**             "%i{lblue bglgreen}"
**
**         Under the hood, ANSI code is prepended and appended
**         to the formatted string; it kinda looks like this:
**
**              \033[<code1>;<code2>; ... <codeN>m
**
*/

t_style styles_table[] =
{
	{    "default",     "0"       },
	\
	{    "underlined",  "4"       },
	{    "bold",        "1"       },
	{    "italic",      "3"       },
	{    "inverted",    "7"       },
	{    "dim",         "2"       },
	{    "hidden",      "8"       },
	\
	\
	{    "black",       "30",     },
	{    "white",       "97",     },
	\
	{    "gray",        "90",     },
	{    "red",         "31",     },
	{    "green",       "32",     },
	{    "yellow",      "33",     },
	{    "blue",        "34",     },
	{    "magenta",     "35",     },
	{    "cyan",        "36",     },
	\
	{    "lgray",       "37",     },
	{    "lred",        "91",     },
	{    "lgreen",      "92",     },
	{    "lyellow",     "93",     },
	{    "lblue",       "94",     },
	{    "lmagenta",    "95",     },
	{    "lcyan",       "96"      },
	\
	\
	{    "bgblack",     "40",     },
	{    "bgwhite",     "107",    },
	\
	{    "bggray",      "100",    },
	{    "bgred",       "41",     },
	{    "bggreen",     "42",     },
	{    "bgyellow",    "43",     },
	{    "bgblue",      "44",     },
	{    "bgmagenta",   "45",     },
	{    "bgcyan",      "46",     },
	\
	{    "bglgray",     "47",     },
	{    "bglred",      "101",    },
	{    "bglgreen",    "102",    },
	{    "bglyellow",   "103",    },
	{    "bglblue",     "104",    },
	{    "bglmagenta",  "105",    },
	{    "bglcyan",     "106"     },
	\
	{    NULL,          NULL      }
};

/*
**    NAME
**         style_handler -- formatted style conversion
**
**    SYNOPSIS
**         #include <libft.h>
**
**         t_char	*
**         style_handler(t_format format);
**
**    PARAMETERS
**
**         t_format format         Structure containing the variable
**                                 and information about how it must
**                                 be formatted.
**
**    DESCRIPTION
**         Handles the '%o' specifier like the libc 'printf()' function.
**
**         Note: the only flags and fields that apply to this specifier
**         are the following:
**
**             Flags: '-', '+', ' ', '0', '#'
**             Width: defined or '*'
**             Precision: defined or '*'
**             Length: 'hh', 'h', 'l', 'll'
**
**
**    RETURN VALUES
**         If successful, returns a formatted string that follows the
**         specified format; otherwise exits with a -1 on error.
*/

t_char	*style_handler(t_format format, t_char *string)
{
	t_int16	i;
	t_int16	j;
	t_char	*style_str;

	if (format.style != NULL)
	{
		style_str = ft_strdup("\033[");
		i = -1;
		while (format.style[++i])
		{
			j = -1;
			while (styles_table[++j].style)
				if (ft_strcmp(format.style[i], styles_table[j].style) == 0)
				{
						style_str = ft_strappend(
							style_str, styles_table[j].ansi_code, 1, 0);
					if (format.style[i + 1] != NULL)
						style_str = ft_strappend(style_str, ";", 1, 0);
				}
		}
		free(format.style);
		style_str = ft_strappend(style_str, "m", 1, 0);
		string = ft_strprepend(string, style_str, 1, 1);
		string = ft_strappend(string, "\033[0m", 1, 0);
	}
	return (string);
}
