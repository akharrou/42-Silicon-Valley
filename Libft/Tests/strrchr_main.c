
#include "../ft_strrchr.c"

#include <stdio.h>
#include <string.h>

int		main(int ac, char *av[])
{
	if (ac != 3)
	{
		printf("Usage: ./program string char\n");
		return (1);
	}

	printf("%s\n", strrchr((const char *)av[1], (int)av[2][0]));
	printf("%s\n", ft_strrchr((const char *)av[1], (int)av[2][0]));

	return (0);
}
