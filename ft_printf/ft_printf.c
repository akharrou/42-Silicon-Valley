/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 23:17:26 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/21 11:47:07 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         ft_printf -- formatted output conversion
**
**    SYNOPSIS
**         #include <libft.h>
**
**         int
**         ft_printf(const char *format, ...);
**
**    PARAMETERS
**
**         const char *format        C string that contains the text to be
**                                   written to stdout.
**
**                                   It can optionally contain embedded
**                                   format specifiers that are replaced by
**                                   the values specified in subsequent
**                                   additional arguments and formatted as
**                                   requested.
**
**         ...                       (Additional arguments)
**
**    DESCRIPTION
**         Reproduction of the libc printf() function.
**
**         Writes the C string pointed by format to the standard output
**         (stdout). If format includes format specifiers (subsequences
**         beginning with %), the additional arguments following format
**         are formatted and inserted in the resulting string replacing
**         their respective specifiers.
**
**
**         A format specifier follows this prototype:
**
**             %[flags][width][.precision][length]specifier
**
**
**         The following is a list of managed specifers, flags, lengths,
**         widths, etc:
**
**         Specifers:
**
**              %c   --   Character
**
**              %s   --   String of characters
**
**              %r   --   String of printable & unprintable characters
**
**              %p   --   Pointer address
**
**              %d   --   Signed decimal integer
**
**              %i   --   Signed decimal integer
**
**              %f   --   Decimal floating point (lowercase)
**
**              %o   --   Unsigned octal
**
**              %u   --   Unsigned decimal integer
**
**              %x   --   Unsigned hexadecimal integer
**
**              %X   --   Unsigned hexadecimal integer (uppercase)
**
**              %b   --   Unsigned binary integer
**
**
**   	   Note: a '%' followed by another '%' character will write a single
**         '%' to the stream.
**
**
**         Flags:
**
**              -       --   Left justify the string.
**
**              +       --   Prepend w/ '+' or '-'.
**
**              #       --   Used with o, x or X specifiers the value is
**                           preceeded with 0, 0x or 0X respectively for
**                           values different than zero.
**
**                           Used with (a, A, e, E,) f, (F, g or G) it forces
**                           the written output to contain a decimal point
**                           even if no more digits follow. By default, if
**                           no digits follow, no decimal point is written.
**
**              0       --   Left-pads the number with zeroes '0' instead of
**                           spaces when padding is specified.
**
**              space   --   If no sign is going to be written, a blank space
**                           is inserted before the value.
**
**
**         Width:
**
**              *       --   Variable number of characters to be printed.
**
**              number  --   Minimum number of characters to be printed.
**                           If the value to be printed is shorter than
**                           this number, the result is padded with blank
**                           spaces. The value is not truncated even if
**                           the result is larger.
**
**
**         Precision:
**
**              *        --   Variable number length for the padding.
**
**              .number  --   For integer specifiers (d, i, o, u, x, X):
**                            precision specifies the minimum number of
**                            digits to be written. If the value to be
**                            written is shorter than this number, the
**                            result is padded with leading zeros. The
**                            value is not truncated even if the result
**                            is longer. A precision of 0 means that no
**                            character is written for the value 0.
**
**                            For a, A, e, E, f and F specifiers: this
**                            is the number of digits to be printed after
**                            the decimal point (by default, this is 6).
**
**                            For g and G specifiers: This is the maximum
**                            number of significant digits to be printed.
**
**                            For s: this is the maximum number of characters
**                            to be printed. By default all characters are
**                            printed until the ending null character is
**                            encountered.
**
**                            If the period is specified without an explicit
**                            value for precision, 0 is assumed.
**
**
**         Lengths:
**
**                                           specifiers
**            | — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — 
**            | length  |      d i      |        u o x X         |      f e    |
**            | — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — 
**            | (none)  | int           | unsigned int           | double      |
**            | hh      | signed char   | unsigned char          |             |
**            | h       | short int     | unsigned short int     |             |
**            | l       | long int      | unsigned long int      |             |
**            | ll      | long long int | unsigned long long int |             |
**            | L       |               |                        | long double |
**            | — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — 
**
**            | — — — — — — — — - - - - - - - - - - -
**            | length  |   c    |     s    |   p   |
**            | — — — — — — — - - - - - - - - - - - -
**            | (none)  | int    | char*    | void* |
**            | hh      |        |          |       |
**            | h       |        |          |       |
**            | l       |        |          |       |
**            | ll      |        |          |       |
**            | L       |        |          |       |
**            | — — — — — — — — — — — — — — — — — - -
**
**
**    RETURN VALUES
**         If successful, the total number of characters written is returned.
*/

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		args;
	t_char		*fstr;
	t_int32		tt_bytes_written;

	tt_bytes_written = 0;
	if (format != NULL)
	{
		va_start(args, format);
		while (*format != '\0')
		{
			if (*format == '%')
			{
				fstr = format_converter(&format, &args);
				if (!fstr)
					exit(-1);
				tt_bytes_written += write(STDOUT, fstr, ft_strlen(fstr));
				free(fstr);
			}
			else
				tt_bytes_written += write(STDOUT, format++, 1);
		}
		va_end(args);
	}
	return (tt_bytes_written);
}

