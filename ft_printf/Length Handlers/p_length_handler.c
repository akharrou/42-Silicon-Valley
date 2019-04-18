/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_specifier_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:52:39 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/17 06:57:33 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_char	*p_specifier_handler(t_format format, va_list *args)
{
	return (ft_itoa_base((int)va_arg(*args, void *), HEX_BASE_LOWER, 7, '0'));
}
