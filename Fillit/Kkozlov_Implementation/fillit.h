/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:07:42 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/27 17:39:31 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>

# include "libft.h"
# include "get_next_line.h"

# define MAXTETS	27
# define TETSIZE	4
# define BLOCK		'#'
# define EMPTY		'.'

#define TESTBIT(pv, size, pos) ft_test_bit(pv, size, pos)

#define CHECK_UP(p, r, c) ft_test_bit(&p, sizeof(p), (r - 2) * BYTE / 2 + c)

#define CHECK_LEFT(p, r, c)	ft_test_bit(&p, sizeof(p), (r - 1) * BYTE / 2 + c - 1)

typedef struct	s_tetromino
{
	short		pattern;
	char		block;
}				t_tetromino;

typedef struct	s_square
{
	size_t		pattern;
	size_t		size;
}				t_square;

void		check_input(char *filepath, t_list ***ppfnode);

t_tetromino	*gen_tet(void);
t_list		*gen_tets(char *filepath);

void		print_content(void *content);
void		free_content(void *content, size_t content_size);

t_square	*gen_square(size_t size);

void		align_tet(t_tetromino *tet);
void		find_inpoint(t_tetromino *tet);
int			fillit();

#endif
