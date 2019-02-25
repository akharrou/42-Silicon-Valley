/*
 *
 * TEST MAIN
 *
 */

#include "../ft_putchar.c"
#include "../ft_strlen.c"
#include "../ft_putnbr_base.c"
#include "../ft_putbytes.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int		main(int ac, char *av[])
{
	(void)ac;
	(void)av;

	ft_putbytes("\t\n\r\a\b");

	return (0);
}
