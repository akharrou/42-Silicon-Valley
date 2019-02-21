/*
 *
 *  TEST MAIN
 *
 */

#include "../ft_putchar_fd.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		main(int ac, char *av[])
{
	if (ac != 3)
	{
		printf("Usage: ./program char filedes\n");
		return (1);
	}

	ft_putchar_fd(av[1][0], atoi(av[2]));

	return (0);
}
