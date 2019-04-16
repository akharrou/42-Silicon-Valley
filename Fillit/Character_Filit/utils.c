/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:51:27 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/18 08:31:20 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static double	tt_axis_lengths_multiplied(t_piece piece[MAX_PIECES],
					t_uint8 n_pieces)
{
	double		total_horizontal_length;
	double		total_vertical_length;
	t_int8		tmp;
	t_int8		i;

	i = -1;
	total_vertical_length = 0;
	total_horizontal_length = 0;
	while (n_pieces > ++i)
	{
		tmp = piece[i].horizontal_length;
		total_horizontal_length += (double)((tmp == 3) ? 2.333333: tmp);
		tmp = piece[i].vertical_length;
		total_vertical_length += (double)((tmp == 3) ? 2.333333: tmp);
	}
	return (total_horizontal_length * total_vertical_length);
}

/*
**    NAME
**         initialize_game -- sets the starting board size and sets the map
**                            to all empty characters.
**
**    SYNOPSIS
**         #include "fillit.h"
**
**         t_board
**         initialize_game(t_game tetromino);
**
**    PARAMETERS
**
**         t_game         A tetromino game structure (a type t_game, defined
**                        in 'fillit.h').
**
**    DESCRIPTION
**         Sets the starting board size according to the pieces given and fills
**         the board with empty characters.
**
**    RETURN VALUES
**         Returns a tetromino game that is in an initialized state.
*/

t_game		initialize_game(t_game tetromino)
{
	t_int8	row;
	t_int8	col;

	tetromino.board.rootsize = FLOOR(
		ft_sqrt(
			tt_axis_lengths_multiplied(tetromino.piece, tetromino.num_pieces)
				/ (double)tetromino.num_pieces));
	row = -1;
	while (MAX_BOARD_SIZE > ++row)
	{
		col = -1;
		while (MAX_BOARD_SIZE > ++col)
			tetromino.board.matrix[row][col] = '.';
	}
	return (tetromino);
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
