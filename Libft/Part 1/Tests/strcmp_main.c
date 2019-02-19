
#include "../ft_strcmp.c"

#include <stdio.h>
#include <string.h>

int		main(int ac, char *av[])
{
	if (ac != 3)
	{
		printf("Usage: ./program s1 s2\n");
		return (1);
	}

	printf("%i\n", strcmp((const char *)av[1], (const char *)av[2]));
	printf("%i\n", ft_strcmp((const char *)av[1], (const char *)av[2]));

	return (0);
}
