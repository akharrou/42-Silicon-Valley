/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 20:25:06 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/17 21:05:05 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int i;

	if (dst && src && n > 0)
	{
		i = 0;
		while (((char *)src)[i] != '\0' && i < n)
		{
			((char *)dst)[i] = ((char *)src)[i];
			if (((char *)src)[i] == (unsigned char)c)
				return (dst + i + 1);
			i++;
		}
	}
	return (NULL);
}


#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char *av[])
{
	if (ac != 5)
	{
		printf("Usage: ./program dst src c n\n");
		return (1);
	}

	printf("System Lib:\n—————————————————————\n%s\n", memccpy((void *)av[1], (void*)av[2], (int)av[3], atoi(av[4])));

	// printf("\nMy Function:\n—————————————————————\n%s\n", ft_memccpy((void *)av[1], (void*)av[2], (int)av[3], atoi(av[4])));

	return (0);
}
