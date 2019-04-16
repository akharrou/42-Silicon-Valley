/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:51:27 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/23 14:55:54 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**    NAME
**         get_piece_height -- get the height of a tetromino piece
**
**    SYNOPSIS
**         #include "fillit.h"
**
**         t_uint8
**         get_piece_height(t_char buf[PIECE_SIZE]);
**
**    PARAMETERS
**
**         t_char buf[PIECE_SIZE]      A string containing the piece as read
**                                     from the input file.
**
**    DESCRIPTION
**         Iterates through the rows of a piece 1 by 1 and checks whether the
**         bit representation of the entire row (i.e of the 4 characters in
**         the row) is equal to that of a row of a bit representation of 4 dot
**         characters; if it isn't equal then we know the row must have a
**         hashtag somewhere.
**
**         The bit (binary) representation of a row of 4 dot characters is:
**
**                 0010 1110 | 0010 1110 | 0010 1110 | 0010 1110
**                     '.'         '.'         '.'        '.'
**
**         ... i.e in binary  00101110001011100010111000101110
**         ... i.e in decimal 774778414
**
**         Hence the macro:
**
**                 #define FOUR_DOTS		(774778414)
**
**         To capture a row in 1 go, we typecast the row of 4 individual
**         characters (i.e bytes) to an int type (i.e also 4 bytes but
**         grouped), which forms 1 single integer value that we can directly
**         compare with another integer value.
**
**         Hence the macro:
**
**                 #define ROW_CHARACTERS	(*((int *)&buf[i]))
**
**    RETURN VALUES
**         Returns the height of a tetromino piece.
*/

#define ROW_CHARACTERS	(*((int *)&buf[i]))
#define FOUR_DOTS		(774778414)

t_uint8			get_piece_height(t_char buf[PIECE_SIZE])
{
	t_uint8		height;
	t_uint8		i;

	i = 0;
	height = 0;
	while (PIECE_SIZE > i)
	{
		if (ROW_CHARACTERS != FOUR_DOTS)
			++height;
		i += 5;
	}
	return (height);
}

/*
**    NAME
**         get_piece_width -- get the width of a tetromino piece
**
**    SYNOPSIS
**         #include "fillit.h"
**
**         t_uint8
**         get_piece_width(t_char buf[PIECE_SIZE]);
**
**    PARAMETERS
**
**         t_char buf[PIECE_SIZE]      A string containing the piece as read
**                                     from the input file.
**
**    DESCRIPTION
**         Iterates through the columns of a piece 1 by 1 and checks
**         whether they contain hashtags, if so width is incremented.
**
**    RETURN VALUES
**         Returns the width of a tetromino piece.
*/

t_uint8			get_piece_width(t_char buf[PIECE_SIZE])
{
	t_uint8		width;
	t_uint8		i;

	i = 0;
	width = 0;
	while (PIECE_COLS > i)
	{
		if (buf[0 + i] == '#' ||
			buf[5 + i] == '#' ||
			buf[10 + i] == '#' ||
			buf[15 + i] == '#')
		{
			++width;
		}
		++i;
	}
	return (width);
}

