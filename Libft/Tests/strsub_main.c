/*
 *
 *  TEST MAIN
 *
 */

#include "../ft_strsub.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		main(int ac, char *av[])
{
	if (ac != 4)
	{
		printf("Usage: ./program string start len\n");
		return (1);
	}

	printf("%s\n", ft_strsub(av[1], atoi(av[2]), atoi(av[3])));

	return (0);
}
