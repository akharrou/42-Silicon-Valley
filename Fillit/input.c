/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 18:56:28 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/14 21:06:53 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         read_pieces -- reads from a file and stores all (legal) tetromino
**                        pieces found into an array of tetromino pieces
**                        (t_piece array).
**
**    SYNOPSIS
**         #include "fillit.h"
**
**         t_game
**         read_pieces(ssize_t fd);
**
**    PARAMETERS
**
**         ssize_t fd        File descriptor to the
**                           file we will read from.
**
**    DESCRIPTION
**         Reads up to MAX_NUM_PIECES (the maximum number of pieces possible)
**         from 'fd', a file descriptor corresponding to a file containing a
**         series of tetromino pieces.
**
**         Every piece read goes through 2 checks:
**
**           - the first validates the characters of a piece, i.e that there
**             are exactly 4 hashtag characters '#', 12 dot characters '.' and
**             4 return line characters '\n'. It also makes sure that there is
**             is exactly for characters, '#' or '.', and a single return line
**             per line.
**
**           - the second checks the legality of each piece, that is to say
**             that each piece has its 4 blocks interlinked.
**
**         If a piece passes both tests, then the relative coordinates of
**         each of its blocks are stored. The structure kept is a 2 dimensional
**         (4 x 2) array:
**
**                        ——————————              ———————
**                       | block #1 |    ———>    | x | y |
**                        ——————————              ———————
**                       | block #2 |    ———>    | x | y |
**                        ——————————              ———————
**                       | block #3 |    ———>    | x | y |
**                        ——————————              ———————
**                       | block #4 |    ———>    | x | y |
**                        ——————————              ———————
**
**         If a piece fails one of the checks, the program prints 'error'
**         to screen and terminates the program calling the exit(2) function
**         with EXIT_FAILURE.
**
**    RETURN VALUES
**         If successful, returns a tetromino game (t_game) with pieces;
**         otherwise calls the exit(2) function with EXIT_FAILURE.
*/

#include "fillit.h"

static void		sort_coordinates(t_int8 (*cord)[BLOCK_CHARS_PER_PIECE][2])
{
	t_uint8		out_of_order;
	t_uint8		n;
	t_int8		tmp;

	out_of_order = TRUE;
	while (out_of_order)
	{
		n = 1;
		out_of_order = FALSE;
		while (BLOCK_CHARS_PER_PIECE > n + 1)
		{
			if (SAME_ROW && ABS(BLOCK_COL(n)) > ABS(BLOCK_COL(n + 1)))
			{
				SWAP_BLOCKS(tmp, BLOCK_COL(n), BLOCK_COL(n + 1));
				out_of_order = TRUE;
			}
			++n;
		}
	}
}

static t_bool	legal(t_piece piece)
{
	t_bool		neighbor;

	t_uint8		block_n;
	t_int8		r_dif;
	t_int8		c_dif;
	t_int8		i;

	sort_coordinates(&piece.coordinates);
	block_n = 0;
	while (BLOCK_CHARS_PER_PIECE - 1 > block_n)
	{
		i = block_n;
		++block_n;
		neighbor = FALSE;
		while (i >= 0 && neighbor == FALSE)
		{
			r_dif = piece.coordinates[i][0] - piece.coordinates[block_n][0];
			c_dif = piece.coordinates[i][1] - piece.coordinates[block_n][1];
			if (TOUCHING_ROW(r_dif, c_dif) || TOUCHING_COLUMN(r_dif, c_dif))
				neighbor = TRUE;
			--i;
		}
		if (neighbor == FALSE)
			return (FALSE);
	}
	return (TRUE);
}

/*
** The checksum starts with the number of times the conditions should
** return true (i.e 1). 4 times for the hash character, 12 times for the
** dot character and 4 times for the return line; not more, not less.
**
** By the end of the process, 'checksum' should be equal to precisely 0.
*/

static t_bool	valid_chars(t_char buf[PIECE_SIZE])
{
	t_uint8		checksum;
	t_uint8		row;
	t_uint8		i;

	i = -1;
	row = -1;
	checksum = (4 * 1) + (12 * 2) + (4 * 3);
	while (PIECE_ROWS > ++row)
	{
		checksum -= (buf[++i] == '#');
		checksum -= (buf[i] == '.') ? 2 : 0;
		checksum -= (buf[++i] == '#');
		checksum -= (buf[i] == '.') ? 2 : 0;
		checksum -= (buf[++i] == '#');
		checksum -= (buf[i] == '.') ? 2 : 0;
		checksum -= (buf[++i] == '#');
		checksum -= (buf[i] == '.') ? 2 : 0;
		checksum -= (buf[++i] == '\n') ? 3 : 0;
	}
	return (checksum == 0);
}

static t_piece	create_piece(t_char id, t_char buf[PIECE_SIZE])
{
	t_piece 	piece;

	t_int8		first;
	t_uint8 	block_count;
	t_uint8 	offset[2];
	t_uint8 	i;

	i = -1;
	first = 1;
	block_count = 0;
	while (PIECE_SIZE > ++i && BLOCK_CHARS_PER_PIECE > block_count)
	{
		if (buf[i] == '#')
		{
			if (first-- > 0)
				SET_OFFSETS(CUR_ROW(i), CUR_COL(i));
			piece.coordinates[block_count][0] = CUR_ROW(i) - offset[0];
			piece.coordinates[block_count][1] = CUR_COL(i) - offset[1];
			++block_count;
		}
	}
	if (!legal(piece))
		EXIT(INVALID_INPUT);
	piece.id = id;
	return (piece);
}

t_game			read_pieces(ssize_t fd)
{
	t_game		tetromino;
	t_char		buf[PIECE_SIZE];
	t_char		piece_id;
	ssize_t		ret;
	t_uint8		i;

	i = -1;
	piece_id = 'A';
	while (MAX_NUM_PIECES > ++i)
	{
		ret = read(fd, buf, PIECE_SIZE);
		if (ret == PIECE_SIZE && valid_chars(buf))
			tetromino.piece[i] = create_piece(piece_id++, buf);
		else
			EXIT(INVALID_INPUT);
		ret = read(fd, buf, 1);
		if (ret == 0)
			break ;
		else if (ret == -1 || buf[0] != '\n')
			EXIT(INVALID_INPUT);
	}
	tetromino.num_pieces = i;
	return (tetromino);
}
