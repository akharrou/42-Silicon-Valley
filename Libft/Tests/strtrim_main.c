/*
 *
 *  TEST MAIN
 *
 */

#include "../ft_strtrim.c"
#include "../ft_isspace.c"
#include "../ft_strlen.c"
#include "../ft_strdup_range.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		main(int ac, char *av[])
{
	if (ac != 2)
	{
		printf("Usage: ./program string\n");
		return (1);
	}

	printf("%s\n", ft_strtrim(av[1]));

	return (0);
}
