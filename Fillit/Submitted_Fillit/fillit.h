/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 09:33:11 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/23 18:31:14 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

# include "libft/libft.h"

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

# define MAX_BOARD_SIZE     16
# define MAX_PIECES         26
# define MAX_TT_CHARS       (MAX_BOARD_SIZE * (MAX_BOARD_SIZE + 1))

# define BOARD_HEIGHT  	    (tetromino.board.size)
# define BOARD_LENGTH  	    (tetromino.board.size + 1)

# define PIECE_SIZE         20
# define PIECE_ROWS         4
# define PIECE_COLS         4

# define BLOCKS_PER_PIECE   4

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

typedef struct	s_tetromino_board
{
	t_uint8		size;
	t_uint16	matrix[MAX_BOARD_SIZE];
}				t_board;

typedef struct	s_tetromino_piece
{
	t_char		letter;
	t_uint64	mask;
	t_uint8		width;
	t_uint8		height;
	t_uint8		row_placement;
	t_uint8		col_placement;
	t_int8		coord[BLOCKS_PER_PIECE][2];
}				t_piece;

typedef struct	s_tetromino_game
{
	t_board		board;
	t_uint8		num_pieces;
	t_piece		piece[MAX_PIECES];
}				t_game;

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

# define PIECE(n)	(tetromino.piece[n])

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

# define INVALID_INPUT 	"error"
# define USAGE			"usage: ./fillit file"
# define ERROR			"error"

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

t_uint8			read_pieces(ssize_t fd, t_piece (*piece)[MAX_PIECES],
					t_uint8 npieces);

t_uint64		get_piece_mask(t_uint64 piece_mask, t_char buf[PIECE_SIZE]);
t_uint8			get_piece_width(t_char buf[PIECE_SIZE]);
t_uint8			get_piece_height(t_char buf[PIECE_SIZE]);

t_game			fill_board(t_game tetromino);
void			place_next_pieces(t_game tetromino);

void			print_board(t_game tetromino);

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

#endif
