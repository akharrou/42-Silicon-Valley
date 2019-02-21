
#include "../ft_memcmp.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		main(int ac, char *av[])
{
	if (ac != 4)
	{
		printf("Usage: ./program s1 s2 n\n");
		return (1);
	}

	printf("%i\n",
		memcmp(((const void *)av[1]), ((const void *)av[2]), atoi(av[3])));

	printf("%i\n",
		ft_memcmp(((const void *)av[1]), ((const void *)av[2]), atoi(av[3])));

	return (0);
}
