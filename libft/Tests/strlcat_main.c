
#include "../ft_strlen.c"
#include "../ft_strlcat.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		main(int ac, char *av[])
{
	if (ac != 4)
	{
		printf("Usage: ./program dst src dstsize\n");
		return (1);
	}

	// printf("%lu\n%s\n",
	// 	strlcat((char *)av[1], (const char *)av[2], atoi(av[3])), av[1]);

	printf("%lu\n%s\n",
		ft_strlcat((char *)av[1], (const char *)av[2], atoi(av[3])), av[1]);

	return (0);
}
