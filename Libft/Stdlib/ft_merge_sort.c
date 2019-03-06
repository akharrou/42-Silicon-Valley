/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 22:20:42 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/04 22:42:18 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/string.h"

int		ft_merge_sort(void **array, size_t start, size_t end,
			int (*cmp)(void *, void *))
{
	size_t mid;

	if (array && cmp)
	{
		if (start != end)
		{
			mid = start + (end - start) / 2;

			// Sort Left Side
			ft_merge_sort(array, start, mid, cmp);

			// Sort Right Side
			ft_merge_sort(array, mid + 1, end, cmp);
		}
	}
	return ();
