/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:55:07 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/19 21:20:54 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void 		place_next_piece(t_game tetromino, t_uint8 i)
{
	t_uint8	col____times_shifted;
	t_uint8	row;

	if (i == tetromino.num_pieces)
	{
		// print_board(tetromino);
		ft_putstr("\n[FINAL BOARD]:\n");
		print_bit_board(tetromino.board.matrix, 16);
		exit(EXIT_SUCCESS);
	}
	row = -1;
	while (tetromino.board.size - tetromino.pieces[i].height >= ++row)
	{
		col____times_shifted = -1;
		while (tetromino.board.size - tetromino.pieces[i].width >= ++col____times_shifted)
		{

			t_uint64 var = ((tetromino.pieces[i].mask >> col____times_shifted) & *(t_uint64 *)&tetromino.board.matrix[row]);
			if (var == 0) // <==> if (PIECE_PLACEMENT_POSSIBLE == TRUE)
			{

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —  */
					// print_bit_board(tetromino.board.matrix, 16);
/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —  */

				*(t_uint64 *)&tetromino.board.matrix[row] = (tetromino.pieces[i].mask >> col____times_shifted) ^ *(t_uint64 *)&tetromino.board.matrix[row]; // <==> PLACE_PIECE(tetromino.pieces[i])

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —  */
					// print_bit_board(tetromino.board.matrix, 16);
/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —  */

				place_next_piece(tetromino, i + 1);
				*(t_uint64 *)&tetromino.board.matrix[row] = (tetromino.pieces[i].mask >> col____times_shifted) ^ *(t_uint64 *)&tetromino.board.matrix[row]; // <==> REMOVE_PIECE(tetromino.pieces[i])

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —  */
					// print_bit_board(tetromino.board.matrix, 16);
/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —  */

			}
		}
	}
}

void 	fill_board(t_game tetromino)
{
	tetromino.board.size = FLOOR(ft_sqrt(tetromino.num_pieces * 4));
	ft_bzero(tetromino.board.matrix, sizeof(tetromino.board.matrix));

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —  */
	// ft_putstr("\n[BOARD SIZE] ——> "); ft_putnbr(tetromino.board.size); ft_putstr("\n");
	// print_bit_board(tetromino.board.matrix, 16);
/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —  */

	while (MAX_BOARD_SIZE >= tetromino.board.size)
	{
		place_next_piece(tetromino, 0);
		++tetromino.board.size;
	}
}
