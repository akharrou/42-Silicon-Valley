/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbytes_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 19:59:31 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/01 10:45:43 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putbytes_fd(const char *byte_str, int fd)
{
	while (*byte_str)
	{
		if (!ISPRINT(*byte_str))
		{
			write(fd, "\\", 1);
			if (*byte_str <= '\xf')
				write(fd, "0", 1);
			ft_putnbr_base_fd(*byte_str++, "0123456789abcdef", fd);
		}
		else
			write(fd, byte_str++, 1);
	}
}
