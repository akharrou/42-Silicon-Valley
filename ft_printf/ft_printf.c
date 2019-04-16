/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 23:17:26 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/16 10:42:32 by akharrou         ###   ########.fr       */
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
**
**   	   Note: a '%' followed by another '%' character will write a single
**         '%' to the stream.
**
**
**         Flags:
**
**              -       --   Left justify
**
**              +       --   Prepend w/ '+' or '-'
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
**                           spaces when padding is specified
**
**              space   --   If no sign is going to be written, a blank space
**                           is inserted before the value.
**
**
**         Width:
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
**            | l       | wint_t | wchar_t* |       |
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
	t_int32		tt_bytes_written;

	if (!format)
		return (0);
	tt_bytes_written = 0;
	va_start(args, format);
	while (*format)
		tt_bytes_written += (*format == '%') ?
			write_argument(STDOUT, &format, &args) :
			write(STDOUT, format++, 1);
	va_end(args);
	return (tt_bytes_written);
}
