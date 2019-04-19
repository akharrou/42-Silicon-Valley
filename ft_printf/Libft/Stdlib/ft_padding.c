/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 07:40:24 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/18 08:13:41 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/stdlib_42.h"
#include "../Includes/string_42.h"

char	*ft_padding(int padding, char pad)
{
	char	pad_str[2];
	char	*buf;
	char	*tmp;
	int		i;

	if (padding < 1)
		return (NULL);
	i = -1;
	buf = NULL;
	tmp = buf;
	pad_str[0] = pad;
	pad_str[1] = '\0';
	while (padding > ++i)
	{
		buf = ft_strjoin(buf, pad_str);
		if (tmp)
			free(tmp);
		tmp = buf;
	}
	return (buf);
}
