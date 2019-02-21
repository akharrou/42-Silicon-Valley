
#include "../ft_strncmp.c"
#include "../ft_strlen.c"
#include "../ft_strnstr.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		main(int ac, char *av[])
{
	if (ac != 4)
	{
		printf("Usage: ./program haystack needle len\n");
		return (1);
	}

	printf("%s\n",
		strnstr((const char *)av[1], (const char *)av[2], atoi(av[3])));

	printf("%s\n",
		ft_strnstr((const char *)av[1], (const char *)av[2], atoi(av[3])));

	return (0);
}
