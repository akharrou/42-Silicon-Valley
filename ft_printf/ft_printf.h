/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 01:21:59 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/19 11:45:52 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

# include "Libft/Includes/libft.h"
# include <stdarg.h>

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

# define SPECIFIERS "cspdifouxXb%"

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

typedef union			u_data
{
	char				chr;
	unsigned char		uchr;
	short				shrt;
	unsigned short		ushrt;
	int					intgr;
	unsigned			uintgr;
	char				*str;
	long				lng;
	unsigned long		ulng;
	long long			lnglng;
	unsigned long long	ulnglng;
	double				dble;
	long double			ldble;
	intmax_t			intmax_t;
	uintmax_t			uintmax_t;
	intptr_t			ptr;
}						t_data;

typedef struct	s_format_info
{
	t_int8		flags;
	t_int32		width;
	t_int32		precision;
	t_int8		length;
	t_int8		specifier;
	t_data		data;
	t_char		pad;
	t_int8		format_length;
}				t_format;

typedef struct	s_dispatch
{
	char		specifier;
	t_char		*(*handler)(t_format format);
}				t_dispatch;

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

# define NONE (-1)

enum	e_flags
{
	MINUS = (1 << 0),
	PLUS = (1 << 1),
	SPACE = (1 << 2),
	HASH = (1 << 3),
	ZERO = (1 << 4)
};

enum	e_lengths
{
	H = sizeof(int),
	HH = sizeof(char),
	L = sizeof(long int),
	LL = sizeof(long long int),
	LLL = sizeof(long double)
};

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

int				ft_printf(const char *format, ...);
int				ft_fprintf(int filedes, const char *format, ...);
int				ft_sprintf(char *str, const char *format, ...);

t_format		parse_format(const char *format, va_list *args);

t_int8			parse_flags(const char *format, t_int8 *i);
t_int32			parse_width(const char *format, va_list *args, t_int8 *i);
t_int32			parse_precison(const char *format, va_list *args, t_int8 *i);
t_int8			parse_length(const char *format, t_int8 *i);
t_int8			parse_specifier(const char *format, t_int8 *i);

t_char			*i_handler(t_format format);
t_char			*d_handler(t_format format);
t_char			*u_handler(t_format format);
t_char			*f_handler(t_format format);
t_char			*o_handler(t_format format);
t_char			*x_handler(t_format format);
t_char			*b_handler(t_format format);
t_char			*c_handler(t_format format);
t_char			*s_handler(t_format format);
t_char			*p_handler(t_format format);
t_char			*mod_handler(t_format format);

t_char			*formatted_string(const char **buf, va_list *args);

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

#endif
