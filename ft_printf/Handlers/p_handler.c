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
	void	*addr;

	// addr = ft_utoa_base((int)format.data, HEX_BASE_LOWER, format.precision);
	// if (info.flags & MINUS)
	// 	addr = ft_strprepend()
	// return ();
}

/* HANDLING ORDER */

// 1 -  length_handler
// 2 -  precision_handler
// 3 -  flags_handler
// 4 -  width_handler
