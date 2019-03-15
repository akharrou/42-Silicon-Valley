/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:55:07 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/14 22:56:40 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_board			initialize_board(t_game tetromino)
{
	t_int8		row;
	t_int8		col;

	tetromino.board.rootsize = tetromino.num_pieces + 1;
	row = -1;
	while (tetromino.board.rootsize > ++row)
	{
		col = -1;
		while (tetromino.board.rootsize > ++col)
			tetromino.board.matrix[row][col] = '.';
	}
	return (tetromino.board);
}

static	t_bool	check(t_piece piece, t_board board, t_uint8 row, t_uint8 col)
{

}

t_board			place_piece(t_game tetromino, t_uint8 index)
{

}

t_bool			place_next_piece(t_game tetromino)
{
	t_int8		i;
	t_int8		j;
	t_game		tetromino_copy;

	i = -1;
	while (tetromino.num_pieces > ++i)
		if (tetromino.piece[i].used == FALSE)
		{
			// ...
		}
	return ();
}

t_game			fill_board(t_game tetromino)
{
	t_int8		i;
	t_int8		j;
	t_game		tetromino_copy;

	while (1)
	{
		i = -1;
		while (tetromino.num_pieces > ++i)
		{
			j = 0;
			while (BOARD_ROWS > CUR_BOARD_ROW)
				while (BOARD_COLS > CUR_BOARD_COL)
				{
					if (PIECE_PLACEMENT_POSSIBLE)
					{
						tetromino_copy = place_piece(PIECE(i), tetromino);
						if (find_next_piece(tetromino_copy) == SUCCESS)
							return (tetromino);
						backtrack();
					}
					++j;
				}
		}
		++tetromino.board.rootsize;
	}
}


						tetromino.piece[i].used = TRUE;
						saved_board = tetromino.board;
						tetromino.board = place_piece(tetromino, i);
						if (find_next_piece(tetromino) == SUCCESS)
							return (tetromino);
						tetromino.board = saved_board;
						tetromino.piece[i].used = FALSE;



