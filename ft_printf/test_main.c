/**
 *
 * TEST MAIN
 *
 */

// #include "ft_printf.h"

// #include "parsers.c"
// #include "format_string.c"
// #include "ft_printf.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <float.h>
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

	// ft_printf("Hello world! This is %Johnathan !\n");

	// ft_printf("%-#20.5hhs"); // [√]
	// ft_printf("%+042Lp"); // [√]
	// ft_printf("% -85lX"); // [√]
	// ft_printf("%+#0000#20.5hu"); // [√]
	// ft_printf("%-#20.5hh"); // [√]
	// ft_printf("%s"); // [√]
	// ft_printf("%%"); // [√]
	// ft_printf("% %"); // [√]
	// ft_printf("%%%%%%%"); // [√]

	// ft_printf(""); 						write(1, "\n", 1);
	// ft_printf("This is a string");      write(1, "\n", 1);
	// ft_printf("This is %a string");     write(1, "\n", 1);
	// ft_printf("%This is a string");     write(1, "\n", 1);

	// printf("%lli", (long long)10);

	// ft_printf("%i", (int)10);     write(1, "\n", 1);

	// ft_printf("%i", (int)11);
	// ft_printf("%i", (int)12);
	// ft_printf("%i", (int)13);

	// printf("%+10.5f", 13.456);
	// printf("%-+20.5d", 13);
	// printf("|%-+20.5f|\n", 13.23);
	// printf("|% +20.5f|", 13.23);

	// printf("%f\n", -340282346638528859811704183484516925441.000000);
	// printf("%f\n", 4294967296.1);
	// printf("%f\n", FLT_MIN);
	// printf("%f\n", FLT_MAX);
	// printf("%f\n", FLT_EPSILON);

	// printf("%f\n", FLT_MAX);
	// printf("%Lf\n", LDBL_MAX);
	printf("%.30Lf\n", (long double)-18131231244674417236523842376892354236872735.0);

	(void)ac;
	(void)av;

	return (0);
}



// /** PRECISION
//  *




// */



// /* FLAGS */



// /* WIDTH */



// SPACE & + : conflict







// if (format.specifier == 'f')
// {

// }
// else
// {

// }



