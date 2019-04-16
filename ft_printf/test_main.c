/**
 *
 * TEST MAIN
 *
 */

#include "ft_printf.h"

#include "Libft/Ctype/ft_ischarset.c"

#include "utils.c"
#include "parsers.c"
#include "write.c"
#include "ft_printf.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

int		main(int ac, char *av[])
{
	// if (ac < 2)
	// {
	// 	printf("Usage: ./a format ...\n");
	// 	return (1);
	// }

	// ft_putnbr(ft_printf("%s\n"));
	// ft_putnbr(ft_printf("%rmncds%dyhsd%mq%%wd\n", 4));

	// printf("%.0f\n", 283.0);
	// printf("%.1i\n", 2);

	// ft_printf("Hello world! This is Johnathan !\n");

	ft_printf("Hello world! This is %Johnathan !\n");

	(void)ac;
	(void)av;
	return (0);
}
