/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_specifier_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:55:58 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/17 01:31:58 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_char	*o_specifier_handler(t_format format, va_list *args)
{
	if (format.length == H)
		return ((t_char *)
			ft_itoa_base((unsigned short int)va_arg(*args, unsigned int),
			OCT_BASE)
		);
	if (format.length == HH)
		return ((t_char *)
			ft_itoa_base((unsigned char)va_arg(*args, unsigned int),
			OCT_BASE)
		);
	if (format.length == L)
		return ((t_char *)
			ft_itoa_base((unsigned long int)va_arg(*args, unsigned long),
			OCT_BASE)
		);
	if (format.length == LL)
		return ((t_char *)
			ft_itoa_base((unsigned long long)va_arg(*args, unsigned long long),
			OCT_BASE)
		);
	else
		return ((t_char *)
			ft_itoa_base((unsigned int)va_arg(*args, unsigned int),
			OCT_BASE)
		);
}
