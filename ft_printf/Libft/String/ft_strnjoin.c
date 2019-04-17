/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 07:25:17 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/16 13:42:57 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/string_42.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char *new_str;

	if (s1 || s2)
	{
		if (!(new_str = ft_strnew(ft_strlen(s1) + ft_strnlen(s2, n) + 1)))
			return (NULL);
		return (ft_strncat(ft_strcat(new_str, s1), s2, n));
	}
	return (NULL);
}
