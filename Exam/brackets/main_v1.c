
/* Assignement Name: brackets */

#include <unistd.h>

char brackets[4][3] = {"()", "[]", "{}", "\0"};

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		find_matching_bracket(char *s, unsigned int *index, char matching_bracket)
{
	unsigned int j;

	while (s[*index])
	{
		if (s[*index] == matching_bracket)
			return (1);
		j = 0;
		while (brackets[j][0])
		{
			if (s[*index] == brackets[j][0])
			{
				(*index)++;
				if (!find_matching_bracket(s, index, brackets[j][1]))
					return (0);
				else
					break ;
			}
			if (s[*index] == brackets[j][1])
				return (0);
			j++;
		}
		(*index)++;
	}
	return (0);
}

int		correctly_bracketed(char *s)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (brackets[j][0])
		{
			if (s[i] == brackets[j][0])
			{
				i++;
				if (!find_matching_bracket(s, &i, brackets[j][1]))
					return (0);
				else
					break ;
			}
			if (s[i] == brackets[j][1])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		main(int ac, char *av[])
{
	int i;
	if (ac < 2)
	{
		ft_putstr("\n");
		return (0);
	}

	i = 1;
	while (i < ac)
	{
		if (correctly_bracketed(av[i]))
			ft_putstr("OK\n");
		else
			ft_putstr("Error\n");
		i++;
	}
	return (0);
}
