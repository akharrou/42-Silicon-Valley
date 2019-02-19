/*
 *
 * TEST MAIN
 *
 */

#include "../ft_itoa.c"
#include "../Part 1/ft_strcpy.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		main(int ac, char *av[])
{
	if (ac != 2)
	{
		printf("Usage: ./program number\n");
		return (1);
	}

	printf("%s\n", ft_itoa(atoi(av[1])));

	return (0);
}
