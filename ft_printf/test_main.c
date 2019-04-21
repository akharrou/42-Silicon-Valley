/**
 *
 * TEST MAIN
 *
 */

#include "ft_printf.h"

// #include "ft_printf.c"
// #include "parser.c"
// #include "converter.c"

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

	// ft_printf("%s\n", NULL);
	// printf("%s\n", NULL);

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
//  *       - Precison
//  *
//  */

	// ft_printf("%r\n", NULL);
	// printf("%r\n", NULL);

	// ft_printf("|%-10.2s|\n", "\x08hello\x09");
	// printf("|%-10.2s|\n\n", "\x08hello\x09");

	// ft_printf("|%12.2s|\n", "\x30h\x29 e\x28l\x27l\x26o\x25");
	// printf("|%12.2s|\n\n", "\x30h\x29 e\x28l\x27l\x26o\x25");

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

	// ft_printf("|%c|\n", 127);
	// printf("|%c|\n\n", 127);

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

// /* %% SPECIFIER TESTS */

// /**
//  * Only takes the following flags & fields:
//  *
//  * 		– Flag: '-',
//  *       - Width
//  *
//  * Everything else does nothing even though you can
//  * specify those fields and flags.
//  *
//  */

	// ft_printf("|%%|\n");
	// printf("|%%|\n\n");

	// ft_printf("|%20%|\n");
	// printf("|%20%|\n\n");

	// ft_printf("|%*%|\n", 15);
	// printf("|%*%|\n\n", 15);

	// ft_printf("|%10.5%|\n");
	// printf("|%10.5%|\n\n");

	// ft_printf("|%+%|\n");
	// printf("|%+%|\n\n");

	// ft_printf("|%#%|\n");
	// printf("|%#%|\n\n");

	// ft_printf("|%-010.20%|\n");
	// printf("|%-010.20%|\n\n");

	// ft_printf("|% +5.10%|\n");
	// printf("|% +5.10%|\n\n");

/* — — — — – – – – – – – – – – – – – – – – – – – – – –  */

// /* %d & %i SPECIFIER TESTS */

// /**
//  * Only takes the following flags & fields:
//  *
//  * 		– Flag: '-', ' ', '0', '+'
//  *       - Width: defined or '*'
//  *       - Precision: defined or '*'
//  *       - Length: 'h', 'hh', 'l', 'll'
//  *
//  */

// // MAXs & MINs

// 	ft_printf("|%hhi|\n",  (signed char)CHAR_MAX);
// 	printf("|%hhi|\n\n",   (signed char)CHAR_MAX);
// 	ft_printf("|%hhi|\n",  (signed char)CHAR_MIN);
// 	printf("|%hhi|\n\n",   (signed char)CHAR_MIN);

// 	ft_printf("|%hi|\n",   (short int)SHORT_MAX);
// 	printf("|%hi|\n\n",    (short int)SHORT_MAX);
// 	ft_printf("|%hi|\n",   (short int)SHORT_MIN);
// 	printf("|%hi|\n\n",    (short int)SHORT_MIN);

// 	ft_printf("|%i|\n",    (int)INT_MAX);
// 	printf("|%i|\n\n",     (int)INT_MAX);
// 	ft_printf("|%i|\n",    (int)INT_MIN);
// 	printf("|%i|\n\n",     (int)INT_MIN);

// 	ft_printf("|%li|\n",   (long int)LONG_MAX);
// 	printf("|%li|\n\n",    (long int)LONG_MAX);
// 	ft_printf("|%li|\n",   (long int)-9223372036854775807);
// 	printf("|%li|\n\n",    (long int)-9223372036854775807);

// 	ft_printf("|%lli|\n",  (long long)LLONG_MAX);
// 	printf("|%lli|\n\n",   (long long)LLONG_MAX);


// /* ++++++++++++++++++++++++++++ LENGTH HH +++++++++++++++++++++++++++ */
// /* ++++++++++++++++++++++++++++ LENGTH HH +++++++++++++++++++++++++++ */


// // Width & Precision (with no flags)

// 	ft_printf("|%10hhi|\n", (signed char)112);
// 	printf("|%10hhi|\n\n", (signed char)112);

// 	ft_printf("|%30hhi|\n", (signed char)112);
// 	printf("|%30hhi|\n\n", (signed char)112);

// 	ft_printf("|%.6hhi|\n", (signed char)112);
// 	printf("|%.6hhi|\n\n", (signed char)112);

// 	ft_printf("|%.10hhi|\n", (signed char)112);
// 	printf("|%.10hhi|\n\n", (signed char)112);

// 	ft_printf("|%25.10hhi|\n", (signed char)112);
// 	printf("|%25.10hhi|\n\n", (signed char)112);

// 	ft_printf("|%25.*hhi|\n", 10, (signed char)112);
// 	printf("|%25.*hhi|\n\n", 10, (signed char)112);

// 	ft_printf("|%25.*hhi|\n", 10, (signed char)112);
// 	printf("|%25.*hhi|\n\n", 10, (signed char)112);

// 	ft_printf("|%*.*hhi|\n", 25, 10, (signed char)112);
// 	printf("|%*.*hhi|\n\n", 25, 10, (signed char)112);

// 	ft_printf("|%*.10hhi|\n", 25, (signed char)112);
// 	printf("|%*.10hhi|\n\n", 25, (signed char)112);

// // Width & Precision (with '-')

// 	ft_printf("|%-10hhi|\n", (signed char)112);
// 	printf("|%-10hhi|\n\n", (signed char)112);

// 	ft_printf("|%-30hhi|\n", (signed char)112);
// 	printf("|%-30hhi|\n\n", (signed char)112);

// 	ft_printf("|%-.6hhi|\n", (signed char)112);
// 	printf("|%-.6hhi|\n\n", (signed char)112);

// 	ft_printf("|%-.10hhi|\n", (signed char)112);
// 	printf("|%-.10hhi|\n\n", (signed char)112);

// 	ft_printf("|%-25.10hhi|\n", (signed char)112);
// 	printf("|%-25.10hhi|\n\n", (signed char)112);

// 	ft_printf("|%-25.*hhi|\n", 10, (signed char)112);
// 	printf("|%-25.*hhi|\n\n", 10, (signed char)112);

// 	ft_printf("|%-25.*hhi|\n", 10, (signed char)112);
// 	printf("|%-25.*hhi|\n\n", 10, (signed char)112);

// 	ft_printf("|%-*.*hhi|\n", 25, 10, (signed char)112);
// 	printf("|%-*.*hhi|\n\n", 25, 10, (signed char)112);

// 	ft_printf("|%-*.10hhi|\n", 25, (signed char)112);
// 	printf("|%-*.10hhi|\n\n", 25, (signed char)112);

// // Width & Precision ('-' with '+')

// 	ft_printf("|%+-10hhi|\n", (signed char)112);
// 	printf("|%+-10hhi|\n\n", (signed char)112);

// 	ft_printf("|%+-30hhi|\n", (signed char)112);
// 	printf("|%+-30hhi|\n\n", (signed char)112);

// 	ft_printf("|%+-.6hhi|\n", (signed char)112);
// 	printf("|%+-.6hhi|\n\n", (signed char)112);

// 	ft_printf("|%+-.10hhi|\n", (signed char)112);
// 	printf("|%+-.10hhi|\n\n", (signed char)112);

// 	ft_printf("|%+-25.10hhi|\n", (signed char)112);
// 	printf("|%+-25.10hhi|\n\n", (signed char)112);

// 	ft_printf("|%+-25.*hhi|\n", 10, (signed char)112);
// 	printf("|%+-25.*hhi|\n\n", 10, (signed char)112);

// 	ft_printf("|%+-25.*hhi|\n", 10, (signed char)112);
// 	printf("|%+-25.*hhi|\n\n", 10, (signed char)112);

// 	ft_printf("|%+-*.*hhi|\n", 25, 10, (signed char)112);
// 	printf("|%+-*.*hhi|\n\n", 25, 10, (signed char)112);

// 	ft_printf("|%+-*.10hhi|\n", 25, (signed char)112);
// 	printf("|%+-*.10hhi|\n\n", 25, (signed char)112);

// // Width & Precision ('-' with '+')

// 	ft_printf("|%+-10hhi|\n", (signed char)-112);
// 	printf("|%+-10hhi|\n\n", (signed char)-112);

// 	ft_printf("|%+-30hhi|\n", (signed char)-112);
// 	printf("|%+-30hhi|\n\n", (signed char)-112);

// 	ft_printf("|%+-.6hhi|\n", (signed char)-112);
// 	printf("|%+-.6hhi|\n\n", (signed char)-112);

// 	ft_printf("|%+-.10hhi|\n", (signed char)-112);
// 	printf("|%+-.10hhi|\n\n", (signed char)-112);

// 	ft_printf("|%+-25.10hhi|\n", (signed char)-112);
// 	printf("|%+-25.10hhi|\n\n", (signed char)-112);

// 	ft_printf("|%+-25.*hhi|\n", 10, (signed char)-112);
// 	printf("|%+-25.*hhi|\n\n", 10, (signed char)-112);

// 	ft_printf("|%+-25.*hhi|\n", 10, (signed char)-112);
// 	printf("|%+-25.*hhi|\n\n", 10, (signed char)-112);

// 	ft_printf("|%+-*.*hhi|\n", 25, 10, (signed char)-112);
// 	printf("|%+-*.*hhi|\n\n", 25, 10, (signed char)-112);

// 	ft_printf("|%+-*.10hhi|\n", 25, (signed char)-112);
// 	printf("|%+-*.10hhi|\n\n", 25, (signed char)-112);

// // Width & Precision ('-' with ' ')

// 	ft_printf("|% -10hhi|\n", (signed char)112);
// 	printf("|% -10hhi|\n\n", (signed char)112);

// 	ft_printf("|% -30hhi|\n", (signed char)112);
// 	printf("|% -30hhi|\n\n", (signed char)112);

// 	ft_printf("|% -.6hhi|\n", (signed char)112);
// 	printf("|% -.6hhi|\n\n", (signed char)112);

// 	ft_printf("|% -.10hhi|\n", (signed char)112);
// 	printf("|% -.10hhi|\n\n", (signed char)112);

// 	ft_printf("|% -25.10hhi|\n", (signed char)112);
// 	printf("|% -25.10hhi|\n\n", (signed char)112);

// 	ft_printf("|% -25.*hhi|\n", 10, (signed char)112);
// 	printf("|% -25.*hhi|\n\n", 10, (signed char)112);

// 	ft_printf("|% -25.*hhi|\n", 10, (signed char)112);
// 	printf("|% -25.*hhi|\n\n", 10, (signed char)112);

// 	ft_printf("|% -*.*hhi|\n", 25, 10, (signed char)112);
// 	printf("|% -*.*hhi|\n\n", 25, 10, (signed char)112);

// 	ft_printf("|% -*.10hhi|\n", 25, (signed char)112);
// 	printf("|% -*.10hhi|\n\n", 25, (signed char)112);

