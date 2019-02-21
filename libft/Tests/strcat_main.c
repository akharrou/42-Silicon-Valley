
#include "../ft_strcat.c"

#include <stdio.h>
#include <string.h>

int		main(int ac, char *av[])
{
	if (ac != 3)
	{
		printf("Usage: ./program s1 s2\n");
		return (1);
	}

	// printf("%s\n", strcat((char *restrict)av[1], (const char *restrict)av[2]));
	printf("%s\n", ft_strcat((char *)av[1], (const char *)av[2]));

	return (0);
}
