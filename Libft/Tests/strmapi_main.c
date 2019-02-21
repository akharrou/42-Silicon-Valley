/*
 *
 *  TEST MAIN
 *
 */

#include "../ft_islower.c"
#include "../ft_strlen.c"
#include "../ft_strmapi.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	ft_toupper__(unsigned int i, char c)
{
	if (ft_islower(c))
		return (c - 32 + i);
	return (c);
}

int		main(int ac, char *av[])
{
	if (ac != 2)
	{
		printf("Usage: ./program \n");
		return (1);
	}

	printf("%s\n", ft_strmapi(av[1], &ft_toupper__));

	return (0);
}
