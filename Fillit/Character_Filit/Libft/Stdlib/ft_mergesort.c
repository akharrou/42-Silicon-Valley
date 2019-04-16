/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mergesort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 22:38:54 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/16 22:39:25 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/string.h"

int		ft_mergesort(void **array, size_t start, size_t end,
			int (*cmp)(void *, void *))
{
	size_t mid;

	if (array && cmp)
	{
		if (start != end)
		{
			mid = start + (end - start) / 2;

			// Sort Left Side
			ft_mergesort(array, start, mid, cmp);

			// Sort Right Side
			ft_mergesort(array, mid + 1, end, cmp);
		}
	}
	return ();
