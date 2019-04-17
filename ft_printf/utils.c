/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 04:44:27 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/16 22:16:30 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		*argument(t_format format, va_list *args)
{
	int var_int;
	long var_long;
	long long var_long_long;
	void	*var_ptr;

	if (format.length == H)
		var_int = va_arg(*args, int);
	if (format.length == H)
		var_long = va_arg(*args, long);
	if (format.length == H)
		var_long_long = va_arg(*args, long long);
	if (format.length == H)
		var_ptr = va_arg(*args, char *);
	if (format.length == H)
		var_ptr = va_arg(*args, void *);
	if (format.length == H)
		var_ptr = va_arg(*args, void *);
	if (format.length == H)
		var_long_long = va_arg(*args, long long);
	else if (format.length == H)
	{

	}
	else if (format.length ==  H)
	{

	}
	else if (format.length == L)
	{

	}
	else if (format.length ==  L)
	{

	}
	else if (format.length ==  LL)
	{

	}
	else
		exit (-1)


	if (ft_ischarset(format.specifier, "dic"))
	{

	}
	else if (ft_ischarset(format.specifier, "uoxX"))
	{

	}
	else if (ft_ischarset(format.specifier, "fFeEgGaA"))
	{

	}
	else if (format.specifier == 's')
	{

	}
	else if ((format.specifier == 's'))
	{

	}
	else
		exit(-1);
}
