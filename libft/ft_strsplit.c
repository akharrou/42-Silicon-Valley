/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 07:25:43 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/19 15:43:09 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**strtab;

	if (!(strtab = (char**)malloc(sizeof(char*) * (ft_wcount_char(s, c) + 1))))
		return (NULL);
	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[i] && !(s[i] == c))
			i++;
		if (!(strtab[k++] = ft_strdup_range(s, j, i)))
			return (NULL);
		while (s[i] && s[i] == c)
			i++;
	}
	strtab[k] = 0;
	return (strtab);
}
