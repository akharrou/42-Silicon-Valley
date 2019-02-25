/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrtab_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 10:34:28 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/21 10:42:33 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrtab_fd(char **tab, char sep, int fd)
{
	if (tab)
		while (*tab)
		{
			ft_putstr_fd(*tab, fd);
			ft_putchar_fd(sep, fd);
			tab++;
		}
}
