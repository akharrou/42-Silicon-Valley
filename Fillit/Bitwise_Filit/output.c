/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 00:11:13 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/23 18:30:53 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define COL_OFFSET(n)  (piece.col_placement + piece.coord[n][1])
#define ROW_OFFSET(n)  ((piece.row_placement + piece.coord[n][0]) * (size + 1))

static void		write_piece(t_piece piece, t_char (*board_str)[MAX_TT_CHARS],
					t_uint8 size)
{
	t_uint8		crd_correction;
	t_uint8		i;

	i = 1;
	while (BLOCKS_PER_PIECE > i && piece.coord[i][1] >= 0)
		++i;
	crd_correction = 0;
	if (piece.coord[i][1] < 0)
		crd_correction = ABS(piece.coord[i][1]);
	(*board_str)[ROW_OFFSET(0) + COL_OFFSET(0) + crd_correction] = piece.letter;
	(*board_str)[ROW_OFFSET(1) + COL_OFFSET(1) + crd_correction] = piece.letter;
	(*board_str)[ROW_OFFSET(2) + COL_OFFSET(2) + crd_correction] = piece.letter;
	(*board_str)[ROW_OFFSET(3) + COL_OFFSET(3) + crd_correction] = piece.letter;
}

void			print_board(t_game tetromino)
{
	t_char		board_str[MAX_TT_CHARS];
	t_uint8		i;

	ft_memset(board_str, '.', BOARD_HEIGHT * BOARD_LENGTH);
	i = -1;
	while (tetromino.board.size > ++i)
		board_str[(i * BOARD_LENGTH) + tetromino.board.size] = '\n';
	i = -1;
	while (tetromino.num_pieces > ++i)
		write_piece(tetromino.piece[i], &board_str, tetromino.board.size);
	write(1, board_str, BOARD_HEIGHT * BOARD_LENGTH);
}