/*
**    NAME
**         ft_fprintf -- formatted output conversion
**
**    SYNOPSIS
**         #include <libft.h>
**
**         int
**         ft_fprintf(int filedes, const char *format, ...);
**
**    PARAMETERS
**
**         int filedes               File descriptor to which the formatted
**                                   string will be written.
**
**         const char *format        C string that contains the text to be
**                                   written to stdout.
**
**                                   It can optionally contain embedded
**                                   format specifiers that are replaced by
**                                   the values specified in subsequent
**                                   additional arguments and formatted as
**                                   requested.
**
**         ...                       (Additional arguments)
**
**    DESCRIPTION
**         Reproduction of the libc fprintf() function.
**
**    RETURN VALUES
**         The total number of characters written is returned.
*/

int		ft_fprintf(int filedes, const char *format, ...)
{
	va_list		args;
	t_char		*fstr;
	t_int32		tt_bytes_written;

	if (!format)
		return (0);
	tt_bytes_written = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			fstr = format_converter(&format, &args);
			tt_bytes_written += write(
				filedes, fstr, ft_strlen(fstr));
			free(fstr);
		}
		else
			tt_bytes_written += write(filedes, format++, 1);
	}
	va_end(args);
	return ((int)tt_bytes_written);
}

/*
**    NAME
**         ft_sprintf -- formatted output conversion
**
**    SYNOPSIS
**         #include <libft.h>
**
**         int
**         ft_sprintf(char *str, const char *format, ...);
**
**    PARAMETERS
**
**         char *str                 String in which to store the complete
**                                   formatted string.
**
**         const char *format        C string that contains the text to be
**                                   written to stdout.
**
**                                   It can optionally contain embedded
**                                   format specifiers that are replaced by
**                                   the values specified in subsequent
**                                   additional arguments and formatted as
**                                   requested.
**
**         ...                       (Additional arguments)
**
**    DESCRIPTION
**         Reproduction of the libc sprintf() function.
**
**    RETURN VALUES
**         The total number of characters stored is returned.
*/

int		ft_sprintf(char *str, const char *format, ...)
{
	va_list		args;
	t_char		*fstr;
	t_char		*tmp;

	(str) = NULL;
	if (!format)
		return (-1);
	fstr = ft_strdup("");
	if (!fstr)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (fstr)
			tmp = fstr;
		fstr = (*format == '%') ?
			ft_strjoin(fstr, format_converter(&format, &args)) :
			ft_strjoin(fstr, &(*format++));
		free(tmp);
		if (!fstr)
			return (-1);
	}
	va_end(args);
	(str) = (char *)fstr;
	return ((int)ft_strlen(fstr));
}
