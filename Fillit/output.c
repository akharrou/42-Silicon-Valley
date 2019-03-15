/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:51:27 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/14 17:46:43 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         print_board -- prints a tetromino board.
**
**    SYNOPSIS
**         #include "fillit.h"
**
**         void
**         print_board(t_game tetromino);
**
**    PARAMETERS
**
**         t_game         A tetromino game (a type t_game) that has its board
**                        filled.
**
**    DESCRIPTION
**         Iterates through board printing each of its character.
**
**    RETURN VALUES
**         None.
*/

#include "fillit.h"

void	print_board(t_game tetromino)
{
	t_uint8 row;

	row = -1;
	while (tetromino.rootsize > ++row)
		ft_putendl((const char *)tetromino.board[row]);
}
