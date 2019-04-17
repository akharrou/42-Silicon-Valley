/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 04:27:31 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/17 04:29:32 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/string_42.h"

size_t	ft_intlen_base(int n, unsigned int base)
{
	unsigned int	num;
	size_t			length;

	length = 1;
	num = n * -(n < 0);
	while (num >= base)
	{
		num /= base;
		++length;
	}
	return (length);
}
