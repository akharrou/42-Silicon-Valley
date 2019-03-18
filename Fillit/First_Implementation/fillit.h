/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 09:33:11 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/18 08:34:45 by akharrou         ###   ########.fr       */
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

# include "Libft/Includes/libft.h"

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

# define MAX_BOARD_SIZE     21
# define MAX_PIECES         26
# define BLOCKS_PER_PIECE   4
# define PIECE_ROWS         4
# define PIECE_COLS         4
# define PIECE_SIZE         20

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

typedef struct	s_tetromino_piece
{
	t_bool		used;
	t_char		id;
	t_int8		coordinates[BLOCKS_PER_PIECE][2];
	t_uint8		vertical_length;
	t_uint8		horizontal_length;
}				t_piece;

typedef struct	s_tetromino_board
{
	t_char		matrix[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
	t_int8		rootsize;
}				t_board;

typedef struct	s_game
{
	t_piece		piece[MAX_PIECES];
	t_uint8		num_pieces;
	t_board		board;
}				t_game;

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
** input.c (only)
*/

# define SET_OFFSETS(row, col) { offset[0] = row; offset[1] = col; }
# define CUR_ROW(i) (i / (PIECE_ROWS + 1))
# define CUR_COL(i) (i % (PIECE_COLS + 1))
# define TOUCHING_ROW(row, col) ((col == 1 || col == -1) && row == 0)
# define TOUCHING_COLUMN(row, col) ((row == 1 || row == -1) && col == 0)
# define BLOCK_COL(n) ((*cord)[n][1])
# define SWAP_BLOCKS(tmp, b1, b2) { tmp = b2; b2 = b1; b1 = tmp; }
# define SAME_ROW (*cord)[n][0] == (*cord)[n + 1][0]

# define ROW(p, block_n) (p.coordinates[block_n][0])
# define MIN_ROW(p) (MIN(MIN(MIN(ROW(p, 0), ROW(p, 1)), ROW(p, 2)), ROW(p, 3)))
# define MAX_ROW(p) (MAX(MAX(MAX(ROW(p, 0), ROW(p, 1)), ROW(p, 2)), ROW(p, 3)))

# define COL(p, block_n) (p.coordinates[block_n][1])
# define MIN_COL(p) (MIN(MIN(MIN(COL(p, 0), COL(p, 1)), COL(p, 2)), COL(p, 3)))
# define MAX_COL(p) (MAX(MAX(MAX(COL(p, 0), COL(p, 1)), COL(p, 2)), COL(p, 3)))

# define GET_VERTICAL_LENGTH(piece) (MAX_ROW(piece) - MIN_ROW(piece) + 1)
# define GET_HORIZONTAL_LENGTH(piece) (MAX_COL(piece) - MIN_COL(piece) + 1)

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
** solver.c & utils.c (only)
*/

# define BOARD_SIZE (tetromino.board.rootsize)
# define BOARD_ROWS BOARD_SIZE
# define BOARD_COLS BOARD_SIZE
# define CUR_BOARD_ROW (j / BOARD_ROWS)
# define CUR_BOARD_COL (j % BOARD_COLS)
# define CBR CUR_BOARD_ROW
# define CBC CUR_BOARD_COL
# define EMPTY ('.')
# define PIECE(n) (tetromino.piece[n])
# define PIECE_AREA(n) (PIECE(n).horizontal_length * PIECE(n).vertical_length)
# define SWAP_PIECES(tmp, p1, p2) { tmp = p2; p2 = p1; p1 = tmp; }
# define BOARD (tetromino.board)
# define CUR_CELL (tetromino.board.matrix[CUR_BOARD_ROW][CUR_BOARD_COL])
# define EMPTY_SPACE check(PIECE(i), BOARD, CUR_BOARD_ROW, CUR_BOARD_COL)
# define PIECE_PLACEMENT_POSSIBLE (CUR_CELL == EMPTY && EMPTY_SPACE)

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

# define USAGE "usage: ./fillit file"
# define INVALID_INPUT "error"
# define ERROR "error"

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

t_game			read_pieces(ssize_t fd);

t_game			initialize_game(t_game tetromino);
void			fill_board(t_game tetromino);

t_game			place_piece(t_game tetromino, t_uint8 piece_index,
					t_uint8 row, t_uint8 col);
void			place_next_pieces(t_game tetromino);

void			print_board(t_board board);

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

#endif
