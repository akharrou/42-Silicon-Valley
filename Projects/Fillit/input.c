/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 18:56:28 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/23 17:36:59 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_bool	legal_connections(t_char buf[PIECE_SIZE])
{
	t_uint8		block_connections;
	t_int8		i;

	i = -1;
	block_connections = 0;
	while (PIECE_SIZE > ++i)
		if (buf[i] == '#')
		{
			if ((i + 1) < PIECE_SIZE && buf[i + 1] == '#')
				block_connections++;
			if ((i - 1) >= 0 && buf[i - 1] == '#')
				block_connections++;
			if ((i + 5) < PIECE_SIZE && buf[i + 5] == '#')
				block_connections++;
			if ((i - 5) >= 0 && buf[i - 5] == '#')
				block_connections++;
		}
	return (block_connections == 6 || block_connections == 8);
}

/*
** The checksum starts with the number of times the conditions should
** return true (i.e 1). 4 times for the hash character, 12 times for the
** dot character and 4 times for the return line; not more, not less.
**
** By the end of the process, 'checksum' should be equal to precisely 0.
*/

static t_bool	legal_chars(t_char buf[PIECE_SIZE])
{
	t_uint8		checksum;
	t_int8		row;
	t_int8		i;

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

#define ROW (0)
#define COL (1)

static t_piece	generate_piece(t_char letter, t_char buf[PIECE_SIZE])
{
	t_uint8		offsets[2];
	t_uint8		block_n;
	t_piece		piece;
	t_int8		i;

	i = -1;
	block_n = 0;
	bzero(offsets, sizeof(offsets));
	while (PIECE_SIZE > ++i && BLOCKS_PER_PIECE > block_n)
		if (buf[i] == '#')
		{
			if (block_n == 0)
			{
				offsets[0] = i / (PIECE_ROWS + 1);
				offsets[1] = i % (PIECE_COLS + 1);
			}
			piece.coord[block_n][0] = (i / (PIECE_ROWS + 1)) - offsets[0];
			piece.coord[block_n][1] = (i % (PIECE_COLS + 1)) - offsets[1];
			++block_n;
		}
	piece.mask = get_piece_mask(0, buf);
	piece.width = get_piece_width(buf);
	piece.height = get_piece_height(buf);
	piece.letter = letter;
	return (piece);
}

t_uint8			read_pieces(ssize_t fd, t_piece (*piece)[MAX_PIECES],
					t_uint8 npieces)
{
	t_char		buf[PIECE_SIZE];
	t_char		piece_id;
	size_t		ret;
	t_int8		i;

	i = -1;
	piece_id = 'A';
	while (npieces > ++i)
	{
		ret = read(fd, buf, PIECE_SIZE);
		if (ret == PIECE_SIZE && legal_chars(buf) && legal_connections(buf))
			(*piece)[i] = generate_piece(piece_id++, buf);
		else
			EXIT(INVALID_INPUT);
		if (read(fd, buf, 1) == 0)
			break ;
		else if (buf[0] != '\n')
			EXIT(INVALID_INPUT);
	}
	return (i + 1);
}
