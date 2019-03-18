/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:24:57 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/27 15:59:05 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_pattern(short pattern, size_t nline,
					size_t pos, size_t nblocks)
{
	static char check_two;

	if ((nline > 1 && CHECK_UP(pattern, nline, pos)) ||
		(pos && CHECK_LEFT(pattern, nline, pos)))
	{
		check_two = 0;
		return (1);
	}
	if (nblocks == TETSIZE - 2 || (!check_two && nblocks == TETSIZE - 1))
	{
		check_two = 1;
		return (1);
	}
	if ((check_two && nblocks == TETSIZE - 1) ||
		(check_two && nblocks == TETSIZE))
	{
		if (CHECK_UP(pattern, nline, pos) && CHECK_LEFT(pattern, nline, pos))
		{
			check_two = 0;
			return (1);
		}
	}
	return (0);
}

static void		check_char(char ch, short pattern, size_t nline, size_t pos)
{
	static size_t	nblocks;

	FT_ASSERT(ch == EMPTY || ch == BLOCK);
	if (ch == BLOCK)
		++nblocks;
	if (nline % TETSIZE == 0 && pos == TETSIZE - 1)
		FT_ASSERT(nblocks == TETSIZE);
	if (nline % TETSIZE == 0 && pos == TETSIZE - 1)
		nblocks = 0;
	if (ch == BLOCK && nblocks > 1)
		FT_ASSERT(check_pattern(pattern, nline, pos, nblocks));
}

static void		check_line(char *line, size_t nline, t_list ***ppfnode)
{
	char			*itr;
	static t_list	*new;

	if (nline == (TETSIZE + 1))
		FT_ASSERT(*line == '\0');
	if (nline == 1)
	{
		new = ft_lstnew(gen_tet(), sizeof(t_tetromino *));
		FT_ASSERT(new != NULL);
		ft_lstadd(*ppfnode, new);
	}
	itr = line;
	while (*itr)
	{
		FT_ASSERT(itr - line < TETSIZE);
		check_char(*itr, ((t_tetromino *)new->content)->pattern,
			nline, itr - line);
		if (*itr == BLOCK)
			ft_set_bit(&((t_tetromino *)new->content)->pattern,
			sizeof(((t_tetromino *)new->content)->pattern),
			(nline - 1) * BYTE / 2 + (itr - line));
		++itr;
	}
	if (*itr)
		FT_ASSERT((itr - line) == TETSIZE);
}

void			check_input(char *filepath, t_list ***ppfnode)
{
	char	*line;
	int		fd;
	size_t	nline;

	nline = 1;
	fd = open(filepath, O_RDONLY);
	FT_ASSERT(fd > 0);
	while (get_next_line(fd, &line) > 0)
	{
		check_line(line, nline, ppfnode);
		if (++nline > TETSIZE + 1)
			nline = 1;
	}
	close(fd);
}
