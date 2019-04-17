/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlonglen_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 01:54:03 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/17 02:12:33 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/string_42.h"

size_t	ft_longlonglen_base(long long n, unsigned int base)
{
	unsigned long long	num;
	size_t				length;

	length = 1 + (n < 0);
	num = (n < 0) ? -n : n;
	while (num >= base)
	{
		num /= base;
		++length;
	}
	return (length);
}
