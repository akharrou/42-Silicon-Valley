/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_cleaner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 19:34:44 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/05 19:46:36 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/string_42.h"
#include "../Includes/bigint.h"

void	bigint_cleaner(t_bigint *number)
{
	char	*decimal_pt;

	decimal_pt = ft_strchr((*number), '.');
	if (decimal_pt)
	{
		(*number) = ft_strrstrip((*number), "0");
		(*number) = ft_strnlstrip((*number), "0", decimal_pt - (*number) - 1);
	}
	else
		(*number) = ft_strnlstrip((*number), "0", ft_strlen(*number) - 1);
}
