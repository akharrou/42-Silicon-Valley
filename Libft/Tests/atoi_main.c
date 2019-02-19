
#include "../ft_atoi.c"

#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char *av[])
{
	if (ac != 2)
	{
		printf("Usage: ./program str\n");
		return (1);
	}

	printf("%i\n", atoi((const char *)av[1]));
	printf("%i\n", ft_atoi((const char *)av[1]));

	return (0);
}
