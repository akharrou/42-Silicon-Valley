
#include "../ft_strcpy.c"

#include <stdio.h>
#include <string.h>

int		main(int ac, char *av[])
{
	if (ac != 3)
	{
		printf("Usage: ./program dst src\n");
		return (1);
	}

	printf("%s\n", strcpy((char *)av[1], (const char *)av[2]));
	printf("%s\n", ft_strcpy((char *)av[1], (const char *)av[2]));

	return (0);
}
