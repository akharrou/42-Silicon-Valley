/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfre.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:26:25 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/18 19:11:43 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/string_42.h"
#include "../Includes/stdlib_42.h"

char	*ft_strjoinfre(char const *s1, char const *s2, int free_s1, int free_s2)
{
	char *new_str;

	new_str = ft_strjoin(s1, s2);
	if (free_s1 && s1)
		free((void *)s1);
	if (free_s2 && s2)
		free((void *)s2);
	return (new_str);
}
