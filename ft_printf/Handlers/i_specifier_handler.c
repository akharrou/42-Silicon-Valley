/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_specifier_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:52:31 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/17 01:33:01 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_char	*i_specifier_handler(t_format format, va_list *args)
{
	if (format.length == H)
	{
		return (ft_itoa((signed short int)va_arg(*args, int)));
	}
	if (format.length == HH)
	{
		return (ft_itoa((signed char)va_arg(*args, int)));
	}
	if (format.length == L)
	{
		return (ft_itoa((signed long int)va_arg(*args, long)));
	}
	if (format.length == LL)
	{
		return (ft_itoa((signed long long int)va_arg(*args, long long)));
	}
	else
	{
		return (ft_itoa((signed int)va_arg(*args, int)));
	}
}
