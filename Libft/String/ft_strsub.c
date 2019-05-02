/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 19:31:36 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/02 08:32:55 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/stdlib_42.h"
#include "../Includes/string_42.h"
#include "../Includes/macros_42.h"
#include "../Includes/math_42.h"

static void	normalize_integers(char **op_1, char **op_2)
{
	size_t	len_1;
	size_t	len_2;

	len_1 = ft_strlen(*op_1);
	len_2 = ft_strlen(*op_2);
	if (len_1 > len_2)
		(*op_2) = ft_strprepend(*op_2, ft_padding(len_1 - len_2, '0'), 1, 1);
	else if (len_1 < len_2)
		(*op_1) = ft_strprepend(*op_1, ft_padding(len_2 - len_1, '0'), 1, 1);
}

static void	normalize_decimals(char **op_1, char **op_2)
{
	char		*decpt_1;
	char		*decpt_2;
	intmax_t	decimals_1;
	intmax_t	decimals_2;

	decpt_1 = ft_strchr(*op_1, '.');
	decpt_2 = ft_strchr(*op_2, '.');
	decimals_1 = (decpt_1) ? ft_strlen(*op_1) - 1 - (decpt_1 - (*op_1)) : 0;
	decimals_2 = (decpt_2) ? ft_strlen(*op_2) - 1 - (decpt_2 - (*op_2)) : 0;
	if (decpt_1 && !decpt_2)
		(*op_2) = ft_strappend(
			*op_2, ft_strjoinfre(".", ft_padding(decimals_1, '0'), 0, 1), 1, 1);
	else if (!decpt_1 && decpt_2)
		(*op_1) = ft_strappend(
			*op_1, ft_strjoinfre(".", ft_padding(decimals_2, '0'), 0, 1), 1, 1);
	else if (decpt_1 && decpt_2)
	{
		if (decimals_1 > decimals_2)
			(*op_2) = ft_strappend(
				*op_2, ft_padding(decimals_1 - decimals_2, '0'), 1, 1);
		if (decimals_1 < decimals_2)
			(*op_1) = ft_strappend(
				*op_1, ft_padding(decimals_2 - decimals_1, '0'), 1, 1);
	}
}

char		*ft_strsub(char *operand_1, char *operand_2, char *base)
{
	/** TODO
	 * IMPLEMENT THE STRSUBTRACT FUNCTION
	*/
	return (NULL);
}
