/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 08:42:20 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/19 08:52:34 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_pow(int nb, int power)
{
	int				sign;
	long double		product;

	// if (power == 0)
	// 	return (1);
	// if (power == 1)
	// 	return (nb);
	sign = (nb < 0) ? -1 : 1;
	nb = (nb < 0) ? -nb : nb;
	product = nb;
	while (--power)
	{
		product *= nb;
		if (product > 2147483647)
			return (-1);
	}
	return (sign * product);
}
