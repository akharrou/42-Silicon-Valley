/*
 *
 *  TEST MAIN
 *
 */

#include "../ft_memset.c"
#include "../ft_memalloc.c"
#include "../ft_strnew.c"

#include "../ft_strdup_range.c"
#include "../ft_strsplit.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		main(int ac, char *av[])
{
	if (ac != 3)
	{
		printf("Usage: ./program string seperator\n");
		return (1);
	}

	char **strtab = ft_strsplit(av[1], av[2][0]);

	for (; *strtab; strtab++)
		printf("%s\n", *strtab);
	printf("%s\n", *strtab);

	return (0);
}
