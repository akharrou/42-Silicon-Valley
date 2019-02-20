/*
 *
 *  TEST MAIN
 *
 */

#include "../ft_islower.c"
#include "../ft_strlen.c"
#include "../ft_strmap.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	ft_toupper_(char c)
{
	if (ft_islower(c))
		return (c - 32);
	return (c);
}

int		main(int ac, char *av[])
{
	if (ac != 2)
	{
		printf("Usage: ./program \n");
		return (1);
	}

	printf("%s\n", ft_strmap(av[1], &ft_toupper_));

	return (0);
}
