/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 04:44:27 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/15 04:50:10 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_params_count(const char *str)
{
	t_uint32 i;
	t_uint32 param_count;

	param_count = 0;
	if (str)
	{
		i = -1;
		while (str[++i])
			if (str[i] == '%' && i != 0 && str[i - 1] != '%')
				++param_count;
	}
	return (param_count);
}