// // Width & Precision ' ')

// 	ft_printf("|% 10hhi|\n", (signed char)112);
// 	printf("|% 10hhi|\n\n", (signed char)112);

// 	ft_printf("|% 30hhi|\n", (signed char)112);
// 	printf("|% 30hhi|\n\n", (signed char)112);

// 	ft_printf("|% .6hhi|\n", (signed char)112);
// 	printf("|% .6hhi|\n\n", (signed char)112);

// 	ft_printf("|% .10hhi|\n", (signed char)112);
// 	printf("|% .10hhi|\n\n", (signed char)112);

// 	ft_printf("|% 25.10hhi|\n", (signed char)112);
// 	printf("|% 25.10hhi|\n\n", (signed char)112);

// 	ft_printf("|% 25.*hhi|\n", 10, (signed char)112);
// 	printf("|% 25.*hhi|\n\n", 10, (signed char)112);

// 	ft_printf("|% 25.*hhi|\n", 10, (signed char)112);
// 	printf("|% 25.*hhi|\n\n", 10, (signed char)112);

// 	ft_printf("|% *.*hhi|\n", 25, 10, (signed char)112);
// 	printf("|% *.*hhi|\n\n", 25, 10, (signed char)112);

// 	ft_printf("|% *.10hhi|\n", 25, (signed char)112);
// 	printf("|% *.10hhi|\n\n", 25, (signed char)112);

// // Width & Precision ('0')

// 	ft_printf("|%010hhi|\n", (signed char)112);
// 	printf("|%010hhi|\n\n", (signed char)112);

// 	ft_printf("|%030hhi|\n", (signed char)112);
// 	printf("|%030hhi|\n\n", (signed char)112);

// 	ft_printf("|%0.6hhi|\n", (signed char)112);
// 	printf("|%0.6hhi|\n\n", (signed char)112);

// 	ft_printf("|%0.10hhi|\n", (signed char)112);
// 	printf("|%0.10hhi|\n\n", (signed char)112);

// 	ft_printf("|%025.10hhi|\n", (signed char)112);
// 	printf("|%025.10hhi|\n\n", (signed char)112);

// 	ft_printf("|%025.*hhi|\n", 10, (signed char)112);
// 	printf("|%025.*hhi|\n\n", 10, (signed char)112);

// 	ft_printf("|%025.*hhi|\n", 10, (signed char)112);
// 	printf("|%025.*hhi|\n\n", 10, (signed char)112);

// 	ft_printf("|%0*.*hhi|\n", 25, 10, (signed char)112);
// 	printf("|%0*.*hhi|\n\n", 25, 10, (signed char)112);

// 	ft_printf("|%0*.10hhi|\n", 25, (signed char)112);
// 	printf("|%0*.10hhi|\n\n", 25, (signed char)112);


// /* ++++++++++++++++++++++++++++ LENGTH H +++++++++++++++++++++++++++ */
// /* ++++++++++++++++++++++++++++ LENGTH H +++++++++++++++++++++++++++ */

// // Width & Precision (with no flags)

// 	ft_printf("|%10hi|\n", (short)27352);
// 	printf("|%10hi|\n\n", (short)27352);

// 	ft_printf("|%30hi|\n", (short)27352);
// 	printf("|%30hi|\n\n", (short)27352);

// 	ft_printf("|%.6hi|\n", (short)27352);
// 	printf("|%.6hi|\n\n", (short)27352);

// 	ft_printf("|%.10hi|\n", (short)27352);
// 	printf("|%.10hi|\n\n", (short)27352);

// 	ft_printf("|%25.10hi|\n", (short)27352);
// 	printf("|%25.10hi|\n\n", (short)27352);

// 	ft_printf("|%25.*hi|\n", 10, (short)27352);
// 	printf("|%25.*hi|\n\n", 10, (short)27352);

// 	ft_printf("|%25.*hi|\n", 10, (short)27352);
// 	printf("|%25.*hi|\n\n", 10, (short)27352);

// 	ft_printf("|%*.*hi|\n", 25, 10, (short)27352);
// 	printf("|%*.*hi|\n\n", 25, 10, (short)27352);

// 	ft_printf("|%*.10hi|\n", 25, (short)27352);
// 	printf("|%*.10hi|\n\n", 25, (short)27352);

// // Width & Precision (with '-')

// 	ft_printf("|%-10hi|\n", (short)27352);
// 	printf("|%-10hi|\n\n", (short)27352);

// 	ft_printf("|%-30hi|\n", (short)27352);
// 	printf("|%-30hi|\n\n", (short)27352);

// 	ft_printf("|%-.6hi|\n", (short)27352);
// 	printf("|%-.6hi|\n\n", (short)27352);

// 	ft_printf("|%-.10hi|\n", (short)27352);
// 	printf("|%-.10hi|\n\n", (short)27352);

// 	ft_printf("|%-25.10hi|\n", (short)27352);
// 	printf("|%-25.10hi|\n\n", (short)27352);

// 	ft_printf("|%-25.*hi|\n", 10, (short)27352);
// 	printf("|%-25.*hi|\n\n", 10, (short)27352);

// 	ft_printf("|%-25.*hi|\n", 10, (short)27352);
// 	printf("|%-25.*hi|\n\n", 10, (short)27352);

// 	ft_printf("|%-*.*hi|\n", 25, 10, (short)27352);
// 	printf("|%-*.*hi|\n\n", 25, 10, (short)27352);

// 	ft_printf("|%-*.10hi|\n", 25, (short)27352);
// 	printf("|%-*.10hi|\n\n", 25, (short)27352);

// // Width & Precision ('-' with '+')

// 	ft_printf("|%+-10hi|\n", (short)27352);
// 	printf("|%+-10hi|\n\n", (short)27352);

// 	ft_printf("|%+-30hi|\n", (short)27352);
// 	printf("|%+-30hi|\n\n", (short)27352);

// 	ft_printf("|%+-.6hi|\n", (short)27352);
// 	printf("|%+-.6hi|\n\n", (short)27352);

// 	ft_printf("|%+-.10hi|\n", (short)27352);
// 	printf("|%+-.10hi|\n\n", (short)27352);

// 	ft_printf("|%+-25.10hi|\n", (short)27352);
// 	printf("|%+-25.10hi|\n\n", (short)27352);

// 	ft_printf("|%+-25.*hi|\n", 10, (short)27352);
// 	printf("|%+-25.*hi|\n\n", 10, (short)27352);

// 	ft_printf("|%+-25.*hi|\n", 10, (short)27352);
// 	printf("|%+-25.*hi|\n\n", 10, (short)27352);

// 	ft_printf("|%+-*.*hi|\n", 25, 10, (short)27352);
// 	printf("|%+-*.*hi|\n\n", 25, 10, (short)27352);

// 	ft_printf("|%+-*.10hi|\n", 25, (short)27352);
// 	printf("|%+-*.10hi|\n\n", 25, (short)27352);

// // Width & Precision ('-' with '+')

// 	ft_printf("|%+-10hi|\n", (short)-27352);
// 	printf("|%+-10hi|\n\n", (short)-27352);

// 	ft_printf("|%+-30hi|\n", (short)-27352);
// 	printf("|%+-30hi|\n\n", (short)-27352);

// 	ft_printf("|%+-.6hi|\n", (short)-27352);
// 	printf("|%+-.6hi|\n\n", (short)-27352);

// 	ft_printf("|%+-.10hi|\n", (short)-27352);
// 	printf("|%+-.10hi|\n\n", (short)-27352);

// 	ft_printf("|%+-25.10hi|\n", (short)-27352);
// 	printf("|%+-25.10hi|\n\n", (short)-27352);

// 	ft_printf("|%+-25.*hi|\n", 10, (short)-27352);
// 	printf("|%+-25.*hi|\n\n", 10, (short)-27352);

// 	ft_printf("|%+-25.*hi|\n", 10, (short)-27352);
// 	printf("|%+-25.*hi|\n\n", 10, (short)-27352);

// 	ft_printf("|%+-*.*hi|\n", 25, 10, (short)-27352);
// 	printf("|%+-*.*hi|\n\n", 25, 10, (short)-27352);

// 	ft_printf("|%+-*.10hi|\n", 25, (short)-27352);
// 	printf("|%+-*.10hi|\n\n", 25, (short)-27352);

// // Width & Precision ('-' with ' ')

// 	ft_printf("|% -10hi|\n", (short)27352);
// 	printf("|% -10hi|\n\n", (short)27352);

// 	ft_printf("|% -30hi|\n", (short)27352);
// 	printf("|% -30hi|\n\n", (short)27352);

// 	ft_printf("|% -.6hi|\n", (short)27352);
// 	printf("|% -.6hi|\n\n", (short)27352);

// 	ft_printf("|% -.10hi|\n", (short)27352);
// 	printf("|% -.10hi|\n\n", (short)27352);

// 	ft_printf("|% -25.10hi|\n", (short)27352);
// 	printf("|% -25.10hi|\n\n", (short)27352);

// 	ft_printf("|% -25.*hi|\n", 10, (short)27352);
// 	printf("|% -25.*hi|\n\n", 10, (short)27352);

// 	ft_printf("|% -25.*hi|\n", 10, (short)27352);
// 	printf("|% -25.*hi|\n\n", 10, (short)27352);

// 	ft_printf("|% -*.*hi|\n", 25, 10, (short)27352);
// 	printf("|% -*.*hi|\n\n", 25, 10, (short)27352);

// 	ft_printf("|% -*.10hi|\n", 25, (short)27352);
// 	printf("|% -*.10hi|\n\n", 25, (short)27352);

// // Width & Precision ' ')

// 	ft_printf("|% 10hi|\n", (short)27352);
// 	printf("|% 10hi|\n\n", (short)27352);

// 	ft_printf("|% 30hi|\n", (short)27352);
// 	printf("|% 30hi|\n\n", (short)27352);

// 	ft_printf("|% .6hi|\n", (short)27352);
// 	printf("|% .6hi|\n\n", (short)27352);

// 	ft_printf("|% .10hi|\n", (short)27352);
// 	printf("|% .10hi|\n\n", (short)27352);

// 	ft_printf("|% 25.10hi|\n", (short)27352);
// 	printf("|% 25.10hi|\n\n", (short)27352);

// 	ft_printf("|% 25.*hi|\n", 10, (short)27352);
// 	printf("|% 25.*hi|\n\n", 10, (short)27352);

// 	ft_printf("|% 25.*hi|\n", 10, (short)27352);
// 	printf("|% 25.*hi|\n\n", 10, (short)27352);

// 	ft_printf("|% *.*hi|\n", 25, 10, (short)27352);
// 	printf("|% *.*hi|\n\n", 25, 10, (short)27352);

// 	ft_printf("|% *.10hi|\n", 25, (short)27352);
// 	printf("|% *.10hi|\n\n", 25, (short)27352);

// // Width & Precision ('0')

