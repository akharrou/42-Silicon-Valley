/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 01:21:59 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/15 16:15:32 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "Libft/Includes/libft.h"
#include <stdarg.h>

#define SPECIFERS "cspdifouxX%"
#define FLAGS "-+#0 "

typedef struct	s_dispatch
{
	char		specifier;
	int			(*ftptr)(const char *format, void *);
}				t_dispatch;

typedef struct	s_format
{
	/* TODO */
}				t_format;

int				ft_printf(const char *format, ...);

t_bool		valid_format(const char *format);
t_format	parse_format(const char *format);
size_t		handle_format(t_format *info, va_list *args);

#endif
