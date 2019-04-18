/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_specifier_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:52:31 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/17 07:13:21 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_char	*i_specifier_handler(t_format format, va_list *args)
{
	if (format.length == H)
		return ((t_char *)ft_uitoa_base(
			(signed short int)va_arg(*args, signed int), DECIMAL_BASE,
			0, 0));
	if (format.length == HH)
		return ((t_char *)ft_uitoa_base(
			(signed char)va_arg(*args, signed int), DECIMAL_BASE,
			0, 0));
	if (format.length == L)
		return ((t_char *)ft_ultoa_base(
			(signed long int)va_arg(*args, signed long), DECIMAL_BASE,
			0, 0));
	if (format.length == LL)
		return ((t_char *)ft_ulltoa_base(
			(signed long long)va_arg(*args, signed long long), DECIMAL_BASE,
			0, 0));
	else
		return ((t_char *)ft_uitoa_base(
			(signed int)va_arg(*args, signed int), DECIMAL_BASE,
			0, 0)
		);
}
