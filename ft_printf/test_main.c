/**
 *
 * TEST MAIN
 *
 */

#include "ft_printf.c"
#include "ft_printf.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

int		main(int ac, char *av[])
{
	// if (ac != )
	// {
	// 	printf("Usage: ./a \n");
	// 	return (1);
	// }

	printf("Real:	");		printf("this is a string");			printf("\n");
	printf("Mine:	");		ft_printf("this is a string");		printf("\n");

	return (0);
}