/*
**    NAME
**         get_piece_mask -- get an unsigned 64 bit integer representation of
**                           a tetromino piece
**
**    SYNOPSIS
**         #include "fillit.h"
**
**         t_uint64
**         get_piece_mask(t_uint64 piece_mask, t_char buf[PIECE_SIZE]);
**
**    PARAMETERS
**
**         t_uint64 piece_mask         An unsigned 64 bit integer that will be
**                                     zero'd and used to represent the
**                                     tetromino piece.
**
**                                     PS: there is no point to this parameter,
**                                     this is just because the 42's norm
**                                     doesn't allow more than 5 variables.
**
**         t_char buf[PIECE_SIZE]      A string containing the piece as read
**                                     from the input file.
**
**    DESCRIPTION
**         Adds a mask to an unsigned 64 bit integer. The mask is a
**         represention of the tetromino piece contained in 'buf'.
**
**       — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
**
**         Row by row, the piece is read; each row is read from its first
**         character to its last, starting by the last row of the piece.
**
**         The process is as follows:
**
**       — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
**
**               We start with an unsigned 64 bit integer (an unsigned long
**               long) of value 0, i.e with this:
**
**         last bit ——>   0000 0000 0000 0000
**                        0000 0000 0000 0000
**                        0000 0000 0000 0000
**                        0000 0000 0000 0000   <—— first bit
**
**               ...this 64 bit integer will be known as: 'piece_mask'
**
**               Also each row of the tetromino will use a temporary unsigned
**               16 bit integer (a unsigned short); one of these:
**
**                      last bit ——>   0000 0000 0000 0000   <—— first bit
**
**               ...this short will be known as: 'row_mask'
**
**       — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
**
**               The goal of this function is to turn a piece from the file
**               into a 64 bit representation that can then be used to solve
**               and fill the board.
**
**               Hashtags are turned into 1's and the piece is placed at the
**               top-left most area of the 64 bit integer, ex:
**
**						... a piece that looks like this:
**
**                                      ..#.
**                                      ###.
**                                      ....
**                                      ....
**
**						... will end up like this on the 64 bit integer:
**
**
**                 (uint 64)    0010 0000 0000 0000
**                              1110 0000 0000 0000
**                              0000 0000 0000 0000
**                              0000 0000 0000 0000
**
**						... and a piece that looks like this:
**
**                                      #...
**                                      #...
**                                      ##..
**                                      ....
**
**						... will end up like this on the 64 bit integer:
**
**
**                 (uint 64)    1000 0000 0000 0000
**                              1000 0000 0000 0000
**                              1100 0000 0000 0000
**                              0000 0000 0000 0000
**
**       — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
**
**               Starting from the last row, every row of the tetromino piece
**               is iterated through. The iteration of a row goes as follows:
**
**               (starting from the first character in the row)
**
**                    1 - the (short) is shifted by 1 to the left (regardless
**                        of whether or not it is empty (i.e still 0))
**
**                    2 - a check is made to see if the current character
**                        is a dot or a hashtag...
**
**                          > if the character is a dot: nothing is done
**                          > if the character is a hashtag: '1' is
**                            appended to the end of the (short), i.e
**                            '1' is OR'ed ('|') with the 'row_mask'
**
**                    3 - a check is made to see if we have encountered a
**                        hashtag character by now
**
**                          > if a hashtag has been encounterd: nothing is done
**                          > if a hashtag has yet to be encounterd: a counter
**                            of leading '0's (i.e dots) is incremented
**
**                        (this variable will be needed to correct the
**                        placement of the tetromino piece on the 64 bit
**                        integer at the end)
**
**               After the entire row has been iterated through, a check is
**               made to see if the row contained any hashtags, i.e if
**               'row_mask' has had a 1 appended to it, i.e if 'row_mask'
**               is greater than 0:
**
**                     > if it isn't: nothing is done, the row is basically
**                       skipped
**                     > if it is: the row is added to the (top) of the
**                       64 bit integer. A couple of step before the adding of
**                       the row to the 'piece_mask', first the previous row in
**                       the 64 bit integer is pushed down a row; and 2nd the
**                       current 'row_mask' is shifted by 12 bits, this is to
**                       move the first 4 bits to the end of the short; this is
**                       again important to get the placement of the tetromino
**                       piece correct on the 64 bit integer.
**
**                       ex:
**
**                   1) - - - - - - - - - - - - - - - - - - - - - - -
**
**                         (uint 64)    0010 0000 0000 0000  <— this row
**                                      0000 0000 0000 0000
**                                      0000 0000 0000 0000
**                                      0000 0000 0000 0000
**
**                                        piece_mask << 16
**
**                         (uint 64)    0000 0000 0000 0000
**                                      0010 0000 0000 0000  <— is now here
**                                      0000 0000 0000 0000
**                                      0000 0000 0000 0000
**
**                   2) - - - - - - - - - - - - - - - - - - - - - - -
**
**                         (short)      0000 0000 0000 0110
**                                                       ^
**                                                     these bits
**
**                                        row_mask << 12
**
**                         (short)      0110 0000 0000 0000
**                                        ^
**                                   are now here
**
**                   3) - - - - - - - - - - - - - - - - - - - - - - -
**
**                         (uint 64)    0000 0000 0000 0000  <— we add here
**                                      0010 0000 0000 0000
**                                      0000 0000 0000 0000
**                                      0000 0000 0000 0000
**
**                                     piece_mask | row_mask
**
**                         (uint 64)    0110 0000 0000 0000  <— the current row
**                                      0010 0000 0000 0000
**                                      0000 0000 0000 0000
**                                      0000 0000 0000 0000
**
**               After that is done, we keep track compare the current minimum
**               number of leading dots we've encountered so far, to the current
**               rows leading 'dots', we keep the minimum of the two.
**
**
**          ~ loop (we do this process for each row of the tetromino)
**
**
**       — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
**
**               At the end, with a tetromino piece like this (for example):
**
**                                      ..#.
**                                      ..#.
**                                      .##.
**                                      ....
**
**						... we end up with something that looks like this:
**
**
**                 (uint 64)    0010 0000 0000 0000
**                              0010 0000 0000 0000
**                              0110 0000 0000 0000
**                              0000 0000 0000 0000
**
**               So finally, we must shift the piece to the left until it
**               is touching the wall (until it is at the top-left most
**               corner).
**
**               That's why we keep track of the leading zero's, but more
**               specifically the minimum leading zero of the piece's rows
**               (i.e the row that contains the least leading 'dots').
**
**               In this case we see that the third row has a single dot
**               that leads..
**
**                                      ..#.
**                                      ..#.
**                     right here ——>   .##.
**                                      ....
**
**               It is indeed the row with the minimum number of leading zero's
**               (i.e 'dots', i.e a minimum leading dot count of 1).
**
**               The 64 bit integer is then shifted by that number.. to finally
**               place it on the most left of the 64 bit integer; we get the
**               result we are looking for:
**
**                 (uint 64)    0100 0000 0000 0000
**                              0100 0000 0000 0000
**                              1100 0000 0000 0000
**                              0000 0000 0000 0000
**
**       — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
**
**               We return this 64 bit integer And that's it we're done.
**
**
**    RETURN VALUES
**         Returns an unsigned 64 bit integer containing a mask that represents
**         the tetromino piece contained in 'buf'.
*/

t_uint64		get_piece_mask(t_uint64 piece_mask, t_char buf[PIECE_SIZE])
{
	t_uint8		min_leading_dots;
	t_uint8		leading_dots;
	t_uint16	row_mask;
	t_int8		row;
	t_int8		col;

	row = 4;
	piece_mask = 0;
	min_leading_dots = 4;
	while (--row > -1)
	{
		row_mask = 0;
		leading_dots = 0;
		col = row * (PIECE_COLS + 1);
		while (PIECE_COLS > col % (PIECE_COLS + 1))
		{
			row_mask <<= 1;
			row_mask = (buf[col++] == '#') ? row_mask | 1 : row_mask;
			leading_dots += (row_mask == 0) ? 1 : 0;
		}
		if (row_mask > 0)
			piece_mask = (piece_mask << 16) | (row_mask << 12);
		min_leading_dots = MIN(leading_dots, min_leading_dots);
	}
	return (piece_mask << min_leading_dots);
}
