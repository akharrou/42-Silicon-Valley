/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 07:25:36 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/20 20:37:37 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	end;

	if (s)
	{
		while (*s && ft_isspace(*s))
			s++;
		end = ft_strlen(s);
		while (end > 0 && ft_isspace(s[end - 1]))
			--end;
		return (ft_strdup_range(s, 0, end));
	}
	return (NULL);
}
