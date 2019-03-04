/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 07:21:23 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/04 10:12:50 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/stdlib_42.h"

void	ft_memdel(void **ap)
{
	if (ap)
	{
		free(*ap);
		(*ap) = NULL;
	}
}
