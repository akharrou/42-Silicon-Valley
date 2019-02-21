/*
 *
 *  TEST MAIN
 *
 */

#include "../ft_intlen.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		main(int ac, char *av[])
{
	if (ac != 2)
	{
		printf("Usage: ./program integer\n");
		return (1);
	}

	printf("%i\n", ft_intlen(atoi(av[1])));

	// (void)av;
	// printf("%i\n", ft_intlen(-2147484523823623223));
	/* max length of an integer literal is 20 */

	return (0);
}
