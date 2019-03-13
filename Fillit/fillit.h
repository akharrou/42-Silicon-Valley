/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 09:33:11 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/12 18:19:15 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# include "libft/Includes/libft.h"

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

# define MAX_BOARD_ROW          52
# define MAX_BOARD_COL          52
# define MAX_NUM_PIECES         26
# define PIECE_ROWS             4
# define PIECE_COLS             4
# define PIECE_SIZE             20
# define BLOCK_CHARS_PER_PIECE  4

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

typedef struct	s_tetromino_piece
{
	t_char		id;
	t_char		coordinates[BLOCK_CHARS_PER_PIECE][2];
}				t_piece;

typedef struct	s_game
{
	t_char		board[MAX_BOARD_ROW][MAX_BOARD_COL];
	t_piece		pieces[MAX_NUM_PIECES];
	t_uint8		num_pieces;
	t_uint8		last_row;
	t_uint8		last_col;
}				t_game;

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

# define CHECKSUM_VALUE (('#' * 4) + ('.' * 12) + ())
# define SET_OFFSETS(row, col) { offset[0] = row; offset[1] = col; }
# define CUR_ROW i / 5
# define CUR_COL i % 5

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

# define USAGE "usage: ./fillit file"
# define INVALID_INPUT "error"
# define ERROR "error"

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

#endif
