/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbytes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 19:22:31 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/21 19:47:19 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putbytes(char *str)
{
	while (*str)
	{
		if (!ISPRINT(*str))
		{
			ft_putchar('\\');
			if (*str <= '\xf')
				ft_putchar('0');
			ft_putnbr_base(*str++, "0123456789abcdef");
		}
		else
			ft_putchar(*str++);
	}
}
