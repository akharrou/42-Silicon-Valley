/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:20:16 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/17 21:50:00 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/stdlib_42.h"
#include "../Includes/string_42.h"

char	*ft_ftoa(double n, int precision)
{
	char	*first_half;
	char	*second_half;
	short int i

	first_half = ft_lltoa_base((int)n, first_half, -1);
	ft_strjoin(first_half, ".");
	uint16_t i = (n – ((int)n)) * (precision == -1) ? 6 : precision;
	second_half = ft_itoa_base(n, first_half, -1);
	ft_strcat(first_half, second_half);
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
