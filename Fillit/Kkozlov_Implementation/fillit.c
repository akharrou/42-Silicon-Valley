/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 09:48:06 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/27 17:46:59 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

void	align_tet(t_tetromino *tet)
{
	char	r;
	char	c;
	char	zr;


	r = -1;
	while (++r < TETSIZE)
	{
		zr = 0;
		c = -1;
		while (++c < TETSIZE)
			if (!ft_test_bit(&tet->pattern, sizeof(tet->pattern), r * BYTE / 2 + c))
				++zr;
		if (zr == TETSIZE)
			tet->pattern >>= zr;
	}
}

void	find_inpoint(t_tetromino *tet)
{
	char	r;
	char	c;
	char	x;
	char	y;

	x = -1;
	y = -1;
	r = -1;
	while (++r < TETSIZE)
	{
		c = -1;
		while (++c < TETSIZE)
		{
			if (ft_test_bit(&tet->pattern, sizeof(tet->pattern), r * BYTE / 2 + c))
			{
				if (x == -1 || x > c)
					x = c;
				if (y == -1)
					y = r;
			}
		}
	}
	ft_putnbr_endl(x);
	ft_putnbr_endl(y);
}	

//int		insert_tet(t_square *square, t_tetromino *tet)






