/*
 *
 *  TEST MAIN
 *
 */

#include "../ft_strncmp.c"
#include "../ft_strnequ.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		main(int ac, char *av[])
{
	// if (ac != 4)
	// {
	// 	printf("Usage: ./program str1 str2 n\n");
	// 	return (1);
	// }

	// printf("%i\n", ft_strnequ(av[1], av[2], atoi(av[3])));

	(void)ac;
	(void)av;
	printf("%i\n", ft_strnequ("ededeqdf", "", 0));

	return (0);
}
