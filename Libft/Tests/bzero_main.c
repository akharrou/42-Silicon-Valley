
#include "memset.c"

/* ===> insert 'bzero' here <=== */

#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char *av[])
{
	if (ac != 3)
	{
		printf("Usage: ./program string len\n");
		return (1);
	}

	ft_bzero((void *)av[1], (size_t)atoi(av[2]));

	printf("%s\n", av[1]);
	return (0);
}
