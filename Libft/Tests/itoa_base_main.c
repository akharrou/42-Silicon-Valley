/*
 *
 * TEST MAIN
 *
 */

#include "../ft_strlen.c"
#include "../ft_itoa_base.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int		main(int ac, char *av[])
{
	if (ac != 3)
	{
		printf("Usage: ./a nbr base\n");
		return (1);
	}

	printf("%s\n", ft_itoa_base(atol(av[1]), av[2]));

	return (0);
}
