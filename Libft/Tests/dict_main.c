/*
 *
 * TEST MAIN
 *
 */

#include "../libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int		main(int ac, char *av[])
{
	if (ac != 1)
	{
		printf("Usage: ./a\n");
		return (1);
	}

	(void)ac;
	(void)av;

	t_dict *students;

	dict_insert(&students, "James", ft_strdup("Senior"), 10);
	dict_insert(&students, "Tina", ft_strdup("Junior"), 0);
	dict_insert(&students, "Albert", ft_strdup("Sophmore"), 0);

	printf("%s\n", (char*)dict_getvalue(students, "James"));
	printf("%s\n", (char*)dict_getvalue(students, "Tina"));
	printf("%s\n", (char*)dict_getvalue(students, "Albert"));

	printf("%i\n", dict_remove(&students, "James"));
	printf("%i\n", dict_remove(&students, "Jina"));

	dict_clear(&students);

	printf("%p\n", students);

	return (0);
}
