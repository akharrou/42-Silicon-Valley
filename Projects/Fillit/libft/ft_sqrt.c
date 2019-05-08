/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 18:38:49 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/23 18:20:37 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_sqrt(double x)
{
	long double		res;
	long double		root;
	double			precision;

	if (x < 2)
		return ((x < 0) ? 0.0 : x);
	res = 0;
	root = 2;
	while ((res = root * root) <= x)
	{
		if (res == x)
			return (root);
		root++;
	}
	--root;
	precision = 0.000001;
	while ((res = root * root) <= x)
	{
		if (res == x)
			return (root);
		root += precision;
	}
	return (root - precision);
}
