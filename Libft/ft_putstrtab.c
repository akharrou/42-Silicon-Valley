/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrtab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 10:28:29 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/21 10:29:20 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrtab(char **tab, char sep)
{
	if (tab)
		while (*tab)
		{
			ft_putstr(*tab);
			ft_putchar(sep);
			tab++;
		}
}
