
#include "../ft_strstr.c"

#include <stdio.h>
#include <string.h>

int		main(int ac, char *av[])
{
	if (ac != 3)
	{
		printf("Usage: ./program haystack needle\n");
		return (1);
	}

	printf("%s\n", strstr((const char *)av[1], (const char *)av[2]));
	printf("%s\n", ft_strstr((const char *)av[1], (const char *)av[2]));

	return (0);
}
