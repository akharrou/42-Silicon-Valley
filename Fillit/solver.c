/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:55:07 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/14 21:10:56 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_board	initialize_board(t_game tetromino)
{
	t_uint8	row;
	t_uint8	col;
	t_board initialized_board;

	initialized_board.rootsize = tetromino.num_pieces + 1;
	row = -1;
	while (tetromino.board.rootsize > ++row)
	{
		col = -1;
		while (tetromino.board.rootsize > ++col)
			tetromino.board.matrix[row][col] = '.';
		++row;
	}
	return (tetromino.board);
}

t_bool	check(t_piece piece, t_board board, t_uint8 row, t_uint8 col)
{

}

t_board	place_piece(t_game tetromino, t_uint8 index)
{

}

t_bool	find_next_piece(t_game tetromino)
{
	t_int8	i;
	t_int8	row;
	t_int8	col;

	i = -1;
	while (tetromino.num_pieces > ++i)
		if (tetromino.piece[i].used == FALSE)
		{
			row = -1;
			while (tetromino.rootsize > ++row)
			{
				col = -1;
				while (tetromino.rootsize > ++col)
				{
					if (check(tetromino.piece[i], tetromino.board, row, col))
						if (find_next_piece(place_piece(tetromino)) == SUCCESS)
							return (tetromino);
				}
			}
		}
	return ();
}

t_game	fill_board(t_game tetromino)
{
	t_int8		i;
	t_int8		count;
	t_board		saved_board;

	tetromino.board = initialize_board(tetromino);
	while (1)
	{
		i = -1;
		while (tetromino.num_pieces > ++i)
		{
			count = 0;
			while (BOARD_ROWS > CUR_BOARD_ROW)
				while (BOARD_COLS > CUR_BOARD_COL)
					if (CUR_CELL == EMPTY)
						if (LEGAL)
					{
						tetromino.piece[i].used = TRUE;
						saved_board = tetromino.board;
						tetromino.board = place_piece(tetromino, i);
						if (find_next_piece(tetromino) == SUCCESS)
							return (tetromino);
						tetromino.board = saved_board;
						tetromino.piece[i].used = FALSE;
					}
		}
		++tetromino.board.rootsize;
	}
}
