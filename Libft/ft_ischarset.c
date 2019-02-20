/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischarset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:17:40 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/19 15:36:17 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_ischarset(int c, const char *seperators);
{
	while (*seperators)
	{
		if ((unsigned char)c == *seperators)
			return (1);
		seperators++;
	}
	return (0);
}
