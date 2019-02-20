/*
 *
 *  TEST MAIN
 *
 */

#include "../ft_putchar.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		main(int ac, char *av[])
{
	if (ac != 2)
	{
		printf("Usage: ./program character\n");
		return (1);
	}

	ft_putchar(av[1][0]);

	return (0);
}