// 	ft_printf("|%010hi|\n", (short)27352);
// 	printf("|%010hi|\n\n", (short)27352);

// 	ft_printf("|%030hi|\n", (short)27352);
// 	printf("|%030hi|\n\n", (short)27352);

// 	ft_printf("|%0.6hi|\n", (short)27352);
// 	printf("|%0.6hi|\n\n", (short)27352);

// 	ft_printf("|%0.10hi|\n", (short)27352);
// 	printf("|%0.10hi|\n\n", (short)27352);

// 	ft_printf("|%025.10hi|\n", (short)27352);
// 	printf("|%025.10hi|\n\n", (short)27352);

// 	ft_printf("|%025.*hi|\n", 10, (short)27352);
// 	printf("|%025.*hi|\n\n", 10, (short)27352);

// 	ft_printf("|%025.*hi|\n", 10, (short)27352);
// 	printf("|%025.*hi|\n\n", 10, (short)27352);

// 	ft_printf("|%0*.*hi|\n", 25, 10, (short)27352);
// 	printf("|%0*.*hi|\n\n", 25, 10, (short)27352);

// 	ft_printf("|%0*.10hi|\n", 25, (short)27352);
// 	printf("|%0*.10hi|\n\n", 25, (short)27352);


// /* ++++++++++++++++++++++++++++ LENGTH DEFAULT +++++++++++++++++++++++++++ */
// /* ++++++++++++++++++++++++++++ LENGTH DEFAULT +++++++++++++++++++++++++++ */


// // Width & Precision (with no flags)

// 	ft_printf("|%10i|\n", 12345);
// 	printf("|%10i|\n\n", 12345);

// 	ft_printf("|%30i|\n", 12345);
// 	printf("|%30i|\n\n", 12345);

// 	ft_printf("|%.6i|\n", 12345);
// 	printf("|%.6i|\n\n", 12345);

// 	ft_printf("|%.10i|\n", 12345);
// 	printf("|%.10i|\n\n", 12345);

// 	ft_printf("|%25.10i|\n", 12345);
// 	printf("|%25.10i|\n\n", 12345);

// 	ft_printf("|%25.*i|\n", 10, 12345);
// 	printf("|%25.*i|\n\n", 10, 12345);

// 	ft_printf("|%25.*i|\n", 10, 12345);
// 	printf("|%25.*i|\n\n", 10, 12345);

// 	ft_printf("|%*.*i|\n", 25, 10, 12345);
// 	printf("|%*.*i|\n\n", 25, 10, 12345);

// 	ft_printf("|%*.10i|\n", 25, 12345);
// 	printf("|%*.10i|\n\n", 25, 12345);

// // Width & Precision (with '-')

// 	ft_printf("|%-10i|\n", 12345);
// 	printf("|%-10i|\n\n", 12345);

// 	ft_printf("|%-30i|\n", 12345);
// 	printf("|%-30i|\n\n", 12345);

// 	ft_printf("|%-.6i|\n", 12345);
// 	printf("|%-.6i|\n\n", 12345);

// 	ft_printf("|%-.10i|\n", 12345);
// 	printf("|%-.10i|\n\n", 12345);

// 	ft_printf("|%-25.10i|\n", 12345);
// 	printf("|%-25.10i|\n\n", 12345);

// 	ft_printf("|%-25.*i|\n", 10, 12345);
// 	printf("|%-25.*i|\n\n", 10, 12345);

// 	ft_printf("|%-25.*i|\n", 10, 12345);
// 	printf("|%-25.*i|\n\n", 10, 12345);

// 	ft_printf("|%-*.*i|\n", 25, 10, 12345);
// 	printf("|%-*.*i|\n\n", 25, 10, 12345);

// 	ft_printf("|%-*.10i|\n", 25, 12345);
// 	printf("|%-*.10i|\n\n", 25, 12345);

// // Width & Precision ('-' with '+')

// 	ft_printf("|%+-10i|\n", 12345);
// 	printf("|%+-10i|\n\n", 12345);

// 	ft_printf("|%+-30i|\n", 12345);
// 	printf("|%+-30i|\n\n", 12345);

// 	ft_printf("|%+-.6i|\n", 12345);
// 	printf("|%+-.6i|\n\n", 12345);

// 	ft_printf("|%+-.10i|\n", 12345);
// 	printf("|%+-.10i|\n\n", 12345);

// 	ft_printf("|%+-25.10i|\n", 12345);
// 	printf("|%+-25.10i|\n\n", 12345);

// 	ft_printf("|%+-25.*i|\n", 10, 12345);
// 	printf("|%+-25.*i|\n\n", 10, 12345);

// 	ft_printf("|%+-25.*i|\n", 10, 12345);
// 	printf("|%+-25.*i|\n\n", 10, 12345);

// 	ft_printf("|%+-*.*i|\n", 25, 10, 12345);
// 	printf("|%+-*.*i|\n\n", 25, 10, 12345);

// 	ft_printf("|%+-*.10i|\n", 25, 12345);
// 	printf("|%+-*.10i|\n\n", 25, 12345);

// // Width & Precision ('-' with '+')

// 	ft_printf("|%+-10i|\n", -12345);
// 	printf("|%+-10i|\n\n", -12345);

// 	ft_printf("|%+-30i|\n", -12345);
// 	printf("|%+-30i|\n\n", -12345);

// 	ft_printf("|%+-.6i|\n", -12345);
// 	printf("|%+-.6i|\n\n", -12345);

// 	ft_printf("|%+-.10i|\n", -12345);
// 	printf("|%+-.10i|\n\n", -12345);

// 	ft_printf("|%+-25.10i|\n", -12345);
// 	printf("|%+-25.10i|\n\n", -12345);

// 	ft_printf("|%+-25.*i|\n", 10, -12345);
// 	printf("|%+-25.*i|\n\n", 10, -12345);

// 	ft_printf("|%+-25.*i|\n", 10, -12345);
// 	printf("|%+-25.*i|\n\n", 10, -12345);

// 	ft_printf("|%+-*.*i|\n", 25, 10, -12345);
// 	printf("|%+-*.*i|\n\n", 25, 10, -12345);

// 	ft_printf("|%+-*.10i|\n", 25, -12345);
// 	printf("|%+-*.10i|\n\n", 25, -12345);

// // Width & Precision ('-' with ' ')

// 	ft_printf("|% -10i|\n", 12345);
// 	printf("|% -10i|\n\n", 12345);

// 	ft_printf("|% -30i|\n", 12345);
// 	printf("|% -30i|\n\n", 12345);

// 	ft_printf("|% -.6i|\n", 12345);
// 	printf("|% -.6i|\n\n", 12345);

// 	ft_printf("|% -.10i|\n", 12345);
// 	printf("|% -.10i|\n\n", 12345);

// 	ft_printf("|% -25.10i|\n", 12345);
// 	printf("|% -25.10i|\n\n", 12345);

// 	ft_printf("|% -25.*i|\n", 10, 12345);
// 	printf("|% -25.*i|\n\n", 10, 12345);

// 	ft_printf("|% -25.*i|\n", 10, 12345);
// 	printf("|% -25.*i|\n\n", 10, 12345);

// 	ft_printf("|% -*.*i|\n", 25, 10, 12345);
// 	printf("|% -*.*i|\n\n", 25, 10, 12345);

// 	ft_printf("|% -*.10i|\n", 25, 12345);
// 	printf("|% -*.10i|\n\n", 25, 12345);

// // Width & Precision ' ')

// 	ft_printf("|% 10i|\n", 12345);
// 	printf("|% 10i|\n\n", 12345);

// 	ft_printf("|% 30i|\n", 12345);
// 	printf("|% 30i|\n\n", 12345);

// 	ft_printf("|% .6i|\n", 12345);
// 	printf("|% .6i|\n\n", 12345);

// 	ft_printf("|% .10i|\n", 12345);
// 	printf("|% .10i|\n\n", 12345);

// 	ft_printf("|% 25.10i|\n", 12345);
// 	printf("|% 25.10i|\n\n", 12345);

// 	ft_printf("|% 25.*i|\n", 10, 12345);
// 	printf("|% 25.*i|\n\n", 10, 12345);

// 	ft_printf("|% 25.*i|\n", 10, 12345);
// 	printf("|% 25.*i|\n\n", 10, 12345);

// 	ft_printf("|% *.*i|\n", 25, 10, 12345);
// 	printf("|% *.*i|\n\n", 25, 10, 12345);

// 	ft_printf("|% *.10i|\n", 25, 12345);
// 	printf("|% *.10i|\n\n", 25, 12345);

// // Width & Precision ('0')

// 	ft_printf("|%010i|\n", 12345);
// 	printf("|%010i|\n\n", 12345);

// 	ft_printf("|%030i|\n", 12345);
// 	printf("|%030i|\n\n", 12345);

// 	ft_printf("|%0.6i|\n", 12345);
// 	printf("|%0.6i|\n\n", 12345);

// 	ft_printf("|%0.10i|\n", 12345);
// 	printf("|%0.10i|\n\n", 12345);

// 	ft_printf("|%025.10i|\n", 12345);
// 	printf("|%025.10i|\n\n", 12345);

// 	ft_printf("|%025.*i|\n", 10, 12345);
// 	printf("|%025.*i|\n\n", 10, 12345);

// 	ft_printf("|%025.*i|\n", 10, 12345);
// 	printf("|%025.*i|\n\n", 10, 12345);

// 	ft_printf("|%0*.*i|\n", 25, 10, 12345);
// 	printf("|%0*.*i|\n\n", 25, 10, 12345);

// 	ft_printf("|%0*.10i|\n", 25, 12345);
// 	printf("|%0*.10i|\n\n", 25, 12345);


// /* ++++++++++++++++++++++++++++ LENGTH L +++++++++++++++++++++++++++ */
// /* ++++++++++++++++++++++++++++ LENGTH L +++++++++++++++++++++++++++ */


// // Width & Precision (with no flags)

// 	ft_printf("|%10li|\n", (signed long)52728623);
// 	printf("|%10li|\n\n", (signed long)52728623);

// 	ft_printf("|%30li|\n", (signed long)52728623);
// 	printf("|%30li|\n\n", (signed long)52728623);

// 	ft_printf("|%.6li|\n", (signed long)52728623);
// 	printf("|%.6li|\n\n", (signed long)52728623);

// 	ft_printf("|%.10li|\n", (signed long)52728623);
// 	printf("|%.10li|\n\n", (signed long)52728623);

// 	ft_printf("|%40.10li|\n", (signed long)52728623);
// 	printf("|%40.10li|\n\n", (signed long)52728623);

// 	ft_printf("|%40.*li|\n", 10, (signed long)52728623);
// 	printf("|%40.*li|\n\n", 10, (signed long)52728623);

// 	ft_printf("|%40.*li|\n", 10, (signed long)52728623);
// 	printf("|%40.*li|\n\n", 10, (signed long)52728623);

