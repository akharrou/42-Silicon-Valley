/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:51:27 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/16 18:36:17 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**    NAME
**         biggest_axis_length -- returns the biggest integer; either
**                                the sum of all vertical lengths of each
**                                tetromino piece or the sum of all horizontal
**                                lengths of each tetromino piece.
**
**    SYNOPSIS
**         #include "fillit.h"
**
**         t_uint8
**         biggest_axis_length(t_game tetromino);
**
**    PARAMETERS
**
**         t_piece piece[MAX_NUM_PIECES]      Array containing tetromino pieces
**                                            (t_piece structures).
**
**         t_uint8 n_pieces                   Number of tetromino pieces in the
**                                            array of tetromino pieces
**                                            'piece[]'.
**
**    DESCRIPTION
**         Sums up all the vertical lengths of all the tetromino pieces in the
**         array of tetromino pieces as well as all the horizontal lengths;
**         returning the biggest integer of the two.
**
**         The root of this integer will be the starting root size of our board.
**
**         This is a premature optimization to save us from having to try a
**         bunch of smaller board sizes that we are sure won't fit all the
**         pieces.
**
**    RETURN VALUES
**         Returns the biggest integer; either the sum of all vertical lengths
**         or the sum of all horizontal lengths of all tetromino pieces.
*/

t_uint8		biggest_axis_length(t_piece piece[MAX_NUM_PIECES], t_uint8 n_pieces)
{
	t_int8		total_horizontal_length;
	t_int8		total_vertical_length;
	t_int8		i;

	i = -1;
	total_vertical_length = 0;
	total_horizontal_length = 0;
	while (n_pieces > ++i)
	{
		total_horizontal_length += piece[i].horizontal_length;
		total_vertical_length += piece[i].vertical_length;
	}
	return (MAX(total_horizontal_length, total_vertical_length));
}

/*
**    NAME
**         initialize_board -- initializes the board of a tetromino game.
**
**    SYNOPSIS
**         #include "fillit.h"
**
**         t_board
**         initialize_board(t_game tetromino);
**
**    PARAMETERS
**
**         t_game         A tetromino game structure (a type t_game, defined
**                        in 'fillit.h').
**
**    DESCRIPTION
**         Initializes the board of a tetromino game to all empty characters.
**
**    RETURN VALUES
**         Returns a tetromino board that is in an initialized state.
*/
#include "math.h"
t_board		initialize_board(t_game tetromino)
{
	t_int8		row;
	t_int8		col;
	t_int8		safe_board_size;

	tetromino.board.rootsize = 12;
	safe_board_size = 20;
	row = -1;
	while (safe_board_size > ++row)
	{
		col = -1;
		while (safe_board_size > ++col)
			tetromino.board.matrix[row][col] = '.';
	}
	return (tetromino.board);
}

/*
**    NAME
**         print_board -- prints a tetromino board.
**
**    SYNOPSIS
**         #include "fillit.h"
**
**         void
**         print_board(t_game tetromino);
**
**    PARAMETERS
**
**         t_game         A tetromino game (a type t_game) that has its board
**                        filled.
**
**    DESCRIPTION
**         Iterates through board printing each of its character.
**
**    RETURN VALUES
**         None.
*/

void		print_board(t_board board)
{
	t_int8		row;
	t_int8		col;

	row = 0;
	while (board.rootsize > row)
	{
		col = 0;
		while (board.rootsize > col)
		{
			write(1, &board.matrix[row][col], 1);
			++col;
		}
		write(1, "\n", 1);
		++row;
	}
}
