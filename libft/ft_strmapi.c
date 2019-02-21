/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 07:23:46 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/20 17:24:47 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_str;

	if (!(new_str = (char *)malloc(ft_strlen(s) + 1)))
		return (NULL);
	i = -1;
	while (s[++i])
		new_str[i] = (*f)(i, s[i]);
	new_str[i] = '\0';
	return (new_str);
}