// 	ft_printf("|%*.*li|\n", 40, 10, (signed long)52728623);
// 	printf("|%*.*li|\n\n", 40, 10, (signed long)52728623);

// 	ft_printf("|%*.10li|\n", 40, (signed long)52728623);
// 	printf("|%*.10li|\n\n", 40, (signed long)52728623);

// // Width & Precision (with '-')

// 	ft_printf("|%-10li|\n", (signed long)52728623);
// 	printf("|%-10li|\n\n", (signed long)52728623);

// 	ft_printf("|%-30li|\n", (signed long)52728623);
// 	printf("|%-30li|\n\n", (signed long)52728623);

// 	ft_printf("|%-.6li|\n", (signed long)52728623);
// 	printf("|%-.6li|\n\n", (signed long)52728623);

// 	ft_printf("|%-.10li|\n", (signed long)52728623);
// 	printf("|%-.10li|\n\n", (signed long)52728623);

// 	ft_printf("|%-40.10li|\n", (signed long)52728623);
// 	printf("|%-40.10li|\n\n", (signed long)52728623);

// 	ft_printf("|%-40.*li|\n", 10, (signed long)52728623);
// 	printf("|%-40.*li|\n\n", 10, (signed long)52728623);

// 	ft_printf("|%-40.*li|\n", 10, (signed long)52728623);
// 	printf("|%-40.*li|\n\n", 10, (signed long)52728623);

// 	ft_printf("|%-*.*li|\n", 40, 10, (signed long)52728623);
// 	printf("|%-*.*li|\n\n", 40, 10, (signed long)52728623);

// 	ft_printf("|%-*.10li|\n", 40, (signed long)52728623);
// 	printf("|%-*.10li|\n\n", 40, (signed long)52728623);

// // Width & Precision ('-' with '+')

// 	ft_printf("|%+-10li|\n", (signed long)52728623);
// 	printf("|%+-10li|\n\n", (signed long)52728623);

// 	ft_printf("|%+-30li|\n", (signed long)52728623);
// 	printf("|%+-30li|\n\n", (signed long)52728623);

// 	ft_printf("|%+-.6li|\n", (signed long)52728623);
// 	printf("|%+-.6li|\n\n", (signed long)52728623);

// 	ft_printf("|%+-.10li|\n", (signed long)52728623);
// 	printf("|%+-.10li|\n\n", (signed long)52728623);

// 	ft_printf("|%+-40.10li|\n", (signed long)52728623);
// 	printf("|%+-40.10li|\n\n", (signed long)52728623);

// 	ft_printf("|%+-40.*li|\n", 10, (signed long)52728623);
// 	printf("|%+-40.*li|\n\n", 10, (signed long)52728623);

// 	ft_printf("|%+-40.*li|\n", 10, (signed long)52728623);
// 	printf("|%+-40.*li|\n\n", 10, (signed long)52728623);

// 	ft_printf("|%+-*.*li|\n", 40, 10, (signed long)52728623);
// 	printf("|%+-*.*li|\n\n", 40, 10, (signed long)52728623);

// 	ft_printf("|%+-*.10li|\n", 40, (signed long)52728623);
// 	printf("|%+-*.10li|\n\n", 40, (signed long)52728623);

// // Width & Precision ('-' with '+')

// 	ft_printf("|%+-10li|\n", (signed long)-52728623);
// 	printf("|%+-10li|\n\n", (signed long)-52728623);

// 	ft_printf("|%+-30li|\n", (signed long)-52728623);
// 	printf("|%+-30li|\n\n", (signed long)-52728623);

// 	ft_printf("|%+-.6li|\n", (signed long)-52728623);
// 	printf("|%+-.6li|\n\n", (signed long)-52728623);

// 	ft_printf("|%+-.10li|\n", (signed long)-52728623);
// 	printf("|%+-.10li|\n\n", (signed long)-52728623);

// 	ft_printf("|%+-40.10li|\n", (signed long)-52728623);
// 	printf("|%+-40.10li|\n\n", (signed long)-52728623);

// 	ft_printf("|%+-40.*li|\n", 10, (signed long)-52728623);
// 	printf("|%+-40.*li|\n\n", 10, (signed long)-52728623);

// 	ft_printf("|%+-40.*li|\n", 10, (signed long)-52728623);
// 	printf("|%+-40.*li|\n\n", 10, (signed long)-52728623);

// 	ft_printf("|%+-*.*li|\n", 40, 10, (signed long)-52728623);
// 	printf("|%+-*.*li|\n\n", 40, 10, (signed long)-52728623);

// 	ft_printf("|%+-*.10li|\n", 40, (signed long)-52728623);
// 	printf("|%+-*.10li|\n\n", 40, (signed long)-52728623);

// // Width & Precision ('-' with ' ')

// 	ft_printf("|% -10li|\n", (signed long)52728623);
// 	printf("|% -10li|\n\n", (signed long)52728623);

// 	ft_printf("|% -30li|\n", (signed long)52728623);
// 	printf("|% -30li|\n\n", (signed long)52728623);

// 	ft_printf("|% -.6li|\n", (signed long)52728623);
// 	printf("|% -.6li|\n\n", (signed long)52728623);

// 	ft_printf("|% -.10li|\n", (signed long)52728623);
// 	printf("|% -.10li|\n\n", (signed long)52728623);

// 	ft_printf("|% -40.10li|\n", (signed long)52728623);
// 	printf("|% -40.10li|\n\n", (signed long)52728623);

// 	ft_printf("|% -40.*li|\n", 10, (signed long)52728623);
// 	printf("|% -40.*li|\n\n", 10, (signed long)52728623);

// 	ft_printf("|% -40.*li|\n", 10, (signed long)52728623);
// 	printf("|% -40.*li|\n\n", 10, (signed long)52728623);

// 	ft_printf("|% -*.*li|\n", 40, 10, (signed long)52728623);
// 	printf("|% -*.*li|\n\n", 40, 10, (signed long)52728623);

// 	ft_printf("|% -*.10li|\n", 40, (signed long)52728623);
// 	printf("|% -*.10li|\n\n", 40, (signed long)52728623);

// // Width & Precision ' ')

// 	ft_printf("|% 10li|\n", (signed long)52728623);
// 	printf("|% 10li|\n\n", (signed long)52728623);

// 	ft_printf("|% 30li|\n", (signed long)52728623);
// 	printf("|% 30li|\n\n", (signed long)52728623);

// 	ft_printf("|% .6li|\n", (signed long)52728623);
// 	printf("|% .6li|\n\n", (signed long)52728623);

// 	ft_printf("|% .10li|\n", (signed long)52728623);
// 	printf("|% .10li|\n\n", (signed long)52728623);

// 	ft_printf("|% 40.10li|\n", (signed long)52728623);
// 	printf("|% 40.10li|\n\n", (signed long)52728623);

// 	ft_printf("|% 40.*li|\n", 10, (signed long)52728623);
// 	printf("|% 40.*li|\n\n", 10, (signed long)52728623);

// 	ft_printf("|% 40.*li|\n", 10, (signed long)52728623);
// 	printf("|% 40.*li|\n\n", 10, (signed long)52728623);

// 	ft_printf("|% *.*li|\n", 40, 10, (signed long)52728623);
// 	printf("|% *.*li|\n\n", 40, 10, (signed long)52728623);

// 	ft_printf("|% *.10li|\n", 40, (signed long)52728623);
// 	printf("|% *.10li|\n\n", 40, (signed long)52728623);

// // Width & Precision ('0')

// 	ft_printf("|%010li|\n", (signed long)52728623);
// 	printf("|%010li|\n\n", (signed long)52728623);

// 	ft_printf("|%030li|\n", (signed long)52728623);
// 	printf("|%030li|\n\n", (signed long)52728623);

// 	ft_printf("|%0.6li|\n", (signed long)52728623);
// 	printf("|%0.6li|\n\n", (signed long)52728623);

// 	ft_printf("|%0.10li|\n", (signed long)52728623);
// 	printf("|%0.10li|\n\n", (signed long)52728623);

// 	ft_printf("|%040.10li|\n", (signed long)52728623);
// 	printf("|%040.10li|\n\n", (signed long)52728623);

// 	ft_printf("|%040.*li|\n", 10, (signed long)52728623);
// 	printf("|%040.*li|\n\n", 10, (signed long)52728623);

// 	ft_printf("|%040.*li|\n", 10, (signed long)52728623);
// 	printf("|%040.*li|\n\n", 10, (signed long)52728623);

// 	ft_printf("|%0*.*li|\n", 40, 10, (signed long)52728623);
// 	printf("|%0*.*li|\n\n", 40, 10, (signed long)52728623);

// 	ft_printf("|%0*.10li|\n", 40, (signed long)52728623);
// 	printf("|%0*.10li|\n\n", 40, (signed long)52728623);


// /* ++++++++++++++++++++++++++++ LENGTH LL +++++++++++++++++++++++++++ */
// /* ++++++++++++++++++++++++++++ LENGTH LL +++++++++++++++++++++++++++ */


// // Width & Precision (with no flags)

// 	ft_printf("|%10lli|\n", (long long int)27323472342);
// 	printf("|%10lli|\n\n", (long long int)27323472342);

// 	ft_printf("|%30lli|\n", (long long int)27323472342);
// 	printf("|%30lli|\n\n", (long long int)27323472342);

// 	ft_printf("|%.6lli|\n", (long long int)27323472342);
// 	printf("|%.6lli|\n\n", (long long int)27323472342);

// 	ft_printf("|%.10lli|\n", (long long int)27323472342);
// 	printf("|%.10lli|\n\n", (long long int)27323472342);

// 	ft_printf("|%25.10lli|\n", (long long int)27323472342);
// 	printf("|%25.10lli|\n\n", (long long int)27323472342);

// 	ft_printf("|%25.*lli|\n", 60, (long long int)27323472342);
// 	printf("|%25.*lli|\n\n", 60, (long long int)27323472342);

// 	ft_printf("|%25.*lli|\n", 60, (long long int)27323472342);
// 	printf("|%25.*lli|\n\n", 60, (long long int)27323472342);

// 	ft_printf("|%*.*lli|\n", 50, 60, (long long int)27323472342);
// 	printf("|%*.*lli|\n\n", 50, 60, (long long int)27323472342);

// 	ft_printf("|%*.60lli|\n", 50, (long long int)27323472342);
// 	printf("|%*.60lli|\n\n", 50, (long long int)27323472342);

// // Width & Precision (with '-')

// 	ft_printf("|%-60lli|\n", (long long int)27323472342);
// 	printf("|%-60lli|\n\n", (long long int)27323472342);

// 	ft_printf("|%-30lli|\n", (long long int)27323472342);
// 	printf("|%-30lli|\n\n", (long long int)27323472342);

// 	ft_printf("|%-.6lli|\n", (long long int)27323472342);
// 	printf("|%-.6lli|\n\n", (long long int)27323472342);

// 	ft_printf("|%-.60lli|\n", (long long int)27323472342);
// 	printf("|%-.60lli|\n\n", (long long int)27323472342);

