
#include "../ft_memcpy.c"

#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char *av[])
{
	if (ac != 4)
	{
		printf("Usage: ./program dst src n\n");
		return (1);
	}

	// printf("—————————————————\nSystem Lib:\n");
	// printf("Original Dst: %s\nNew Dst: %s\n", memcpy((void*)(av[1]), (void*)av[2], atoi(av[3])), av[1]);

	printf("\n—————————————————\nMy Lib:\n");
	printf("Original Dst: %s\nNew Dst: %s\n", ft_memcpy((void*)(av[1]), (void*)av[2], atoi(av[3])), av[1]);

	return (0);
}
