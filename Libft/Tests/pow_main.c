/*
 *
 *  TEST MAIN
 *
 */

#include "../ft_pow.c"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int		main(int ac, char *av[])
{
	if (ac != 3)
	{
		printf("Usage: ./program n power\n");
		return (1);
	}

	printf("System	: %f\n", pow(atoi(av[1]), atoi(av[2])));
	printf("Mine	: %Lf\n", ft_pow(atoi(av[1]), atoi(av[2])));

	return (0);
}
