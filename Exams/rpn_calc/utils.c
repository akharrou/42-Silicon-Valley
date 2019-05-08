
/* Utils Module */

#include <stdlib.h>

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
 
char	*ft_strdup_range(char *str, int index, int end)
{
	char	*new_str;
	int		i;

	new_str = (char *)malloc(end - index + 1);
	i = 0;
	while (index < end)
	{
		new_str[i] = str[index];
		index++;
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

int		ft_issep(char c, char *seperators)
{
	while (*seperators)
	{
		if (c == *seperators)
			return (1);
		seperators++;
	}
	return (0);
}

int		ft_wcount(char *s)
{
	int		wcount;

	wcount = 0;
	while (*s)
	{
		while (*s && ft_issep(*s, "\t\n "))
			s++;
		while (*s && !ft_issep(*s, "\t\n "))
			s++;
		wcount++;
		while (*s && ft_issep(*s, "\t\n "))
			s++;
	}
	return (wcount);
}

char	**ft_split(char *str)
{
	int 	i;
	int 	j;
	int 	k;
	int 	wcount;
	char 	**strtab;

	if (!(strtab = (char **)malloc(sizeof(char *) * ((wcount = ft_wcount(str)) + 1))))
		return (NULL);
	i = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] && ft_issep(str[i], "\t\n "))
			i++;
		j = i;
		while (str[j] && !ft_issep(str[j], "\t\n "))
			j++;
		strtab[k++] = ft_strdup_range(str, i, j);
		i = j;
		while (str[i] && ft_issep(str[i], "\t\n "))
			i++;
	}
	strtab[k] = 0;
	return (strtab);
}
