/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:55:07 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/17 12:38:02 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	t_bool	end_state(t_game tetromino)
{
	t_int8		i;

	i = -1;
	while (tetromino.num_pieces > ++i)
		if (tetromino.piece[i].used == FALSE)
			return (FALSE);
	return (TRUE);
}

static	t_bool	check(t_piece piece, t_board board, t_uint8 row, t_uint8 col)
{
	t_int8		i;
	t_uint8		r;
	t_uint8		c;

	i = 0;
	while (BLOCKS_PER_PIECE > ++i)
	{
		r = row + piece.coordinates[i][0];
		c = col + piece.coordinates[i][1];
		if (r >= board.rootsize || c >= board.rootsize ||
			board.matrix[r][c] != EMPTY)
		{
			return (FALSE);
		}
	}
	return (TRUE);
}

t_game			place_piece(t_game tetromino, t_uint8 i, t_uint8 row,
					t_uint8 col)
{
	t_int8		j;
	t_uint8		r;
	t_uint8		c;

	j = -1;
	while (BLOCKS_PER_PIECE > ++j)
	{
		r = row + PIECE(i).coordinates[j][0];
		c = col + PIECE(i).coordinates[j][1];
		tetromino.board.matrix[r][c] = PIECE(i).id;
	}
	tetromino.piece[i].used = TRUE;
	return (tetromino);
}

void			place_next_pieces(t_game tetromino)
{
	t_int8		i;
	t_uint8		j;
	t_game		new_state;

	if (end_state(tetromino))
	{
		print_board(tetromino.board);
		exit(EXIT_SUCCESS);
	}
	i = -1;
	while (tetromino.num_pieces > ++i)
		if (tetromino.piece[i].used == FALSE)
		{
			j = 0;
			while (BOARD_ROWS > CUR_BOARD_ROW)
			{
				if (PIECE_PLACEMENT_POSSIBLE)
				{
					new_state = place_piece(tetromino, i, CBR, CBC);
					place_next_pieces(new_state);
				}
				++j;
			}
		}
}

void			fill_board(t_game tetromino)
{
	t_int8		i;
	t_uint8		j;
	t_game		new_state;

	while (1)
	{
		i = -1;
		while (tetromino.num_pieces > ++i)
		{
			j = 0;
			while (BOARD_ROWS > CUR_BOARD_ROW)
			{
				if (PIECE_PLACEMENT_POSSIBLE)
				{
					new_state = place_piece(tetromino, i, CBR, CBC);
					place_next_pieces(new_state);
				}
				++j;
			}
		}
		++tetromino.board.rootsize;
	}
}
