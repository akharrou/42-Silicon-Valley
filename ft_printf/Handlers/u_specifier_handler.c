/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_specifier_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:56:15 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/16 23:58:15 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_char	*u_specifier_handler(t_format format, va_list *args)
{
	if (format.length == H)
	{
		return (ft_itoa((unsigned short int)va_arg(*args, unsigned int)));
	}
	if (format.length == HH)
	{
		return (ft_itoa((unsigned char)va_arg(*args, unsigned int)));
	}
	if (format.length == L)
	{
		return (ft_itoa((unsigned long int)va_arg(*args, unsigned long)));
	}
	if (format.length == LL)
		return (
			ft_itoa((unsigned long long int)va_arg(*args, unsigned long long))
		);
	else
	{
		return (ft_itoa((unsigned int)va_arg(*args, unsigned int)));
	}
}
