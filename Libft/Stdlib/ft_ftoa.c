/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:20:16 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/17 19:46:45 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/stdlib_42.h"
#include "../Includes/string_42.h"

char	*ft_ftoa(double n, int precision)
{
	int


	ft_itoa(f, string, 10);
	ft_strcat(string, “.”);
	uint16_t i = (f – (int)f) * 100000;
	ft_itoa(i, string2, 10);
	ft_strcat(string, string2);
}

char	*ft_lftoa(long double n, int precision)
{
	short int i;

	ft_itoa_base(f, string, 10);
	ft_strcat(string, “.”);
	i = (f – (int)f) * precision;
	ft_itoa(i, string2, 10);
	strcat(string, string2);
}