// 	ft_printf("|%-50.60lli|\n", (long long int)27323472342);
// 	printf("|%-50.60lli|\n\n", (long long int)27323472342);

// 	ft_printf("|%-50.*lli|\n", 60, (long long int)27323472342);
// 	printf("|%-50.*lli|\n\n", 60, (long long int)27323472342);

// 	ft_printf("|%-50.*lli|\n", 60, (long long int)27323472342);
// 	printf("|%-50.*lli|\n\n", 60, (long long int)27323472342);

// 	ft_printf("|%-*.*lli|\n", 50, 60, (long long int)27323472342);
// 	printf("|%-*.*lli|\n\n", 50, 60, (long long int)27323472342);

// 	ft_printf("|%-*.60lli|\n", 50, (long long int)27323472342);
// 	printf("|%-*.60lli|\n\n", 50, (long long int)27323472342);

// // Width & Precision ('-' with '+')

// 	ft_printf("|%+-60lli|\n", (long long int)27323472342);
// 	printf("|%+-60lli|\n\n", (long long int)27323472342);

// 	ft_printf("|%+-30lli|\n", (long long int)27323472342);
// 	printf("|%+-30lli|\n\n", (long long int)27323472342);

// 	ft_printf("|%+-.6lli|\n", (long long int)27323472342);
// 	printf("|%+-.6lli|\n\n", (long long int)27323472342);

// 	ft_printf("|%+-.60lli|\n", (long long int)27323472342);
// 	printf("|%+-.60lli|\n\n", (long long int)27323472342);

// 	ft_printf("|%+-50.60lli|\n", (long long int)27323472342);
// 	printf("|%+-50.60lli|\n\n", (long long int)27323472342);

// 	ft_printf("|%+-50.*lli|\n", 60, (long long int)27323472342);
// 	printf("|%+-50.*lli|\n\n", 60, (long long int)27323472342);

// 	ft_printf("|%+-50.*lli|\n", 60, (long long int)27323472342);
// 	printf("|%+-50.*lli|\n\n", 60, (long long int)27323472342);

// 	ft_printf("|%+-*.*lli|\n", 50, 60, (long long int)27323472342);
// 	printf("|%+-*.*lli|\n\n", 50, 60, (long long int)27323472342);

// 	ft_printf("|%+-*.60lli|\n", 50, (long long int)27323472342);
// 	printf("|%+-*.60lli|\n\n", 50, (long long int)27323472342);

// // Width & Precision ('-' with '+')

// 	ft_printf("|%+-60lli|\n", (long long int)-27323472342);
// 	printf("|%+-60lli|\n\n", (long long int)-27323472342);

// 	ft_printf("|%+-30lli|\n", (long long int)-27323472342);
// 	printf("|%+-30lli|\n\n", (long long int)-27323472342);

// 	ft_printf("|%+-.6lli|\n", (long long int)-27323472342);
// 	printf("|%+-.6lli|\n\n", (long long int)-27323472342);

// 	ft_printf("|%+-.60lli|\n", (long long int)-27323472342);
// 	printf("|%+-.60lli|\n\n", (long long int)-27323472342);

// 	ft_printf("|%+-50.60lli|\n", (long long int)-27323472342);
// 	printf("|%+-50.60lli|\n\n", (long long int)-27323472342);

// 	ft_printf("|%+-50.*lli|\n", 60, (long long int)-27323472342);
// 	printf("|%+-50.*lli|\n\n", 60, (long long int)-27323472342);

// 	ft_printf("|%+-50.*lli|\n", 60, (long long int)-27323472342);
// 	printf("|%+-50.*lli|\n\n", 60, (long long int)-27323472342);

// 	ft_printf("|%+-*.*lli|\n", 50, 60, (long long int)-27323472342);
// 	printf("|%+-*.*lli|\n\n", 50, 60, (long long int)-27323472342);

// 	ft_printf("|%+-*.60lli|\n", 50, (long long int)-27323472342);
// 	printf("|%+-*.60lli|\n\n", 50, (long long int)-27323472342);

// // Width & Precision ('-' with ' ')

// 	ft_printf("|% -60lli|\n", (long long int)27323472342);
// 	printf("|% -60lli|\n\n", (long long int)27323472342);

// 	ft_printf("|% -30lli|\n", (long long int)27323472342);
// 	printf("|% -30lli|\n\n", (long long int)27323472342);

// 	ft_printf("|% -.6lli|\n", (long long int)27323472342);
// 	printf("|% -.6lli|\n\n", (long long int)27323472342);

// 	ft_printf("|% -.60lli|\n", (long long int)27323472342);
// 	printf("|% -.60lli|\n\n", (long long int)27323472342);

// 	ft_printf("|% -50.60lli|\n", (long long int)27323472342);
// 	printf("|% -50.60lli|\n\n", (long long int)27323472342);

// 	ft_printf("|% -50.*lli|\n", 60, (long long int)27323472342);
// 	printf("|% -50.*lli|\n\n", 60, (long long int)27323472342);

// 	ft_printf("|% -50.*lli|\n", 60, (long long int)27323472342);
// 	printf("|% -50.*lli|\n\n", 60, (long long int)27323472342);

// 	ft_printf("|% -*.*lli|\n", 50, 60, (long long int)27323472342);
// 	printf("|% -*.*lli|\n\n", 50, 60, (long long int)27323472342);

// 	ft_printf("|% -*.60lli|\n", 50, (long long int)27323472342);
// 	printf("|% -*.60lli|\n\n", 50, (long long int)27323472342);

// // Width & Precision ' ')

// 	ft_printf("|% 60lli|\n", (long long int)27323472342);
// 	printf("|% 60lli|\n\n", (long long int)27323472342);

// 	ft_printf("|% 30lli|\n", (long long int)27323472342);
// 	printf("|% 30lli|\n\n", (long long int)27323472342);

// 	ft_printf("|% .6lli|\n", (long long int)27323472342);
// 	printf("|% .6lli|\n\n", (long long int)27323472342);

// 	ft_printf("|% .60lli|\n", (long long int)27323472342);
// 	printf("|% .60lli|\n\n", (long long int)27323472342);

// 	ft_printf("|% 50.60lli|\n", (long long int)27323472342);
// 	printf("|% 50.60lli|\n\n", (long long int)27323472342);

// 	ft_printf("|% 50.*lli|\n", 60, (long long int)27323472342);
// 	printf("|% 50.*lli|\n\n", 60, (long long int)27323472342);

// 	ft_printf("|% 50.*lli|\n", 60, (long long int)27323472342);
// 	printf("|% 50.*lli|\n\n", 60, (long long int)27323472342);

// 	ft_printf("|% *.*lli|\n", 50, 60, (long long int)27323472342);
// 	printf("|% *.*lli|\n\n", 50, 60, (long long int)27323472342);

// 	ft_printf("|% *.60lli|\n", 50, (long long int)27323472342);
// 	printf("|% *.60lli|\n\n", 50, (long long int)27323472342);

// // Width & Precision ('0')

// 	ft_printf("|%060lli|\n", (long long int)27323472342);
// 	printf("|%060lli|\n\n", (long long int)27323472342);

// 	ft_printf("|%030lli|\n", (long long int)27323472342);
// 	printf("|%030lli|\n\n", (long long int)27323472342);

// 	ft_printf("|%0.6lli|\n", (long long int)27323472342);
// 	printf("|%0.6lli|\n\n", (long long int)27323472342);

// 	ft_printf("|%0.60lli|\n", (long long int)27323472342);
// 	printf("|%0.60lli|\n\n", (long long int)27323472342);

// 	ft_printf("|%050.60lli|\n", (long long int)27323472342);
// 	printf("|%050.60lli|\n\n", (long long int)27323472342);

// 	ft_printf("|%050.*lli|\n", 60, (long long int)27323472342);
// 	printf("|%050.*lli|\n\n", 60, (long long int)27323472342);

// 	ft_printf("|%050.*lli|\n", 60, (long long int)27323472342);
// 	printf("|%050.*lli|\n\n", 60, (long long int)27323472342);

// 	ft_printf("|%0*.*lli|\n", 50, 60, (long long int)27323472342);
// 	printf("|%0*.*lli|\n\n", 50, 60, (long long int)27323472342);

// 	ft_printf("|%0*.60lli|\n", 50, (long long int)27323472342);
// 	printf("|%0*.60lli|\n\n", 50, (long long int)27323472342);

/* — — — — – – – – – – – – – – – – – – – – – – – – – –  */

// /* %u SPECIFIER TESTS */

// /**
//  * Only takes the following flags & fields:
//  *
//  * 		– Flag: '-', '0'
//  *       - Width: defined or '*'
//  *       - Precision: defined or '*'
//  *       - Length: 'h', 'hh', 'l', 'll'
//  *
//  */

// // MAXs & MINs

// 	ft_printf("|%hhu|\n",  (unsigned char)UCHAR_MAX);
// 	printf("|%hhu|\n\n",   (unsigned char)UCHAR_MAX);

// 	ft_printf("|%hu|\n",   (unsigned short)USHORT_MAX);
// 	printf("|%hu|\n\n",    (unsigned short)USHORT_MAX);

// 	ft_printf("|%u|\n",    (unsigned int)UINT_MAX);
// 	printf("|%u|\n\n",     (unsigned int)UINT_MAX);

// 	ft_printf("|%lu|\n",   (unsigned long)ULONG_MAX);
// 	printf("|%lu|\n\n",    (unsigned long)ULONG_MAX);

// 	ft_printf("|%llu|\n",  (unsigned long long)ULLONG_MAX);
// 	printf("|%llu|\n\n",   (unsigned long long)ULLONG_MAX);


// /* ++++++++++++++++++++++++++++ LENGTH HH +++++++++++++++++++++++++++ */
// /* ++++++++++++++++++++++++++++ LENGTH HH +++++++++++++++++++++++++++ */


// // Width & Precision (with no flags)

// 	ft_printf("|%10hhu|\n", (unsigned char)112);
// 	printf("|%10hhu|\n\n", (unsigned char)112);

// 	ft_printf("|%30hhu|\n", (unsigned char)112);
// 	printf("|%30hhu|\n\n", (unsigned char)112);

// 	ft_printf("|%.6hhu|\n", (unsigned char)112);
// 	printf("|%.6hhu|\n\n", (unsigned char)112);

// 	ft_printf("|%.10hhu|\n", (unsigned char)112);
// 	printf("|%.10hhu|\n\n", (unsigned char)112);

// 	ft_printf("|%25.10hhu|\n", (unsigned char)112);
// 	printf("|%25.10hhu|\n\n", (unsigned char)112);

// 	ft_printf("|%25.*hhu|\n", 10, (unsigned char)112);
// 	printf("|%25.*hhu|\n\n", 10, (unsigned char)112);

// 	ft_printf("|%25.*hhu|\n", 10, (unsigned char)112);
// 	printf("|%25.*hhu|\n\n", 10, (unsigned char)112);

