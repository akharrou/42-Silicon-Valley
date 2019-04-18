/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:13:05 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/18 12:13:08 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long double		ft_round(long double n)
{
	long double tmp;

	n = (n < 0) ? -n : n;
	tmp = n / 10;
	tmp -= (unsigned long long)tmp;
	tmp = (tmp < 0) ? -tmp : tmp;
	if (tmp >= 0.5)
		return (n + 1);
	return (n);
}
