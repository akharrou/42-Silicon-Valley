/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 08:30:24 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/21 18:54:55 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_intlen(long n)
{
	size_t i;

	i = 0;
	if (n <= 0)
		n = -n;
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}
