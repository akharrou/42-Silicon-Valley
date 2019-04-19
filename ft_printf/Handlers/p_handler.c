/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:52:39 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/17 06:57:33 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_char	*p_handler(t_format format)
{
	t_char	*addr;

	addr = ft_utoa_base(
		(uintmax_t)format.data.ptr, HEX_BASE_LOWER, format.precision);
	addr = ft_strprepend(addr, "0x", 1, 0);
	if (!addr)
		exit (-1);
	return (addr);
}
