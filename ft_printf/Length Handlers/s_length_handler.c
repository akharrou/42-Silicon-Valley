/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_specifier_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:51:50 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/17 00:20:27 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_char	*s_specifier_handler(t_format format, va_list *args)
{
	return ((t_char *)va_arg(*args, char *));
}
