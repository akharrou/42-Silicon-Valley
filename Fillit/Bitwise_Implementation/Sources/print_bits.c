

/*
 *
 * TEST MAIN
 *
 */

#include "libft/Stdio/ft_putnbr_base.c"
#include "libft/Stdio/ft_putchar.c"
#include "libft/String/ft_strlen.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

int		main(int ac, char *av[])
{
	(void)ac;

	// char num1 = atoi(av[1]);
	// short num2 = atoi(av[2]);

	// ft_putnbr_base(num1 ^ num2, "01");

	char map[2];

	bzero(map, sizeof(map));
	*map ^= atoi(av[1]);

	// ft_putnbr_base(*map, "01");
	printf("%ul\n%ul\n", map[0], map[1]);
	printf("\n");
	// ft_putnbr_base(*map, "01");


	return (0);
}



void	print_bits(ptr, size_t bufsiz)
{

}
