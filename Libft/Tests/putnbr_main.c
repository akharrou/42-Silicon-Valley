/*
 *
 *  TEST MAIN
 *
 */

#include "../ft_putchar.c"
#include "../ft_putstr.c"
#include "../ft_putnbr.c"

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

	ft_putnbr(atoi(av[1]));

	return (0);
}
