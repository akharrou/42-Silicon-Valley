
#include "../ft_strncpy.c"

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

	printf("%s\n",
		strncpy((char *)av[1], (const char *)av[2], atoi(av[3])));

	printf("%s\n",
		ft_strncpy((char *)av[1], (const char *)av[2], atoi(av[3])));

	return (0);
}
