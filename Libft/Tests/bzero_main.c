
#include "../ft_memset.c"
#include "../ft_bzero.c"

#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char *av[])
{
	if (ac != 3)
	{
		printf("Usage: ./program string len\n");
		return (1);
	}

	// bzero((void *)av[1], (size_t)atoi(av[2]));		// System
	ft_bzero((void *)av[1], (size_t)atoi(av[2]));		// My

	printf("%s\n", av[1]);
	return (0);
}
