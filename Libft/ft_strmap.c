/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 07:23:33 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/19 18:57:45 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*new_str;

	if (!(new_str = (char *)malloc(ft_strlen(s))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = (*f)(s[i]);
		i++;
	}
	return (new_str);
}
