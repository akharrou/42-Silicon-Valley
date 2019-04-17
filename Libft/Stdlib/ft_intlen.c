/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 08:30:24 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/17 02:12:54 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/string_42.h"

size_t	ft_intlen_base(int n, unsigned int base)
{
	unsigned int	num;
	size_t			length;

	length = 1;
	num = (n < 0) ? -n : n;
	while (num >= base)
	{
		num /= base;
		++length;
	}
	return (length);
}
