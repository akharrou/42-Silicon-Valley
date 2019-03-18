/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 08:14:04 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/12 11:15:39 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ctype_42.h"
#include "../Includes/macros.h"

int		ft_find_next_prime(int n)
{
	if (n % 2 == 0)
		n++;
	else
		n += 2;
	while (!ft_isprime(n))
		n += 2;
	return (n);
}
