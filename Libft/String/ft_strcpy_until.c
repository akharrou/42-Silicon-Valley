/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_until.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 10:48:34 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/02 10:51:27 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strcpy_until(char *dest, const char *src, char *charset)
{
	int i;

	if (dest && src && charset)
	{
		i = 0;
		while (src[i] && !ft_ischarset(src[i], charset))
		{
			dest[i] = src[i];
			++i;
		}
		dest[i] = src[i];
		return (dest);
	}
	return (NULL);
}
