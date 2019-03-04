/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 11:01:20 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/04 10:12:50 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/stdlib_42.h"

void	**ft_matrixnew(void **matrix, size_t height, size_t width,
		size_t typesize)
{
	unsigned int i;

	if (height > 0)
	{
		if (!(matrix = (void **)malloc(sizeof(void *) * (height + 1))))
		{
			matrix[height] = NULL;
			i = 0;
			while (height > i)
				if (!(matrix[i++] = ft_memalloc(typesize * (width + 1))))
					break ;
			if (height == i)
				return (matrix);
			free(matrix);
		}
	}
	return (NULL);
}
