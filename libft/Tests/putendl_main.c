/*
 *
 *  TEST MAIN
 *
 */

#include "../ft_putendl.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		main(int ac, char *av[])
{
	if (ac != 2)
	{
		printf("Usage: ./program string\n");
		return (1);
	}

	ft_putendl(av[1]);

	return (0);
}
