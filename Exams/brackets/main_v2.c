
/* Assignement Name: brackets */

#include <unistd.h>

char brackets[4][3] = {"()", "[]", "{}", "\0"};

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		correctly_bracketed(char *s, unsigned int *i, char matching_bracket)
{
	unsigned int j;

	while (s[*i])
	{
		// I - Check if the current character is the matching bracket
		if (s[*i] == matching_bracket)
			return (1);

		// II - Check if the current character is a bracket
		j = 0;
		while (brackets[j][0])
		{

			// A - Check if its an opening bracket of type 'x'
			if (s[*i] == brackets[j][0])
			{
				(*i)++;
				if (!correctly_bracketed(s, i, brackets[j][1]))
					return (0);
				else
					break ;
			}

			// B - Check if its a closing bracket of type 'x'
			if (s[*i] == brackets[j][1])
				return (0);

			// C - Try the next type of bracket
			j++;
		}

		// III - Else go to the next character
		(*i)++;
	}

	// If the string had an opening bracket that was not closed
	if (matching_bracket != '\0')
		return (0);

	// Returns 1 upon success.
	return (1);
}

int		main(int ac, char *av[])
{
	int i;
	unsigned int start;

	if (ac < 2)
	{
		ft_putstr("\n");
		return (0);
	}

	i = 1;
	while (i < ac)
	{
		start = 0;
		if (correctly_bracketed(av[i], &start, '\0'))
			ft_putstr("OK\n");
		else
			ft_putstr("Error\n");
		i++;
	}
	return (0);
}
