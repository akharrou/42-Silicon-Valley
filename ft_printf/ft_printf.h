/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 01:21:59 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/16 02:59:29 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "Libft/Includes/libft.h"
# include <stdarg.h>

# define SPECIFIERS  "cspdifouxX%"
# define FLAGS       "-+#0 "

# define NONE -1

enum e_flags
{
    MINUS = (1 << 0),
    PLUS  = (1 << 1),
    SPACE = (1 << 2),
    HASH  = (1 << 3),
    ZERO  = (1 << 4)
};

enum e_lengths
{
	H,
	HH,
	L,
	LL,
	LLL
};

typedef struct	s_dispatch
{
	char		specifier;
	int			(*ftptr)(const char *format, void *);
}				t_dispatch;

typedef struct	s_format_info
{
	t_int8		flags : 5;
	t_int8		width;
	t_int8		precision;
	t_int8		length;
	t_int8		specifier;
	t_uint32	format_length;
}				t_format;

int			ft_printf(const char *format, ...);

t_int8		parse_flags(const char *format, t_uint32 *i);
t_int8		parse_width(const char *format, t_uint32 *i);
t_int8		parse_precison(const char *format, t_uint32 *i);
t_int8		parse_length(const char *format, t_uint32 *i);
t_int8		parse_specifier(const char *format, t_uint32 *i);

t_format	parse_format(const char *format);

void		c_flag_handler();
void		s_flag_handler();
void		p_flag_handler();
void		d_flag_handler();
void		i_flag_handler();
void		f_flag_handler();
void		o_flag_handler();
void		u_flag_handler();
void		x_flag_handler();
void		X_flag_handler();

t_format	handle_format(const char *format);

size_t		write_argument(int filedes, const char **buf, va_list *args);

#endif
