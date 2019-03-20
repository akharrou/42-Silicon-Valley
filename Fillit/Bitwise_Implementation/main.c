/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 09:43:08 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/19 20:17:18 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int ac, char *av[])
{
	t_game	tetromino;
	ssize_t	fd;

	if (ac != 2)
		EXIT(USAGE);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		EXIT(ERROR);
	tetromino = read_pieces(fd);
	fill_board(tetromino);
	return (0);
}

/*
**	printf("%i\n", tetromino.num_pieces);
**  for (int i = 0; tetromino.num_pieces > i; i++)
**  {
**  	printf("—————————————————————————————————————\n");
**  	printf("[PIECE #%i] :\n\n", i);
**  	printf("ID:	%c\n", PIECE(i).id);
**  	printf("WIDTH:	%i\n", PIECE(i).width);
**  	printf("HEIGHT:	%i\n", PIECE(i).height);
**  	printf("\nMASK:\n");
**  	ft_putbits(PIECE(i).mask, 16);
**  	ft_putbits(PIECE(i).mask, 32);
**  	ft_putbits(PIECE(i).mask, 48);
**  	ft_putbits(PIECE(i).mask, 64);
**  }
**  printf("—————————————————————————————————————\n");
*/

void	print_bit_board(uint16_t *matrix, int size)
{
	int i;

	ft_putstr("\n  ————   ————   ————   ————   ————   ————   ————   ————\n");
	i = 0;
	while (i < size)
	{
		ft_putstr("| ");
		ft_putbits((uint16_t) matrix[i], size);
		i++;
	}
	ft_putstr("  ————   ————   ————   ————   ————   ————   ————   ————\n\n");
}


/*
** TODAY:
**
** 	- fix main backtracking function
** 	- print the board
**
** 	- have fun with debugging
*/
