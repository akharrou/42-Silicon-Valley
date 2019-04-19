/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:52:40 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/17 01:31:12 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_char	*c_handler(t_format format)
{
	t_char	*str;

	(void) format;
	if (!(str = ft_strdup(" ")))
		exit(-1);
	str[0] = (t_char)va_arg(*args, int);
	return ((t_char *)str);
}
