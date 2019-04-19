/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:51:50 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/17 00:20:27 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_char	*s_handler(t_format format)
{
	t_char	*fstr;

	fstr = ft_strdup((t_char *)format.data.str);
	if (format.precision != NONE)
		if (0 < format.precision && format.precision < (long)ft_strlen(fstr))
			fstr[format.precision] = '\0';
	format.width = format.width - ft_strlen(fstr);
	if (format.width > 0)
	{
		if ((format.flags & MINUS) == 1)
			fstr = ft_strappend(fstr, ft_padding(format.width, ' '), 1, 1);
		else
			fstr = ft_strprepend(fstr, ft_padding(format.width, ' '), 1, 1);
	}
	return (fstr);
}
