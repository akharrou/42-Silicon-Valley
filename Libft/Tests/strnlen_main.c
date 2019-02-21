
#include "../ft_strnlen.c"

#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char *av[])
{
	if (ac != 3)
	{
		printf("Usage: ./program str maxlen\n");
		return (1);
	}

	printf("%i\n", (int)strnlen((const char *)av[1], atoi(av[2])));
	printf("%i\n", (int)ft_strnlen((const char *)av[1], atoi(av[2])));

	return (0);
}
