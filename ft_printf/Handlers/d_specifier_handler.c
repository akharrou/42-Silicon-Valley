/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_specifier_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:52:33 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/17 00:34:20 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_char	*d_specifier_handler(t_format format, va_list *args)
{
	if (format.length == H)
	{
		return ((t_char *)ft_itoa((signed short int)va_arg(*args, int)));
	}
	if (format.length == HH)
	{
		return ((t_char *)ft_itoa((signed char)va_arg(*args, int)));
	}
	if (format.length == L)
	{
		return ((t_char *)ft_itoa((signed long int)va_arg(*args, long)));
	}
	if (format.length == LL)
		return (
			(t_char *)ft_itoa((signed long long int)va_arg(*args, long long))
		);
	else
	{
		return ((t_char *)ft_itoa((signed int)va_arg(*args, int)));
	}
}
