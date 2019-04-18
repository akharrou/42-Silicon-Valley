/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:20:16 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/18 13:15:04 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/stdlib_42.h"
#include "../Includes/macros.h"

char	*ft_ftoa(long double n, int width, int precision)
{
	return (ft_ftoa_base(n, DECIMAL_BASE, width, precision));
}
