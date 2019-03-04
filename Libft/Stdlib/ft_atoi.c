/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:53:15 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/04 13:17:20 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/macros.h"

int		ft_atoi(const char *str)
{
	int	i;
	int	val;
	int	sign;

	i = 0;
	while ((str[i] >= '\a' && str[i] <= '\r') || str[i] == ' ')
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	val = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (val > INT_MAX || val < INT_MIN)
			return (0);
		val = (val * 10) + (str[i++] - '0');
	}
	return (val * sign);
}
