/*
 *
 * TEST MAIN
 *
 */

#include "../ft_strlen.c"
#include "../ft_putchar.c"
#include "../ft_putnbr_base.c"
#include "../ft_putbyte.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int		main(int ac, char *av[])
{
	(void)ac;
	(void)av;

	ft_putbyte('\t');
	ft_putbyte('\n');
	ft_putbyte('\r');
	ft_putbyte('\a');
	ft_putbyte('\b');

	return (0);
}
