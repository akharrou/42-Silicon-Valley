/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 18:56:28 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/12 20:49:17 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_bool		legal(t_piece piece)
{
	t_bool neighbor;
	t_int8 dif;
	t_uint8 block;
	t_uint8 i;

	block = -1;
	while (BLOCK_CHARS_PER_PIECE > ++block)
	{
		i = -1;
		neighbor = FALSE;
		while (BLOCK_CHARS_PER_PIECE > ++i)
		{
			if (i != block)
			{

			}
		}
	}
}

t_piece	create_piece(t_char id, t_char buf[PIECE_SIZE])
{
	t_piece piece;
	t_uint8 block_count;
	t_uint8 offset[2];
	t_uint8 first;
	t_uint8 i;

	i = -1;
	first = 1;
	block_count = 0;
	while (PIECE_SIZE > ++i)
		if (buf[i] == '#')
		{
			if (first-- > 0)
				SET_OFFSETS(i / 5, i % 5);
			piece.coordinates[block_count][0] = CUR_ROW - offset[0];
			piece.coordinates[block_count][1] = CUR_COL - offset[1];
			++block_count;
		}
	if (!legal(piece))
		EXIT(INVALID_INPUT);
	piece.id = id;
	return (piece);
}

/*
** The checksum starts with the number of times the conditions should
** return true (i.e 1). 4 times for the hash character, 12 times for the
** dot character and 4 times for the return line; not more not less.
**
** By the end of the process, checksum should be equal to precisely: 0.
*/

t_bool		valid_chars(t_char buf[20])
{
	t_uint16	checksum;
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

t_uint8	read_pieces(int fd, t_piece (*piece)[MAX_NUM_PIECES])
{
	t_char		letter;
	t_char		buf[20];
	ssize_t		ret;
	t_uint8		i;

	i = -1;
	letter = 'A';
	while (MAX_NUM_PIECES > ++i)
	{
		ret = read(fd, buf, PIECE_SIZE);
		if (ret == PIECE_SIZE && valid_chars(buf))
			(*piece)[i] = create_piece(letter++, buf);
		ret = read(fd, buf, 1);
		if (ret == 0)
			break ;
		else if (ret == -1 || buf[0] != '\n')
			EXIT(INVALID_INPUT);
	}
	return (i);
}