// 	ft_printf("|%*.*hhu|\n", 25, 10, (unsigned char)112);
// 	printf("|%*.*hhu|\n\n", 25, 10, (unsigned char)112);

// 	ft_printf("|%*.10hhu|\n", 25, (unsigned char)112);
// 	printf("|%*.10hhu|\n\n", 25, (unsigned char)112);

// // Width & Precision (with '-')

// 	ft_printf("|%-10hhu|\n", (unsigned char)112);
// 	printf("|%-10hhu|\n\n", (unsigned char)112);

// 	ft_printf("|%-30hhu|\n", (unsigned char)112);
// 	printf("|%-30hhu|\n\n", (unsigned char)112);

// 	ft_printf("|%-.6hhu|\n", (unsigned char)112);
// 	printf("|%-.6hhu|\n\n", (unsigned char)112);

// 	ft_printf("|%-.10hhu|\n", (unsigned char)112);
// 	printf("|%-.10hhu|\n\n", (unsigned char)112);

// 	ft_printf("|%-25.10hhu|\n", (unsigned char)112);
// 	printf("|%-25.10hhu|\n\n", (unsigned char)112);

// 	ft_printf("|%-25.*hhu|\n", 10, (unsigned char)112);
// 	printf("|%-25.*hhu|\n\n", 10, (unsigned char)112);

// 	ft_printf("|%-25.*hhu|\n", 10, (unsigned char)112);
// 	printf("|%-25.*hhu|\n\n", 10, (unsigned char)112);

// 	ft_printf("|%-*.*hhu|\n", 25, 10, (unsigned char)112);
// 	printf("|%-*.*hhu|\n\n", 25, 10, (unsigned char)112);

// 	ft_printf("|%-*.10hhu|\n", 25, (unsigned char)112);
// 	printf("|%-*.10hhu|\n\n", 25, (unsigned char)112);

// // Width & Precision ('-')

// 	ft_printf("|%-10hhu|\n", (unsigned char)112);
// 	printf("|%-10hhu|\n\n", (unsigned char)112);

// 	ft_printf("|%-30hhu|\n", (unsigned char)112);
// 	printf("|%-30hhu|\n\n", (unsigned char)112);

// 	ft_printf("|%-.6hhu|\n", (unsigned char)112);
// 	printf("|%-.6hhu|\n\n", (unsigned char)112);

// 	ft_printf("|%-.10hhu|\n", (unsigned char)112);
// 	printf("|%-.10hhu|\n\n", (unsigned char)112);

// 	ft_printf("|%-25.10hhu|\n", (unsigned char)112);
// 	printf("|%-25.10hhu|\n\n", (unsigned char)112);

// 	ft_printf("|%-25.*hhu|\n", 10, (unsigned char)112);
// 	printf("|%-25.*hhu|\n\n", 10, (unsigned char)112);

// 	ft_printf("|%-25.*hhu|\n", 10, (unsigned char)112);
// 	printf("|%-25.*hhu|\n\n", 10, (unsigned char)112);

// 	ft_printf("|%-*.*hhu|\n", 25, 10, (unsigned char)112);
// 	printf("|%-*.*hhu|\n\n", 25, 10, (unsigned char)112);

// 	ft_printf("|%-*.10hhu|\n", 25, (unsigned char)112);
// 	printf("|%-*.10hhu|\n\n", 25, (unsigned char)112);

// // Width & Precision ('0')

// 	ft_printf("|%010hhu|\n", (unsigned char)112);
// 	printf("|%010hhu|\n\n", (unsigned char)112);

// 	ft_printf("|%030hhu|\n", (unsigned char)112);
// 	printf("|%030hhu|\n\n", (unsigned char)112);

// 	ft_printf("|%0.6hhu|\n", (unsigned char)112);
// 	printf("|%0.6hhu|\n\n", (unsigned char)112);

// 	ft_printf("|%0.10hhu|\n", (unsigned char)112);
// 	printf("|%0.10hhu|\n\n", (unsigned char)112);

// 	ft_printf("|%025.10hhu|\n", (unsigned char)112);
// 	printf("|%025.10hhu|\n\n", (unsigned char)112);

// 	ft_printf("|%025.*hhu|\n", 10, (unsigned char)112);
// 	printf("|%025.*hhu|\n\n", 10, (unsigned char)112);

// 	ft_printf("|%025.*hhu|\n", 10, (unsigned char)112);
// 	printf("|%025.*hhu|\n\n", 10, (unsigned char)112);

// 	ft_printf("|%0*.*hhu|\n", 25, 10, (unsigned char)112);
// 	printf("|%0*.*hhu|\n\n", 25, 10, (unsigned char)112);

// 	ft_printf("|%0*.10hhu|\n", 25, (unsigned char)112);
// 	printf("|%0*.10hhu|\n\n", 25, (unsigned char)112);


// /* ++++++++++++++++++++++++++++ LENGTH H +++++++++++++++++++++++++++ */
// /* ++++++++++++++++++++++++++++ LENGTH H +++++++++++++++++++++++++++ */

// // Width & Precision (with no flags)

// 	ft_printf("|%10hu|\n", (unsigned short)27352);
// 	printf("|%10hu|\n\n", (unsigned short)27352);

// 	ft_printf("|%30hu|\n", (unsigned short)27352);
// 	printf("|%30hu|\n\n", (unsigned short)27352);

// 	ft_printf("|%.6hu|\n", (unsigned short)27352);
// 	printf("|%.6hu|\n\n", (unsigned short)27352);

// 	ft_printf("|%.10hu|\n", (unsigned short)27352);
// 	printf("|%.10hu|\n\n", (unsigned short)27352);

// 	ft_printf("|%25.10hu|\n", (unsigned short)27352);
// 	printf("|%25.10hu|\n\n", (unsigned short)27352);

// 	ft_printf("|%25.*hu|\n", 10, (unsigned short)27352);
// 	printf("|%25.*hu|\n\n", 10, (unsigned short)27352);

// 	ft_printf("|%25.*hu|\n", 10, (unsigned short)27352);
// 	printf("|%25.*hu|\n\n", 10, (unsigned short)27352);

// 	ft_printf("|%*.*hu|\n", 25, 10, (unsigned short)27352);
// 	printf("|%*.*hu|\n\n", 25, 10, (unsigned short)27352);

// 	ft_printf("|%*.10hu|\n", 25, (unsigned short)27352);
// 	printf("|%*.10hu|\n\n", 25, (unsigned short)27352);

// // Width & Precision (with '-')

// 	ft_printf("|%-10hu|\n", (unsigned short)27352);
// 	printf("|%-10hu|\n\n", (unsigned short)27352);

// 	ft_printf("|%-30hu|\n", (unsigned short)27352);
// 	printf("|%-30hu|\n\n", (unsigned short)27352);

// 	ft_printf("|%-.6hu|\n", (unsigned short)27352);
// 	printf("|%-.6hu|\n\n", (unsigned short)27352);

// 	ft_printf("|%-.10hu|\n", (unsigned short)27352);
// 	printf("|%-.10hu|\n\n", (unsigned short)27352);

// 	ft_printf("|%-25.10hu|\n", (unsigned short)27352);
// 	printf("|%-25.10hu|\n\n", (unsigned short)27352);

// 	ft_printf("|%-25.*hu|\n", 10, (unsigned short)27352);
// 	printf("|%-25.*hu|\n\n", 10, (unsigned short)27352);

// 	ft_printf("|%-25.*hu|\n", 10, (unsigned short)27352);
// 	printf("|%-25.*hu|\n\n", 10, (unsigned short)27352);

// 	ft_printf("|%-*.*hu|\n", 25, 10, (unsigned short)27352);
// 	printf("|%-*.*hu|\n\n", 25, 10, (unsigned short)27352);

// 	ft_printf("|%-*.10hu|\n", 25, (unsigned short)27352);
// 	printf("|%-*.10hu|\n\n", 25, (unsigned short)27352);

// // Width & Precision ('0')

// 	ft_printf("|%010hu|\n", (unsigned short)27352);
// 	printf("|%010hu|\n\n", (unsigned short)27352);

// 	ft_printf("|%030hu|\n", (unsigned short)27352);
// 	printf("|%030hu|\n\n", (unsigned short)27352);

// 	ft_printf("|%0.6hu|\n", (unsigned short)27352);
// 	printf("|%0.6hu|\n\n", (unsigned short)27352);

// 	ft_printf("|%0.10hu|\n", (unsigned short)27352);
// 	printf("|%0.10hu|\n\n", (unsigned short)27352);

// 	ft_printf("|%025.10hu|\n", (unsigned short)27352);
// 	printf("|%025.10hu|\n\n", (unsigned short)27352);

// 	ft_printf("|%025.*hu|\n", 10, (unsigned short)27352);
// 	printf("|%025.*hu|\n\n", 10, (unsigned short)27352);

// 	ft_printf("|%025.*hu|\n", 10, (unsigned short)27352);
// 	printf("|%025.*hu|\n\n", 10, (unsigned short)27352);

// 	ft_printf("|%0*.*hu|\n", 25, 10, (unsigned short)27352);
// 	printf("|%0*.*hu|\n\n", 25, 10, (unsigned short)27352);

// 	ft_printf("|%0*.10hu|\n", 25, (unsigned short)27352);
// 	printf("|%0*.10hu|\n\n", 25, (unsigned short)27352);


// /* ++++++++++++++++++++++++++++ LENGTH DEFAULT +++++++++++++++++++++++++++ */
// /* ++++++++++++++++++++++++++++ LENGTH DEFAULT +++++++++++++++++++++++++++ */


// // Width & Precision (with no flags)

// 	ft_printf("|%10u|\n", (unsigned int)12345);
// 	printf("|%10u|\n\n", (unsigned int)12345);

// 	ft_printf("|%30u|\n", (unsigned int)12345);
// 	printf("|%30u|\n\n", (unsigned int)12345);

// 	ft_printf("|%.6u|\n", (unsigned int)12345);
// 	printf("|%.6u|\n\n", (unsigned int)12345);

// 	ft_printf("|%.10u|\n", (unsigned int)12345);
// 	printf("|%.10u|\n\n", (unsigned int)12345);

// 	ft_printf("|%25.10u|\n", (unsigned int)12345);
// 	printf("|%25.10u|\n\n", (unsigned int)12345);

// 	ft_printf("|%25.*u|\n", 10, (unsigned int)12345);
// 	printf("|%25.*u|\n\n", 10, (unsigned int)12345);

// 	ft_printf("|%25.*u|\n", 10, (unsigned int)12345);
// 	printf("|%25.*u|\n\n", 10, (unsigned int)12345);

// 	ft_printf("|%*.*u|\n", 25, 10, (unsigned int)12345);
// 	printf("|%*.*u|\n\n", 25, 10, (unsigned int)12345);

