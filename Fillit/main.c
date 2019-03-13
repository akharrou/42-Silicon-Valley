/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 09:43:08 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/12 18:55:52 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_board(t_game tetromino)
{
	t_uint8 row;
	t_uint8 col;

	row = -1;
	while (++row < tetromino.last_row)
	{
		col = -1;
		while (++col < tetromino.last_col)
			ft_putchar(tetromino.board[row][col]);
	}
}

void	fill_board(t_char (*board)[MAX_BOARD_ROW][MAX_BOARD_COL],
			t_piece pieces[MAX_NUM_PIECES])
{
	return ;
}

int		main(int ac, char *av[])
{
	t_game	tetromino;
	ssize_t	fd;

	if (ac != 2)
		EXIT(USAGE);
	fd = open(av[1], O_RDONLY);
	if (fd < 3)
		EXIT(ERROR);
	read_pieces(fd, &tetromino.pieces);
	fill_board(&tetromino.board, tetromino.pieces);
	print_board(tetromino);
	exit(EXIT_SUCCESS);
}



// int				main(int ac, char *av[])
// {
// 	t_game	tetromino;
// 	ssize_t	fd;

// 	if (ac == 2)
// 	{
// 		fd = open(av[1], O_RDONLY);
// 		if (fd > 2)
// 		{
// 			read_pieces(fd, &tetromino.pieces);
// 			fill_board(&tetromino.board, tetromino.pieces);
// 			print_board(tetromino);
// 		}
// 		EXIT(ERROR);
// 	}
// 	EXIT(USAGE);
// }
