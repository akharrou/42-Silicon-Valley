
#include "../ft_memccpy.c"

#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char *av[])
{
	if (ac != 5)
	{
		printf("Usage: ./program dst src c n\n");
		return (1);
	}

	printf("System Lib:\n—————————————————————\n%s\n", memccpy((void *)av[1], (void*)av[2], (int)av[3], atoi(av[4])));			// System

	// printf("\nMy Function:\n—————————————————————\n%s\n", ft_memccpy((void *)av[1], (void*)av[2], (int)av[3], atoi(av[4])));		// My

	return (0);
}
