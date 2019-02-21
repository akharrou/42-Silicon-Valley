/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 08:42:20 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/19 14:12:07 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double		ft_pow(int nb, int power)
{
	int				sign;
	long double		val;

	if (power == 0)
		return (1);
	sign = (nb < 0) ? -1 : 1;
	nb = (nb < 0) ? -nb : nb;
	val = nb;
	if (power < 0)
	{
		power = -power + 1;
		while (power--)
			val /= nb;
	}
	else
	{
		while (--power)
			val *= nb;
	}
	return (val * sign);
}
