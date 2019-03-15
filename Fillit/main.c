/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 09:43:08 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/14 19:13:20 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char *av[])
{
	t_game		tetromino;
	ssize_t		fd;

	if (ac != 2)
		EXIT(USAGE);
	fd = open(av[1], O_RDONLY);
	if (fd < 3)
		EXIT(ERROR);
	tetromino = read_pieces(fd);
	tetromino = fill_board(tetromino);
	print_board(tetromino);
	exit(EXIT_SUCCESS);
}

// #include <stdio.h>

	// for (int i = 0; i <= tetromino.num_pieces; i++)
	// {
	// 	printf("—————————————————————————\nPiece #%c:\n\n",
	// 		tetromino.piece[i].id);
	// 	printf("Block #1:	%i, %i\n",
	// 		tetromino.piece[i].coordinates[0][0],
	// 		tetromino.piece[i].coordinates[0][1]);
	// 	printf("Block #2:	%i, %i\n",
	// 		tetromino.piece[i].coordinates[1][0],
	// 		tetromino.piece[i].coordinates[1][1]);
	// 	printf("Block #3:	%i, %i\n",
	// 		tetromino.piece[i].coordinates[2][0],
	// 		tetromino.piece[i].coordinates[2][1]);
	// 	printf("Block #4:	%i, %i\n",
	// 		tetromino.piece[i].coordinates[3][0],
	// 		tetromino.piece[i].coordinates[3][1]);
	// }
	// printf("—————————————————————————\n");
