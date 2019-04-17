/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_specifier_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:52:40 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/17 00:28:37 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_char	*c_specifier_handler(t_format format, va_list *args)
{
	t_char	*str;

	if (!(str = ft_strdup(" ")))
		exit(-1);
	str[0] = (t_char)va_arg(*args, int);
	return ((t_char *)str);
}
