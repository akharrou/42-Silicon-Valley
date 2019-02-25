/*
 *
 * TEST MAIN
 *
 */

#include "../ft_strchrs.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int		main(int ac, char *av[])
{
	if (ac != 3)
	{
		printf("Usage: ./a str substr\n");
		return (1);
	}

	printf("%i\n", ft_strchrs(av[1], av[2]));

	return (0);
}