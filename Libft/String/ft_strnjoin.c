/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 07:25:17 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/16 14:12:56 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/string_42.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*new_str;
	int		len;

	if (s1 || s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		len = (n - 1 > len) ? len : n - 1;
		if (!(new_str = ft_strnew(len + 1)))
			return (NULL);
		return (ft_strcat(ft_strncat(new_str, s1, n), s2));
	}
	return (NULL);
}
