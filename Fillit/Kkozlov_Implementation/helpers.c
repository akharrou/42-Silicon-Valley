/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:12:08 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/27 14:02:45 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetromino	*gen_tet(void)
{
	static char	ntet;
	t_tetromino	*tet;

	tet = malloc(sizeof(t_tetromino));
	FT_ASSERT(tet != NULL);
	tet->block = 'A' + ntet;
	tet->pattern = 0;
	++ntet;
	return (tet);
}

t_list		*gen_tets(char *filepath)
{
	t_list	*fnode;
	t_list	**pfnode;
	
	fnode = 0;
	pfnode = &fnode;
	check_input(filepath, &pfnode);
	return (fnode); 
}

t_square	*gen_square(size_t size)
{
	t_square *square;

	square = malloc(sizeof(t_square));
	FT_ASSERT(square != NULL);
	square->size = size;
	square->pattern = 0;
	return (square);
}

void		free_content(void *content, size_t content_size)
{
	if (content_size)
		free(content);
}

void		print_content(void *content)
{
	size_t		pos;
	t_tetromino *tet;

	pos = 0;
	tet = (t_tetromino *)content;
	while (pos <  sizeof(tet->pattern) * 8)
	{
		ft_putchar(ft_test_bit(&tet->pattern,
			 sizeof(tet->pattern), pos) ? tet->block : EMPTY);
		++pos;
		if (pos % TETSIZE == 0)
			ft_putchar('\n');
	}
}

