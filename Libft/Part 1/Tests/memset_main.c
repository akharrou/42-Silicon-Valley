

#include "../ft_memset.c"

#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char *av[])
{
	if (ac != 4)
	{
		printf("Usage: ./program string char len\n");
		return (1);
	}

	printf("%s\n", memset((void *)av[1], (int)av[2][0], (size_t) atoi(av[3]))); // system

	// printf("%s\n", ft_memset((void *)av[1], (int)av[2][0], (size_t) atoi(av[3]))); // my

	return (0);
}

/* Mine will stop when it reaches the end of the string. The system's will keep
going and writing in the subsequent bytes in memory. */
