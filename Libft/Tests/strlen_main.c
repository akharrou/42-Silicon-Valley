
#include "../ft_strlen.c"

#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char *av[])
{
	if (ac != 2)
	{
		printf("Usage: ./program str\n");
		return (1);
	}

	printf("%i\n", (int)strlen((const char *)av[1]));
	printf("%i\n", (int)ft_strlen((const char *)av[1]));

	return (0);
}
