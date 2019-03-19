/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:51:27 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/19 00:11:01 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_uint8			get_piece_height(t_char buf[PIECE_SIZE])
{
	t_uint8		height;
	t_uint8		i;

	i = 0;
	height = 0;
	while (PIECE_SIZE > i)
	{
		if (*((int *)&buf[i]) != FOUR_DOTS)
			++height;
		i += 5;
	}
	return (height);
}

t_uint8			get_piece_width(t_char buf[PIECE_SIZE])
{
	t_uint8		width;
	t_uint8		i;

	i = 0;
	width = 0;
	while (PIECE_COLS > i)
	{
		if (buf[0 + i] == '#' ||
			buf[5 + i] == '#' ||
			buf[10 + i] == '#' ||
			buf[15 + i] == '#')
		{
			++width;
		}
		++i;
	}
	return (width);
}

t_uint64	get_piece_mask(t_uint64 piece_mask, t_char buf[PIECE_SIZE])
{
	t_uint16	min_leading_dots;
	t_uint16	leading_dots;
	t_uint16	row_mask;
	t_int8		i;

	min_leading_dots = 4;
	i = PIECE_SIZE - 1;
	while (i > 0)
	{
		row_mask = 0;
		leading_dots = 0;
		while (--i > -1 && buf[i] != '\n')
		{
			row_mask <<= 1;
			if (buf[i] == '#')
				row_mask |= 1;
			else if (row_mask == 0)
				++leading_dots;
		}
		if (row_mask > 0)
			piece_mask = ((piece_mask << 16) | (row_mask << 12));
		min_leading_dots = MIN(leading_dots, min_leading_dots);
	}
	return (piece_mask <<= min_leading_dots);
}


TODAY:

	- test piece legality checkers
	- fix main backtracking function
	- print the board

	- have fun with debugging
