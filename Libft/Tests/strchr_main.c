
#include "../ft_strchr.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		main(int ac, char *av[])
{
	if (ac != 3)
	{
		printf("Usage: ./program string char\n");
		return (1);
	}

	printf("%s\n", strchr((const char *)av[1], (int)av[2][0]));
	printf("%s\n", ft_strchr((const char *)av[1], (int)av[2][0]));

	return (0);
}
