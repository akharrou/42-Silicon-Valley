
#include "../ft_memchr.c"

#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char *av[])
{
	if (ac != 4)
	{
		printf("Usage: ./program string char n\n");
		return (1);
	}

	// printf("%s\n", memchr((const void*)av[1], av[2][0], atoi(av[3])));
	printf("%s\n", ft_memchr((const void*)av[1], av[2][0], atoi(av[3])));

	return (0);
}
