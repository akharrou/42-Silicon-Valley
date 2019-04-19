/**
 *
 * TEST MAIN
 *
 */

#include "ft_printf.h"

#include "ft_printf.c"
#include "parsers.c"
#include "format_string.c"

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
	// printf("%.30Lf\n", (long double)-18131231244674417236523842376892354236872735.0);

	//
	// /* — — — — – – – – – – – – – – – – – – – – – – – – – –  */ ft_printf("%i, %i, %i, %i, %i", 10, 50, 100, 150, 1000);



/* ========================================================================= */
/* ========================================================================= */
/* ========================================================================= */


/* %s SPECIFIER TESTS */

/**
 * Only takes the following flags & fields:
 *
 * 		– Flag: '-',
 *      - Width
 *      - Precision
 *
 */

	// ft_printf("|%-10.2s|\n", "hello");
	// printf("|%-10.2s|\n\n", "hello");

	// ft_printf("|%12.2s|\n", "hello");
	// printf("|%12.2s|\n\n", "hello");

	// ft_printf("|%-2.1223s|\n", "hello");
	// printf("|%-2.1223s|\n\n", "hello");

	// ft_printf("|%-200.12s|\n", "hello");
	// printf("|%-200.12s|\n\n", "hello");

	// ft_printf("|%*.12s|\n", 10, "hello");
	// printf("|%*.12s|\n\n", 10, "hello");

	// ft_printf("|%*.*s|\n", 40, 5, "hello");
	// printf("|%*.*s|\n\n", 40, 5, "hello");

	// ft_printf("|%*.*s|\n", 25, 2, "hello");
	// printf("|%*.*s|\n\n", 25, 2, "hello");

/* — — — — – – – – – – – – – – – – – – – – – – – – – –  */

// /* %c SPECIFIER TESTS */

// /**
//  * Only takes the following flags & fields:
//  *
//  * 		– Flag: '-'
//  *       - Width
//  *
//  */

	// ft_printf("|%c|\n", 'a');
	// printf("|%c|\n\n", 'a');

	// ft_printf("|%c|	|%c|	|%c|\n", 'a', 'b', 'c');
	// printf("|%c|	|%c|	|%c|\n\n", 'a', 'b', 'c');

	// ft_printf("|%10c|\n", 'z');
	// printf("|%10c|\n\n", 'z');

	// ft_printf("|%-*c|\n", 10, 'y');
	// printf("|%-*c|\n\n", 10, 'y');

	// ft_printf("|%25c|\n", 'x');
	// printf("|%25c|\n\n", 'x');

	// ft_printf("|%c%c%c%c%c!|\n", 'K', 'e', 'v', 'i', 'n');
	// printf("|%c%c%c%c%c!|\n\n", 'K', 'e', 'v', 'i', 'n');

	// ft_printf("|%c%c%c%c%c%c%c%c%c|\n",
	// 	'B', 'e', ' ', 'd', 'e', 'v', 'i', 'n', '\'');
	// printf("|%c%c%c%c%c%c%c%c%c|\n\n",
	// 	'B', 'e', ' ', 'd', 'e', 'v', 'i', 'n', '\'');

/* — — — — – – – – – – – – – – – – – – – – – – – – – –  */

// /* %mod SPECIFIER TESTS */

// /**
//  * Only takes the following flags & fields:
//  *
//  * 		– Flag: '-',
//  *       - Width
//  *
//  */

	ft_printf("||\n", );
	printf("||\n\n", );

	ft_printf("||\n", );
	printf("||\n\n", );

	ft_printf("||\n", );
	printf("||\n\n", );

	ft_printf("||\n", );
	printf("||\n\n", );

	ft_printf("||\n", );
	printf("||\n\n", );

	ft_printf("||\n", );
	printf("||\n\n", );

	ft_printf("||\n", );
	printf("||\n\n", );

/* — — — — – – – – – – – – – – – – – – – – – – – – – –  */

// /* %c SPECIFIER TESTS */