// 	ft_printf("|%*.10u|\n", 25, (unsigned int)12345);
// 	printf("|%*.10u|\n\n", 25, (unsigned int)12345);

// // Width & Precision (with '-')

// 	ft_printf("|%-10u|\n", (unsigned int)12345);
// 	printf("|%-10u|\n\n", (unsigned int)12345);

// 	ft_printf("|%-30u|\n", (unsigned int)12345);
// 	printf("|%-30u|\n\n", (unsigned int)12345);

// 	ft_printf("|%-.6u|\n", (unsigned int)12345);
// 	printf("|%-.6u|\n\n", (unsigned int)12345);

// 	ft_printf("|%-.10u|\n", (unsigned int)12345);
// 	printf("|%-.10u|\n\n", (unsigned int)12345);

// 	ft_printf("|%-25.10u|\n", (unsigned int)12345);
// 	printf("|%-25.10u|\n\n", (unsigned int)12345);

// 	ft_printf("|%-25.*u|\n", 10, (unsigned int)12345);
// 	printf("|%-25.*u|\n\n", 10, (unsigned int)12345);

// 	ft_printf("|%-25.*u|\n", 10, (unsigned int)12345);
// 	printf("|%-25.*u|\n\n", 10, (unsigned int)12345);

// 	ft_printf("|%-*.*u|\n", 25, 10, (unsigned int)12345);
// 	printf("|%-*.*u|\n\n", 25, 10, (unsigned int)12345);

// 	ft_printf("|%-*.10u|\n", 25, (unsigned int)12345);
// 	printf("|%-*.10u|\n\n", 25, (unsigned int)12345);

// // Width & Precision ('0')

// 	ft_printf("|%010u|\n", (unsigned int)12345);
// 	printf("|%010u|\n\n", (unsigned int)12345);

// 	ft_printf("|%030u|\n", (unsigned int)12345);
// 	printf("|%030u|\n\n", (unsigned int)12345);

// 	ft_printf("|%0.6u|\n", (unsigned int)12345);
// 	printf("|%0.6u|\n\n", (unsigned int)12345);

// 	ft_printf("|%0.10u|\n", (unsigned int)12345);
// 	printf("|%0.10u|\n\n", (unsigned int)12345);

// 	ft_printf("|%025.10u|\n", (unsigned int)12345);
// 	printf("|%025.10u|\n\n", (unsigned int)12345);

// 	ft_printf("|%025.*u|\n", 10, (unsigned int)12345);
// 	printf("|%025.*u|\n\n", 10, (unsigned int)12345);

// 	ft_printf("|%025.*u|\n", 10, (unsigned int)12345);
// 	printf("|%025.*u|\n\n", 10, (unsigned int)12345);

// 	ft_printf("|%0*.*u|\n", 25, 10, (unsigned int)12345);
// 	printf("|%0*.*u|\n\n", 25, 10, (unsigned int)12345);

// 	ft_printf("|%0*.10u|\n", 25, (unsigned int)12345);
// 	printf("|%0*.10u|\n\n", 25, (unsigned int)12345);


// /* ++++++++++++++++++++++++++++ LENGTH L +++++++++++++++++++++++++++ */
// /* ++++++++++++++++++++++++++++ LENGTH L +++++++++++++++++++++++++++ */


// // Width & Precision (with no flags)

// 	ft_printf("|%10lu|\n", (unsigned long)52728623);
// 	printf("|%10lu|\n\n", (unsigned long)52728623);

// 	ft_printf("|%30lu|\n", (unsigned long)52728623);
// 	printf("|%30lu|\n\n", (unsigned long)52728623);

// 	ft_printf("|%.6lu|\n", (unsigned long)52728623);
// 	printf("|%.6lu|\n\n", (unsigned long)52728623);

// 	ft_printf("|%.10lu|\n", (unsigned long)52728623);
// 	printf("|%.10lu|\n\n", (unsigned long)52728623);

// 	ft_printf("|%40.10lu|\n", (unsigned long)52728623);
// 	printf("|%40.10lu|\n\n", (unsigned long)52728623);

// 	ft_printf("|%40.*lu|\n", 10, (unsigned long)52728623);
// 	printf("|%40.*lu|\n\n", 10, (unsigned long)52728623);

// 	ft_printf("|%40.*lu|\n", 10, (unsigned long)52728623);
// 	printf("|%40.*lu|\n\n", 10, (unsigned long)52728623);

// 	ft_printf("|%*.*lu|\n", 40, 10, (unsigned long)52728623);
// 	printf("|%*.*lu|\n\n", 40, 10, (unsigned long)52728623);

// 	ft_printf("|%*.10lu|\n", 40, (unsigned long)52728623);
// 	printf("|%*.10lu|\n\n", 40, (unsigned long)52728623);

// // Width & Precision (with '-')

// 	ft_printf("|%-10lu|\n", (unsigned long)52728623);
// 	printf("|%-10lu|\n\n", (unsigned long)52728623);

// 	ft_printf("|%-30lu|\n", (unsigned long)52728623);
// 	printf("|%-30lu|\n\n", (unsigned long)52728623);

// 	ft_printf("|%-.6lu|\n", (unsigned long)52728623);
// 	printf("|%-.6lu|\n\n", (unsigned long)52728623);

// 	ft_printf("|%-.10lu|\n", (unsigned long)52728623);
// 	printf("|%-.10lu|\n\n", (unsigned long)52728623);

// 	ft_printf("|%-40.10lu|\n", (unsigned long)52728623);
// 	printf("|%-40.10lu|\n\n", (unsigned long)52728623);

// 	ft_printf("|%-40.*lu|\n", 10, (unsigned long)52728623);
// 	printf("|%-40.*lu|\n\n", 10, (unsigned long)52728623);

// 	ft_printf("|%-40.*lu|\n", 10, (unsigned long)52728623);
// 	printf("|%-40.*lu|\n\n", 10, (unsigned long)52728623);

// 	ft_printf("|%-*.*lu|\n", 40, 10, (unsigned long)52728623);
// 	printf("|%-*.*lu|\n\n", 40, 10, (unsigned long)52728623);

// 	ft_printf("|%-*.10lu|\n", 40, (unsigned long)52728623);
// 	printf("|%-*.10lu|\n\n", 40, (unsigned long)52728623);

// // Width & Precision ('0')

// 	ft_printf("|%010lu|\n", (unsigned long)52728623);
// 	printf("|%010lu|\n\n", (unsigned long)52728623);

// 	ft_printf("|%030lu|\n", (unsigned long)52728623);
// 	printf("|%030lu|\n\n", (unsigned long)52728623);

// 	ft_printf("|%0.6lu|\n", (unsigned long)52728623);
// 	printf("|%0.6lu|\n\n", (unsigned long)52728623);

// 	ft_printf("|%0.10lu|\n", (unsigned long)52728623);
// 	printf("|%0.10lu|\n\n", (unsigned long)52728623);

// 	ft_printf("|%040.10lu|\n", (unsigned long)52728623);
// 	printf("|%040.10lu|\n\n", (unsigned long)52728623);

// 	ft_printf("|%040.*lu|\n", 10, (unsigned long)52728623);
// 	printf("|%040.*lu|\n\n", 10, (unsigned long)52728623);

// 	ft_printf("|%040.*lu|\n", 10, (unsigned long)52728623);
// 	printf("|%040.*lu|\n\n", 10, (unsigned long)52728623);

// 	ft_printf("|%0*.*lu|\n", 40, 10, (unsigned long)52728623);
// 	printf("|%0*.*lu|\n\n", 40, 10, (unsigned long)52728623);

// 	ft_printf("|%0*.10lu|\n", 40, (unsigned long)52728623);
// 	printf("|%0*.10lu|\n\n", 40, (unsigned long)52728623);


// /* ++++++++++++++++++++++++++++ LENGTH LL +++++++++++++++++++++++++++ */
// /* ++++++++++++++++++++++++++++ LENGTH LL +++++++++++++++++++++++++++ */


// // Width & Precision (with no flags)

// 	ft_printf("|%10llu|\n", (long long int)27323472342);
// 	printf("|%10llu|\n\n", (long long int)27323472342);

// 	ft_printf("|%30llu|\n", (long long int)27323472342);
// 	printf("|%30llu|\n\n", (long long int)27323472342);

// 	ft_printf("|%.6llu|\n", (long long int)27323472342);
// 	printf("|%.6llu|\n\n", (long long int)27323472342);

// 	ft_printf("|%.10llu|\n", (long long int)27323472342);
// 	printf("|%.10llu|\n\n", (long long int)27323472342);

// 	ft_printf("|%25.10llu|\n", (long long int)27323472342);
// 	printf("|%25.10llu|\n\n", (long long int)27323472342);

// 	ft_printf("|%25.*llu|\n", 60, (long long int)27323472342);
// 	printf("|%25.*llu|\n\n", 60, (long long int)27323472342);

// 	ft_printf("|%25.*llu|\n", 60, (long long int)27323472342);
// 	printf("|%25.*llu|\n\n", 60, (long long int)27323472342);

// 	ft_printf("|%*.*llu|\n", 50, 60, (long long int)27323472342);
// 	printf("|%*.*llu|\n\n", 50, 60, (long long int)27323472342);

// 	ft_printf("|%*.60llu|\n", 50, (long long int)27323472342);
// 	printf("|%*.60llu|\n\n", 50, (long long int)27323472342);

// // Width & Precision (with '-')

// 	ft_printf("|%-60llu|\n", (long long int)27323472342);
// 	printf("|%-60llu|\n\n", (long long int)27323472342);

// 	ft_printf("|%-30llu|\n", (long long int)27323472342);
// 	printf("|%-30llu|\n\n", (long long int)27323472342);

// 	ft_printf("|%-.6llu|\n", (long long int)27323472342);
// 	printf("|%-.6llu|\n\n", (long long int)27323472342);

// 	ft_printf("|%-.60llu|\n", (long long int)27323472342);
// 	printf("|%-.60llu|\n\n", (long long int)27323472342);

// 	ft_printf("|%-50.60llu|\n", (long long int)27323472342);
// 	printf("|%-50.60llu|\n\n", (long long int)27323472342);

// 	ft_printf("|%-50.*llu|\n", 60, (long long int)27323472342);
// 	printf("|%-50.*llu|\n\n", 60, (long long int)27323472342);

// 	ft_printf("|%-50.*llu|\n", 60, (long long int)27323472342);
// 	printf("|%-50.*llu|\n\n", 60, (long long int)27323472342);

// 	ft_printf("|%-*.*llu|\n", 50, 60, (long long int)27323472342);
// 	printf("|%-*.*llu|\n\n", 50, 60, (long long int)27323472342);

// 	ft_printf("|%-*.60llu|\n", 50, (long long int)27323472342);
// 	printf("|%-*.60llu|\n\n", 50, (long long int)27323472342);

// // Width & Precision ('0')

// 	ft_printf("|%060llu|\n", (long long int)27323472342);
// 	printf("|%060llu|\n\n", (long long int)27323472342);

