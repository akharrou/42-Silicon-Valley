/*
 *
 *  TEST MAIN
 *
 */

#include "../ft_striteri.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	ft_putchar__(unsigned int i, char *c)
{
	printf("#%i —> %c\n", i, *c);
}

int		main(int ac, char *av[])
{
	if (ac != 2)
	{
		printf("Usage: ./program string\n");
		return (1);
	}

	ft_striteri(av[1], &ft_putchar__);

	return (0);
}
