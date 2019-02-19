
#include "../ft_strdup.c"

#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char *av[])
{
	if (ac != 2)
	{
		printf("Usage: ./program str\n");
		return (1);
	}

	printf("%s\n", strdup((const char *)av[1]));
	printf("%s\n", ft_strdup((const char *)av[1]));

	return (0);
}