// 	ft_printf("|%030llu|\n", (long long int)27323472342);
// 	printf("|%030llu|\n\n", (long long int)27323472342);

// 	ft_printf("|%0.6llu|\n", (long long int)27323472342);
// 	printf("|%0.6llu|\n\n", (long long int)27323472342);

// 	ft_printf("|%0.60llu|\n", (long long int)27323472342);
// 	printf("|%0.60llu|\n\n", (long long int)27323472342);

// 	ft_printf("|%050.60llu|\n", (long long int)27323472342);
// 	printf("|%050.60llu|\n\n", (long long int)27323472342);

// 	ft_printf("|%050.*llu|\n", 60, (long long int)27323472342);
// 	printf("|%050.*llu|\n\n", 60, (long long int)27323472342);

// 	ft_printf("|%050.*llu|\n", 60, (long long int)27323472342);
// 	printf("|%050.*llu|\n\n", 60, (long long int)27323472342);

// 	ft_printf("|%0*.*llu|\n", 50, 60, (long long int)27323472342);
// 	printf("|%0*.*llu|\n\n", 50, 60, (long long int)27323472342);

// 	ft_printf("|%0*.60llu|\n", 50, (long long int)27323472342);
// 	printf("|%0*.60llu|\n\n", 50, (long long int)27323472342);


/* — — — — – – – – – – – – – – – – – – – – – – – – – –  */

/* %o SPECIFIER TESTS */

/**
 * Only takes the following flags & fields:
 *
**
**             Flags: '-', '+', ' ', '0'
**             Width: defined or '*'
**             Precision: defined or '*'
**             Length: 'L'
 *
 */

// MAXs & MINs --------------------------------------------- */

	// ft_printf("|%f|\n",  (double)127.0);
	// printf("|%f|\n\n",   (double)127.0);

	// ft_printf("|%f|\n",   (double)USHORT_MAX);
	// printf("|%f|\n\n",    (double)USHORT_MAX);

	// ft_printf("|%f|\n",    (double)UINT_MAX);
	// printf("|%f|\n\n",     (double)UINT_MAX);

	// ft_printf("|%f|\n",   (double)ULONG_MAX);
	// printf("|%f|\n\n",    (double)ULONG_MAX);

	// ft_printf("|%f|\n",  (double)ULLONG_MAX);
	// printf("|%f|\n\n",   (double)ULLONG_MAX);

	// ft_printf("|%f|\n",  (double)CHAR_MIN);
	// printf("|%f|\n\n",   (double)CHAR_MIN);

	// ft_printf("|%f|\n",   (double)SHORT_MIN);
	// printf("|%f|\n\n",    (double)SHORT_MIN);

	// ft_printf("|%f|\n",    (double)INT_MIN);
	// printf("|%f|\n\n",     (double)INT_MIN);

	// ft_printf("|%f|\n",   (double)LONG_MIN);
	// printf("|%f|\n\n",    (double)LONG_MIN);

	// ft_printf("|%f|\n",  (double)LLONG_MIN);
	// printf("|%f|\n\n",   (double)LLONG_MIN);

// /* --------------------------------------------- */

	// ft_printf("|%f|\n", 0.2323);
	// printf("|%f|\n\n", 0.2323);

	// ft_printf("|%f|\n", 0.2323);
	// printf("|%f|\n\n", 0.2323);

	// ft_printf("|%f|\n", 0.2323);
	// printf("|%f|\n\n", 0.2323);


/* — — — — – – – – – – – – – – – – – – – – – – – – – –  */

/* %b SPECIFIER TESTS */

/**
 * Only takes the following flags & fields:
 *
 *
 *             Flags: '-', '+', ' ', '0', '#'
 *             Width: defined or '*'
 *             Precision: defined or '*'
 *             Length: 'hh', 'h', 'l', 'll'
 *
 */

// /* --------------------------------------------- */

// 	ft_printf("|+%.32b|\n", INT_MAX);
// 	ft_printf("|%b|\n\n", INT_MIN);

// 	ft_printf("|+%.*b|\n", 32, INT_MAX);
// 	ft_printf("|%b|\n\n", INT_MIN);

// 	ft_printf("|% b|\n", 90);
// 	ft_printf("|%b|\n\n", -90);

// 	ft_printf("|% b|\n", 100);
// 	ft_printf("|%b|\n\n", -100);

// /* --------------------------------------------- */

// 	ft_printf("|%+#.*b|\n", 32, INT_MAX);
// 	ft_printf("|%#b|\n\n", INT_MIN);

// 	ft_printf("|%+#.32b|\n", INT_MAX);
// 	ft_printf("|%#b|\n\n", INT_MIN);

// 	ft_printf("|% #b|\n", 90);
// 	ft_printf("|%#b|\n\n", -90);

// 	ft_printf("|% #b|\n", 100);
// 	ft_printf("|%#b|\n\n", -100);

// /* --------------------------------------------- */

// 	ft_printf("|%+#60.*b|\n", 32, INT_MAX);
// 	ft_printf("|%#60b|\n\n", INT_MIN);

// 	ft_printf("|%+#60.32b|\n", INT_MAX);
// 	ft_printf("|%#60b|\n\n", INT_MIN);

// 	ft_printf("|% #20b|\n", 90);
// 	ft_printf("|%#20b|\n\n", -90);

// 	ft_printf("|% #20b|\n", 100);
// 	ft_printf("|%#20b|\n\n", -100);


/* — — — — – – – – – – – – – – – – – – – – – – – – – –  */

/* %o SPECIFIER TESTS */

/**
 * Only takes the following flags & fields:
 *
**
**             Flags: '-', '+', ' ', '0', '#'
**             Width: defined or '*'
**             Precision: defined or '*'
**             Length: 'hh', 'h', 'l', 'll'
 *
 */

	// ft_printf("|%p|\n", (void *)0);
	// printf("|%p|\n\n", (void *)0);

/* — — — — – – – – – – – – – – – – – – – – – – – – – –  */

/* %x SPECIFIER TESTS */

/**
 * Only takes the following flags & fields:
 *
**
**             Flags: '-', '+', ' ', '0', '#'
**             Width: defined or '*'
**             Precision: defined or '*'
**             Length: 'hh', 'h', 'l', 'll'
 *
 */

	// ft_printf("|%p|\n", (void *)0);
	// printf("|%p|\n\n", (void *)0);

/* — — — — – – – – – – – – – – – – – – – – – – – – – –  */

/* %X SPECIFIER TESTS */

/**
 * Only takes the following flags & fields:
 *
**
**             Flags: '-', '+', ' ', '0', '#'
**             Width: defined or '*'
**             Precision: defined or '*'
**             Length: 'hh', 'h', 'l', 'll'
 *
 */

	// ft_printf("|%X|\n",  (signed char)CHAR_MAX);
	// printf("|%X|\n\n",   (signed char)CHAR_MAX);
	// ft_printf("|%X|\n",  (signed char)CHAR_MIN);
	// printf("|%X|\n\n",   (signed char)CHAR_MIN);

	// ft_printf("|%X|\n",   (short int)SHORT_MAX);
	// printf("|%X|\n\n",    (short int)SHORT_MAX);
	// ft_printf("|%X|\n",   (short int)SHORT_MIN);
	// printf("|%X|\n\n",    (short int)SHORT_MIN);

	// ft_printf("|%X|\n",    (int)INT_MAX);
	// printf("|%X|\n\n",     (int)INT_MAX);
	// ft_printf("|%X|\n",    (int)INT_MIN);
	// printf("|%X|\n\n",     (int)INT_MIN);

	// ft_printf("|%X|\n",   (long int)LONG_MAX);
	// printf("|%X|\n\n",    (long int)LONG_MAX);
	// ft_printf("|%X|\n",   (long int)-9223372036854775807);
	// printf("|%X|\n\n",    (long int)-9223372036854775807);

	// ft_printf("|%X|\n",  (long long)LLONG_MAX);
	// printf("|%X|\n\n",   (long long)LLONG_MAX);

/* — — — — – – – – – – – – – – – – – – – – – – – – – –  */


	// ft_printf("|%X|\n",    (int)100);
	// printf("|%X|\n\n",     (int)100);

	// ft_printf("|%X|\n",    (int)90);
	// printf("|%X|\n\n",     (int)90);

	// ft_printf("|%20X|\n",    (int)90);
	// printf("|%20X|\n\n",     (int)90);

	// ft_printf("|%.20X|\n",    (int)90);
	// printf("|%.20X|\n\n",     (int)90);

	// ft_printf("|%0.15X|\n",    (int)90);
	// printf("|%0.15X|\n\n",     (int)90);

	// ft_printf("|%.20X|\n",    (int)90);
	// printf("|%.20X|\n\n",     (int)90);


/* — — — — – – – – – – – – – – – – – – – – – – – – – –  */

/* %p SPECIFIER TESTS */

/**
 * Only takes the following flags & fields:
 *
 * 		– Flag: '-',
 *      - Width
 *
 */

	// ft_printf("|%*p|\n", 40, (void *)NULL);
	// printf("|%*p|\n\n", 40, (void *)NULL);

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

/* — — — — – – – – – – – – – – – – – – – – – – – – – –  */

/* {styles} SPECIFIER TESTS */

	// ft_printf("|%*p|\n", 40, (void *)NULL);
	// printf("|%*p|\n\n", 40, (void *)NULL);

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

/* — — — — – – – – – – – – – – – – – – – – – – – – – –  */

	// ft_printf("%s{red underlined bglyellow}", "James");
	// ft_printf("%s{red bgwhite underlined} said %s{lyellow} %s{bgred}", "James", "whatt", "???");

	// ft_printf("%r{lyellow bgred}%p{bgred}%s{bgred}\n", " DANGER ZONE ", NULL, " ! ");

	ft_printf("%s{dim italic}\n", "/*\n**    NAME\n**         style_handler -- formatted style conversion\n**\n**    SYNOPSIS\n**         #include <libft.h>\n**\n**         t_char	*\n**         style_handler(t_format format, t_char *string);\n**\n**    PARAMETERS\n**\n**         t_format format         Structure containing the variable\n**                                 and information about how it must\n**                                 be formatted.\n**\n**         t_char *string          Output string that we want to style.\n**\n**    DESCRIPTION\n**         Handles the 'style' specification of a formatted string.\n**\n**         Goes through the styles parsed in the format string and\n**         prepends them as their corresponding ANSI code to the output\n**         string.\n**\n**         After having applied all styles, a reset ANSI code is appended\n**         to the end of the output string; this is so that the styling is\n**         not applied to characters that might come after in the output.\n**\n**    RETURN VALUES\n**         If style(s) were specified and successfully applied, the output\n**         string all styled up is returned; otherwise the output string\n**         untouched is returned.\n*/");

	// ft_printf("%s{red inverted}", "hello world");

	// ft_printf("it %s{bglgreen lred inverted}\n", " works! ");

	(void)ac;
	(void)av;

	return (0);
}
