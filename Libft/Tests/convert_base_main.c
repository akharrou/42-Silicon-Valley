/*
 *
 * TEST MAIN
 *
 */

#include "../ft_strlen.c"
#include "../ft_convert_base.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int		main(int ac, char *av[])
{
	if (ac != 4)
	{
		printf("Usage: ./a number base_from base_to\n");
		return (1);
	}

	printf("%s\n", ft_convert_base(av[1], av[2], av[3]));

	return (0);
}
