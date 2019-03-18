/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 07:25:36 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/04 13:17:20 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ctype_42.h"
#include "../Includes/string_42.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	end;

	if (s)
	{
		while (*s && ISSPACE(*s))
			s++;
		end = ft_strlen(s);
		while (end > 0 && ISSPACE(s[end - 1]))
			--end;
		return (ft_strdup_range(s, 0, end));
	}
	return (NULL);
}
