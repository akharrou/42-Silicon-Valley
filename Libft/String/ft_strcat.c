/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:02:19 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/20 17:03:02 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	if (s2)
	{
		i = ft_strlen(s1);
		j = 0;
		while (s2[j])
			s1[i++] = s2[j++];
		s1[i] = '\0';
	}
	return (s1);
}
