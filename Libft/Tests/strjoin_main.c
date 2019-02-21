/*
 *
 *  TEST MAIN
 *
 */

#include "../ft_strlen.c"
#include "../ft_memset.c"
#include "../ft_strcat.c"
#include "../ft_strnew.c"
#include "../ft_strjoin.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		main(int ac, char *av[])
{
	if (ac != 3)
	{
		printf("Usage: ./program s1 s2\n");
		return (1);
	}

	printf("%s\n", ft_strjoin(av[1], av[2]));

	return (0);
}
