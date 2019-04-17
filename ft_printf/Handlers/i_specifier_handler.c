/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_specifier_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:52:31 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/16 23:40:44 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_char	*i_specifier_handler(t_format format, va_list *args)
{
	if (format.length == H)
	{
		return (ft_itoa((short int)va_arg(*args, int)));
	}
	if (format.length == HH)
	{
		return (ft_itoa((signed char)va_arg(*args, int)));
	}
	if (format.length == L)
	{
		return (ft_itoa((long int)va_arg(*args, long)));
	}
	if (format.length == LL)
	{
		return (ft_itoa((long long int)va_arg(*args, long long)));
	}
	else
	{
		return (ft_itoa((int)va_arg(*args, int)));
	}
}
