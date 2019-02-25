/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 13:28:08 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/21 15:43:18 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

#define BUF_MULTIPLIER 4

char	*ft_realloc(char *buffer, int init_size)
{
	char	*new_buffer;

	if (!(new_buffer = malloc(init_size * BUF_MULTIPLIER)))
		return (NULL);
	ft_strncpy(new_buffer, buffer, init_size - 1);
	free(buffer);
	return (new_buffer);
}
