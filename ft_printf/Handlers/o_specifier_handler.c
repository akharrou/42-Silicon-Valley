/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_specifier_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:55:58 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/17 00:06:39 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_char	*o_specifier_handler(t_format format, va_list *args)
{
	if (format.length == H)
		return (
			ft_itoa_base((unsigned short int)va_arg(*args, unsigned int),
			"01234567")
		);
	if (format.length == HH)
		return (
			ft_itoa_base((unsigned char)va_arg(*args, unsigned int),
			"01234567")
		);
	if (format.length == L)
		return (
			ft_itoa_base((unsigned long int)va_arg(*args, unsigned long),
			"01234567")
		);
	if (format.length == LL)
		return (
			ft_itoa_base((unsigned long long)va_arg(*args, unsigned long long),
			"01234567")
		);
	else
		return (
			ft_itoa_base((unsigned int)va_arg(*args, unsigned int),
			"01234567")
		);
}
