/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_length_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:52:28 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/17 18:11:23 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

#include <math.h>

t_char	*f_specifier_handler(t_format format, void *arg)
{
	if (format.length == LLL)
	{
		return ((t_char *)ft_lftoa(
			va_arg(*args, long double), format.precision));
	}
	return(f_flag_handler((t_char *)ft_ftoa(
		va_arg(*args, double), format.precision)));
}
