/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischarset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:17:40 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/19 16:29:38 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_ischarset(int c, const char *charset)
{
	while (*charset)
	{
		if ((unsigned char)c == *charset)
			return (1);
		charset++;
	}
	return (0);
}
