/*
 *
 * TEST MAIN
 *
 */

#include "../ft_putchar.c"
#include "../ft_putstr.c"
#include "../ft_putstrtab.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int		main(int ac, char *av[])
{
	if (ac < 2)
	{
		printf("Usage: ./a str1 str2 str3 ... \n");
		return (1);
	}

	char	**tab = (char **)malloc(sizeof(char *) * ac);
	int		i;

	i = 0;
	while (av[++i])
		tab[i - 1] = av[i];
	tab[i - 1] = NULL;

	ft_putstrtab(tab, '\n');

	// while (*tab)
	// 	printf("%s\n", *tab++);

	return (0);
}
