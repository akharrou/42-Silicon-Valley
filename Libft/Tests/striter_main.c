/*
 *
 *  TEST MAIN
 *
 */

#include "../ft_striter.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	ft_putchar_(char *c)
{
	write(1, c, 1);
}

int		main(int ac, char *av[])
{
	if (ac != 2)
	{
		printf("Usage: ./program string\n");
		return (1);
	}

	ft_striter(av[1], &ft_putchar_);

	return (0);
}
