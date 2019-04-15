/**
 *
 * TEST MAIN
 *
 */

#include "ft_printf.h"

#include "utils.c"
#include "ft_printf.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

int		main(int ac, char *av[])
{
	if (ac < 2)
	{
		printf("Usage: ./a format ...\n");
		return (1);
	}

	ft_putnbr(ft_printf("%s\n"));
	ft_putnbr(ft_printf("%rmncds%yhsd%mq%%wd\n"));

	(void)ac;
	(void)av;
	return (0);
}
