/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:27:03 by kkozlov           #+#    #+#             */
/*   Updated: 2019/03/04 16:06:30 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	print_usage()
{
	ft_putendl("usage: ");
}

int	main(int argc, char **argv)
{
	t_list	*fnode;
	t_list	*itr;

	if (argc == 2)
	{
		fnode = gen_tets(argv[1]);
		FT_ASSERT(fnode != NULL);
		itr = fnode;
		while (itr)
		{
			if (itr->content_size)
			{
				print_content(itr->content);
//				align_tet((t_tetromino *)itr->content);
//				ft_putchar('\n');
//				print_content(itr->content);
				find_inpoint((t_tetromino *)itr->content);
			}
			ft_putchar('\n');
			itr = itr->next;
		}
		ft_lstdel(&fnode, &free_content);
	}
	else
		print_usage();
	return (0);
}