// /**
//  * Only takes the following flags & fields:
//  *
//  * 		– Flag: '-',
//  *       - Width
//  *
//  */

// 	ft_printf("||\n", );
// 	printf("||\n\n", );

// 	ft_printf("||\n", );
// 	printf("||\n\n", );

// 	ft_printf("||\n", );
// 	printf("||\n\n", );

// 	ft_printf("||\n", );
// 	printf("||\n\n", );

// 	ft_printf("||\n", );
// 	printf("||\n\n", );

// 	ft_printf("||\n", );
// 	printf("||\n\n", );

// 	ft_printf("||\n", );
// 	printf("||\n\n", );

/* — — — — – – – – – – – – – – – – – – – – – – – – – –  */

// /* %c SPECIFIER TESTS */

// /**
//  * Only takes the following flags & fields:
//  *
//  * 		– Flag: '-',
//  *       - Width
//  *
//  */

// 	ft_printf("||\n", );
// 	printf("||\n\n", );

// 	ft_printf("||\n", );
// 	printf("||\n\n", );

// 	ft_printf("||\n", );
// 	printf("||\n\n", );

// 	ft_printf("||\n", );
// 	printf("||\n\n", );

// 	ft_printf("||\n", );
// 	printf("||\n\n", );

// 	ft_printf("||\n", );
// 	printf("||\n\n", );

// 	ft_printf("||\n", );
// 	printf("||\n\n", );

/* — — — — – – – – – – – – – – – – – – – – – – – – – –  */

// /* %c SPECIFIER TESTS */

// /**
//  * Only takes the following flags & fields:
//  *
//  * 		– Flag: '-',
//  *       - Width
//  *
//  */

// 	ft_printf("||\n", );
// 	printf("||\n\n", );

// 	ft_printf("||\n", );
// 	printf("||\n\n", );

// 	ft_printf("||\n", );
// 	printf("||\n\n", );

// 	ft_printf("||\n", );
// 	printf("||\n\n", );

// 	ft_printf("||\n", );
// 	printf("||\n\n", );

// 	ft_printf("||\n", );
// 	printf("||\n\n", );

// 	ft_printf("||\n", );
// 	printf("||\n\n", );

/* — — — — – – – – – – – – – – – – – – – – – – – – – –  */

// /* %c SPECIFIER TESTS */

// /**
//  * Only takes the following flags & fields:
//  *
//  * 		– Flag: '-',
//  *       - Width
//  *
//  */

// 	ft_printf("||\n", );
// 	printf("||\n\n", );

// 	ft_printf("||\n", );
// 	printf("||\n\n", );

// 	ft_printf("||\n", );
// 	printf("||\n\n", );

// 	ft_printf("||\n", );
// 	printf("||\n\n", );

// 	ft_printf("||\n", );
// 	printf("||\n\n", );

// 	ft_printf("||\n", );
// 	printf("||\n\n", );

// 	ft_printf("||\n", );
// 	printf("||\n\n", );

/* — — — — – – – – – – – – – – – – – – – – – – – – – –  */

/* %p SPECIFIER TESTS */

/**
 * Only takes the following flags & fields:
 *
 * 		– Flag: '-',
 *      - Width
 *
 */

	// ft_printf("|%p|\n", (void *)0);
	// printf("|%p|\n\n", (void *)0);

	// ft_printf("|%-p|\n", av);
	// printf("|%-p|\n\n", av);

	// ft_printf("|%p|\n", &(av[0]));
	// printf("|%p|\n\n", &(av[0]));

	// ft_printf("|%-30p|\n", av[0]);
	// printf("|%-30p|\n\n", av[0]);

	// ft_printf("|%*p|\n", 10, &ft_printf);
	// printf("|%*p|\n\n", 10, &ft_printf);

	// ft_printf("|%*p|\n", 25, &printf);
	// printf("|%*p|\n\n", 60, &printf);

	// ft_printf("|%*p|\n", 40, (void *)NULL);
	// printf("|%*p|\n\n", 40, (void *)NULL);

	(void)ac;
	(void)av;

	return (0);
}
