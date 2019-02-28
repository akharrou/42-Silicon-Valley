/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbyte_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 19:59:37 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/27 16:44:35 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../libft.h"

void	ft_putbyte_fd(int c, int fd)
{
	if (!ISPRINT(c))
	{
		write(fd, "\\", 1);
		if (c <= '\xf')
			write(fd, "0", 1);
		ft_putnbr_base_fd((unsigned char)c, "0123456789abcdef", fd);
	}
	else
		write(fd, &c, 1);
}
