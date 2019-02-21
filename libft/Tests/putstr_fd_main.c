/*
 *
 *  TEST MAIN
 *
 */

#include "../ft_putstr_fd.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		main(int ac, char *av[])
{
	if (ac != 3)
	{
		printf("Usage: ./program string filedes\n");
		return (1);
	}

	ft_putstr_fd(av[1], atoi(av[2]));

	return (0);
}
