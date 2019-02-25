/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbytes_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 19:59:31 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/21 20:02:23 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putbytes_fd(char *str, int fd)
{
	while (*str)
	{
		if (!ISPRINT(*str))
		{
			write(fd, "\\", 1);
			if (*str <= '\xf')
				write(fd, "0", 1);
			ft_putnbr_base_fd(*str++, "0123456789abcdef", fd);
		}
		else
			write(fd, str++, 1);
	}
}
