

/* ===> insert 'memset' here <=== */

#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char *av[])
{
	if (ac != 4)
	{
		printf("Usage: ./program string char len\n");
		return (1);
	}

	printf("%s\n", ft_memset((void *)av[1], (int)av[2][0], (size_t) atoi(av[3])));
	return (0);
}
