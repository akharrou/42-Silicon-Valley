

// /*
//  *
//  * TEST MAIN
//  *
//  */

// #include "libft/Stdio/ft_putnbr_base.c"
// #include "libft/Stdio/ft_putchar.c"
// #include "libft/String/ft_strlen.c"

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>
// #include <math.h>

// int		main(int ac, char *av[])
// {
// 	(void)ac;

// 	// char num1 = atoi(av[1]);
// 	// short num2 = atoi(av[2]);

// 	// ft_putnbr_base(num1 ^ num2, "01");

// 	char map[2];

// 	bzero(map, sizeof(map));
// 	(int)*map ^= (int)atoi(av[1]);

// 	// ft_putnbr_base(*map, "01");
// 	printf("%ul\n%ul\n", map[0], map[1]);
// 	printf("\n");
// 	// ft_putnbr_base(*map, "01");


// 	return (0);
// }



// void	print_bits(ptr, size_t bufsiz)
// {

// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 21:38:51 by kmira             #+#    #+#             */
/*   Updated: 2019/03/17 23:50:38 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <strings.h>

#include "libft/Includes/libft.h"
#include "libft/Math/ft_powll.c"
#include "libft/Stdio/ft_putbits.c"

void	print_bit_board(uint16_t *matrix, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putbits((uint16_t) matrix[i], size);
		i++;
	}
}

int		main(int ac, char *av[])
{
	uint16_t matrix[18];
	bzero(matrix, sizeof(matrix));
	unsigned long long a = 3758104576U;
	// atoll(av[1]);

	printf("\n[PIECE]:\n");
	ft_putbits(a, 64);


	printf("\n[BOARD]:\n");
	*(uint64_t *)(&matrix[0]) = *(uint64_t *)(&matrix[0]) ^ a;
	print_bit_board(matrix, 16);

	printf("\n[NEW BOARD]:\n");
	*(uint64_t *)(&matrix[0]) = *(uint64_t *)(&matrix[0]) ^ a;
	print_bit_board(matrix, 16);

	printf("\n[NEW BOARD]:\n");
	*(uint64_t *)(&matrix[0]) = *(uint64_t *)(&matrix[0]) ^ (a >> 1);
	print_bit_board(matrix, 16);
	printf("\n");


	(void)ac;
	(void)av;

	return (1);
}


// 18446744073709551615

// 9223512777564356608U

// 1000 0000 0000 0000
// 1000 0000 0000 0000
// 1100 0000 0000 0000
// 0000 0000 0000 0000

// 1111000000000000000000000000000000000000000000000000000000000000

// 15U

// 0000 0000 0000 0000
// 0000 0000 0000 0000
// 0000 0000 0000 0000
// 0000 0000 0000 1111

// 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 1111



// 983040

// 0000 0000 0000 0000
// 0000 0000 0000 0000
// 0000 0000 0000 1111
// 0000 0000 0000 0000

// 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 1111 0000 0000 0000 0000

// 0000000000000000000000000000000000000000000011110000000000000000





// 9223512776490647552U

// 1000 0000 0000 0000
// 1000 0000 0000 0000
// 1000 0000 0000 0000
// 1000 0000 0000 0000

// 1000 0000 0000 0000 1000 0000 0000 0000 1000 0000 0000 0000 1000 0000 0000 0000

// 0000000000000000000000000000000000000000000011110000000000000000



// To represent a piece correctly in a 64bit integer:



// .#..
// .###
// ....
// ....

// 1000 0000 0000 0000
// 1110 0000 0000 0000
// 0000 0000 0000 0000
// 0000 0000 0000 0000

// 0000 0000 0000 0000
// 0000 0000 0000 0000
// 1110 0000 0000 0000
// 1000 0000 0000 0000


// 0000000000000000000000000000000001110000000000000100000000000000




// 0000000000000000000000000000000000000000000000001111000000000000 == 61440
