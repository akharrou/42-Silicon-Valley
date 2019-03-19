/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:55:07 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/19 00:10:14 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void 		place_next_piece(t_game tetromino, t_uint8 i)
{
	t_uint8	i;
	t_uint8	row;
	t_uint8	col____times_shifted;

	if (i == tetromino.num_pieces)
	{
		print_board(tetromino);
		exit(EXIT_SUCCESS);
	}
	row = -1;
	while (tetromino.board.size - tetromino.pieces[i].height >= ++row)
	{
		col____times_shifted = -1;
		while (tetromino.board.size - tetromino.pieces[i].width >= ++col____times_shifted)
		{
			if (((tetromino.pieces[i] >> col____times_shifted) & tetromino.board.matrix[row]) == 0) <==> if (PIECE_PLACEMENT_POSSIBLE == TRUE)
			{
				tetromino.board.matrix[row] = tetromino.pieces[i] ^ tetromino.board.matrix[row]; // <==> PLACE_PIECE(tetromino.pieces[i])
				place_next_piece(tetromino, i + 1);
				tetromino.board.matrix[row] = tetromino.pieces[i] ^ tetromino.board.matrix[row]; // <==> REMOVE_PIECE(tetromino.pieces[i])
			}
		}
	}
}

void 	fill_board(t_game tetromino)
{
	tetromino.board.size = FLOOR(ft_sqrt(tetromino.num_pieces * 4));
	ft_bzero(tetromino.board.matrix, sizeof(tetromino.board.matrix));
	while (MAX_BOARD_SIZE >= tetromino.board.size)
	{
		place_next_piece(tetromino, 0);
		++tetromino.board.size;
	}
}
