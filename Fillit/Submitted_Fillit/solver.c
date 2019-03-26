/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:55:07 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/23 18:23:56 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define BOARD_MATRIX *(t_uint64 *)&(*tetromino).board.matrix

int				place_next_piece(t_game *tetromino, t_uint8 i)
{
	t_uint64	piece_mask;
	t_int8		row;
	t_int8		col;

	if (i == (*tetromino).num_pieces)
		return (SUCCESS);
	piece_mask = (*tetromino).piece[i].mask;
	row = -1;
	while ((*tetromino).board.size - (*tetromino).piece[i].height >= ++row)
	{
		col = -1;
		while ((*tetromino).board.size - (*tetromino).piece[i].width >= ++col)
			if (((piece_mask >> col) & BOARD_MATRIX[row]) == 0)
			{
				(*tetromino).piece[i].row_placement = row;
				(*tetromino).piece[i].col_placement = col;
				BOARD_MATRIX[row] = (piece_mask >> col) ^ BOARD_MATRIX[row];
				if (place_next_piece(tetromino, i + 1) == SUCCESS)
					return (SUCCESS);
				BOARD_MATRIX[row] = (piece_mask >> col) ^ BOARD_MATRIX[row];
			}
	}
	return (FAILURE);
}

t_game			fill_board(t_game tetromino)
{
	tetromino.board.size = ft_sqrt(tetromino.num_pieces * BLOCKS_PER_PIECE);
	ft_bzero(tetromino.board.matrix, sizeof(tetromino.board.matrix));
	while (MAX_BOARD_SIZE >= tetromino.board.size)
	{
		if (place_next_piece(&tetromino, 0) == SUCCESS)
			break ;
		++tetromino.board.size;
	}
	return (tetromino);
}
