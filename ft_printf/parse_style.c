/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_style.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 15:47:32 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/21 10:36:12 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         parse_style -- parse the 'style' field in the formatted string
**
**    SYNOPSIS
**         #include <libft.h>
**
**         t_char **
**         parse_style(const char *format, t_int8 *i);
**
**    PARAMETERS
**
**         const char *format      Formatted string.
**
**         t_int8 *i               Current index in the formatted
**                                 string.
**
**    DESCRIPTION
**         Parses for the 'style' field in the formatted string.
**
**         We first check for an opening bracket. If there is one,
**         we will then look for its matching (closing) bracket.
**         If it is found we will parse out all the styles specified
**         in between the two brackets, storing them in a 2D array.
**         Finally the 2D array will be returned.
**
**    RETURN VALUES
**         If styles we're specified, then a 2D array containing them
**         will be returned; otherwise NULL is returned.
*/

#include "ft_printf.h"

t_char	**parse_style(const char *format, t_int8 *i)
{
	t_char		**styles;
	t_char		*closing_bracket;

	styles = NULL;
	if (format[*i] == '{')
	{
		closing_bracket = ft_strchr(format, '}');
		if (closing_bracket)
		{
			format = ft_strndup(
						format + (*i) + 1,
						closing_bracket - (format + (*i) - 1)
					);
			styles = ft_strsplit(format, ' ');
		}
		(*i) += ft_strlen(format) + 2;
		free((void *)format);
	}
	return (styles);
}
