/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   style_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:56:25 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/20 21:55:28 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
**    DESCRIPTION
**         Dispatch table associating every style to it ANSI code.
**         A style specification follows this format:
**
**              \033[<code1>;<code2>; ... <codeN>m
**
**         Note: light colors are preceded with an 'l'.
**
*/

t_style styles[] =
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
	(void)string;
	(void)format;
	return (NULL);
}
