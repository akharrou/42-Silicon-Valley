
#include "../ft_memcpy.c"
#include "../ft_memmove.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		main(int ac, char *av[])
{
	if (ac != 4)
	{
		printf("Usage: ./program dst src len\n");
		return (1);
	}

	printf("System:\n———————————————\n%s\n%s\n",
			memmove((void *)(av[1]), (void *)(av[2]), atoi(av[3])),
			av[1]);
	// printf("Mine:\n———————————————\n%s\n%s\n",
	// 		ft_memmove((void *)(av[1]), (void *)(av[2]), atoi(av[3])),
	// 		av[1]);

	return (0);
}
