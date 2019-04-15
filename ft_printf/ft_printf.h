/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 01:21:59 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/15 08:17:03 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "Libft/Includes/libft.h"
#include <stdarg.h>

#define SPECIFERS "cspdifouxX"

typedef struct	s_dispatch
{
	char	specifier;
	void	(*ftptr)(const char *format, void *);
}				t_dispatch;

int				ft_printf(const char *format, ...);
size_t			handle_specifier(const char **format);

#endif
