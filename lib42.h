/*

                 // * * * * * * * * * * * * * * * * * * * * //
                 // ======================================= //
                 //               42 LIBRARY                //
                 // ======================================= //
                 // * * * * * * * * * * * * * * * * * * * * //

                                 Welcome Home !

*/



// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
// ======================================================================= //
//                                  DEFINES                                //
// ======================================================================= //
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define ISDIGIT(c) (c >= '0' && c <= '9')
#define ISPRINT(c) (c >= 32 && c <= 126)
#define ISBLANK(c) (c <= 32)



// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
// ======================================================================= //
//                                  stdio.h                                //
// ======================================================================= //
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //



/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
 * DEPENDENCIES:	write() , <unistd.h>
 *
 * DESCRIPTION:		Prints a character to screen.
 *
 * RETURN VALUES:	none.
 *
 * SEARCH TAGS:		ft putchar
 — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */
void	ft_putchar(char c)
{
	write(1, &c, 1);
}


/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
 * DEPENDENCIES:	write(), <unistd.h>
 *
 * DESCRIPTION:		Prints a string of bytes to standard out.
 *
 * RETURN VALUES:	none.
 *
 * SEARCH TAGS:		ft putstr
 — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */
void	ft_putstr(char *str)
{
	while (*str)
		write(1, &(*str++), 1);
}


/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
 * DEPENDENCIES:	ft_putstr()
 *
 * DESCRIPTION:		Prints out given string array, each
 * 					string followed by a newline ('\n').
 *
 * RETURN VALUES:	none.
 *
 * SEARCH TAGS:		ft putstrab
 — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */
void	ft_putstrtab(char **tab)
{
	while (*tab)
	{
		ft_putstr(*tab);
		ft_putstr("\n");
		tab++;
	}
}


/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
 * DEPENDENCIES:	ft_putstr(), ft_putchar()
 *
 * DESCRIPTION:		Prints out given integer.
 *
 * RETURN VALUES:	none.
 *
 * SEARCH TAGS:		ft putnbr
 — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */
void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}


/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
 * DEPENDENCIES:	ft_validate_base_system(), ft_putchar()
 *
 * DESCRIPTION:		Displays a integer given in decimal as
 * 					an integer in the given base.
 *
 * RETURN VALUES:	none.
 *
 * SEARCH TAGS:		ft putnbr_base
 — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */
void	ft_putnbr_base(long nbr, char *base)
{
	int		quotient;
	long	col;
	short	i;
	short	base_sys;

	if (!ft_validate_base_system(base))
		return ;
	i = 0;
	col = 0;
	while (base[i++])
		col++;
	base_sys = col;
	if (nbr < 0)
		ft_putchar('-');
	if (nbr < 0)
		nbr = -nbr;
	while (col <= nbr)
		col *= base_sys;
	while (col > 1)
	{
		col /= base_sys;
		quotient = (nbr / col);
		ft_putchar(base[quotient]);
		nbr -= (quotient * col);
	}
}

/**
DEPENDENCIES: ft_putnbr_base
ft putstr_non_printable ; displays a string of characters on screen with
all non-printable characters as hexadeciaml values preceded by a '\' character.
*/
void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (!ISPRINT(*str))
		{
			ft_putchar('\\');
			if (*str <= '\xf')
				ft_putchar('0');
			ft_putnbr_base(*str++, "0123456789abcdef");
		}
		else
			ft_putchar(*str++);
	}
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
// ======================================================================= //
//                                 stdlib.h                                //
// ======================================================================= //
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //


/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
 * DEPENDENCIES:	none.
 *
 * DESCRIPTION:		Converts a string number into an integer.
 *
 * RETURN VALUES:	Returns the string number as an integer.
 *
 * SEARCH TAGS:		ft atoi
 — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */
int		ft_atoi(char *str)
{
	int	i;
	int	val;
	int	sign;

	i = 0;
	while ((str[i] >= '\a' && str[i] <= '\r') || str[i] == ' ')
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	val = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		val = (val * 10) + (str[i] - '0');
		i++;
	}
	return (val * sign);
}

/**
DEPENDENCIES:

ft_atoi_base_util
ft_validate_base_system
ft_is_charset
ft_strlen

ft atoi_base ; converts an integer string (given in base 'base')
to an integer in base 10.
*/
int		ft_atoi_base_util(char *str, char *base, short base_len)
{
	short	i;
	short	sign;
	short	index;
	long	val;

	i = 0;
	sign = 1;
	if ((str[i] == '+' || str[i] == '-') &&
		ft_is_charset_v2(str[i + 1], base, &index))
		if (str[i++] == '-')
			sign = -1;
	val = 0;
	index = 0;
	while (str[i] && ft_is_charset_v2(str[i++], base, &index))
	{
		val = (val * base_len) + (index);
		index = 0;
	}
	return (sign * val);
}

int		ft_atoi_base(char *str, char *base)
{
	short	base_len;
	short	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	if (!(ft_validate_base_system(base)) || (base_len = ft_strlen(base)) < 1)
		return (0);
	while ((str[i] >= '\a' && str[i] <= '\r') || str[i] == ' ')
		i++;
	return (ft_atoi_base_util(str + i, base, base_len));
}

/**
DEPENDENCIES: none.
ft itoa_base ; converts in integer in base 10 to a number in the
given base, as a string.

NOTE: does NOT handle INT_MIN
*/
char	*ft_itoa_base(int nbr, int base, char *buf)
{
	int		i;
	int		quotient;
	long	col;

	i = 0;
	if (nbr < 0)
	{
		buf[i++] = '-';
		nbr = -nbr;
	}
	col = base;
	while (col <= nbr)
		col *= base;
	while (col > 1)
	{
		col /= base;
		quotient = (nbr / col);
		buf[i++] = quotient + ((quotient < 10) ? '0' : 'W');
		nbr -= (quotient * col);
	}
	buf[i] = '\0';
	return (buf);
}

/**
DEPENDENCIES: none.
ft sort_int_tab ; sorts given integer array by ascending order.
*/
void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int temp;
	int out_of_order;

	i = 0;
	out_of_order = 1;
	while (size && out_of_order)
	{
		i = 0;
		out_of_order = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				out_of_order++;
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
			}
			i++;
		}
		size--;
		i = 0;
	}
}

/**
DEPENDENCIES: ft_strcmp
ft sort_word_tab ; sorts given string array by ASCII order.
*/
void	ft_sort_word_tab(char **tab)
{
	int		out_of_order;
	int		size;
	int		i;
	char	*temp;

	size = 0;
	while (tab[size])
		size++;
	out_of_order = 1;
	while (size && out_of_order)
	{
		i = 0;
		out_of_order = 0;
		while (++i < size - 1)
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				out_of_order++;
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
			}
		size--;
	}
}

/**
DEPENDENCIES: malloc, <stdlib.h>
ft advanced_sort_wordtab ; sorts a given string array using
the the 'cmp' function.
*/
void	ft_advanced_sort_wordtab(char **tab, int (*cmp)(char *, char *))
{
	int		out_of_order;
	int		size;
	int		i;
	char	*temp;

	size = 0;
	while (tab[size])
		size++;
	out_of_order = 1;
	while (size && out_of_order)
	{
		i = 0;
		out_of_order = 0;
		while (++i < size - 1)
			if (cmp(tab[i], tab[i + 1]) > 0)
			{
				out_of_order++;
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
			}
		size--;
	}
}

/**
DEPENDENCIES:

	ft_validate_base_system
	ft_itoa_base
	ft_atoi_base
	ft_ischarset_v2

ft convert_base ; takes an integer (in characters, i.e as a string) in base
'base_from' and converts it to an integer (in characters, i.e as a string) in
base 'base_to'; returns the string.
*/
char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	short	i;
	short	b_from_len;
	short	b_to_len;
	char	*buf;

	b_from_len = 0;
	b_to_len = 0;
	while (base_from[b_from_len])
		b_from_len++;
	while (base_to[b_to_len])
		b_to_len++;
	if (!nbr || !base_from || !base_to || !(buf = malloc(34)) ||
		b_from_len < 1 || b_to_len < 1 ||
		!(ft_validate_base_system(base_from)) ||
		!(ft_validate_base_system(base_to)))
		return (0);
	i = 0;
	while ((nbr[i] >= '\a' && nbr[i] <= '\r') || nbr[i] == ' ')
		i++;
	return
	(ft_itoa_base(
		ft_atoi_base(nbr + i, base_from, b_from_len),
											base_to, b_to_len, buf));
}

char	*ft_itoa_base_conv_util(long nbr, char *base, int base_, char *buf)
{
	short	i;
	int		quotient;
	long	col;

	i = 0;
	col = 0;
	while (base[col])
		col++;
	if (nbr < 0)
		buf[i++] = '-';
	if (nbr < 0)
		nbr = -nbr;
	while (col <= nbr)
		col *= base_;
	while (col > 1)
	{
		col /= base_;
		(quotient = nbr / col);
		buf[i++] = base[quotient];
		nbr -= (quotient * col);
	}
	buf[i] = '\0';
	return (buf);
}

int		ft_atoi_base_conv_util(char *str, char *base, short base_len)
{
	short	i;
	short	sign;
	short	index;
	long	val;

	i = 0;
	sign = 1;
	if ((str[i] == '+' || str[i] == '-') &&
		ft_ischarset_v2(str[i + 1], base, &index))
		if (str[i++] == '-')
			sign = -1;
	val = 0;
	index = 0;
	while (str[i] && ft_ischarset_v2(str[i++], base, &index))
	{
		val = (val * base_len) + (index);
		index = 0;
	}
	return (sign * val);
}

/**
DEPENDENCIES: ft_strncpy, malloc, free, <stdlib.h>
ft realloc ; creates a buffer twice the size of 'init_size', copies all
the values found in buffer into the 'new_buffer', frees the 'buffer', returns
a pointer to the 'new_buffer'.
*/
char	*ft_realloc(char *buffer, int init_size)
{
	char	*new_buffer;

	if (!(new_buffer = malloc(init_size * 2)))
		return (NULL);
	ft_strncpy(new_buffer, buffer, init_size - 1);
	free(buffer);
	return (new_buffer);
}



// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
// ======================================================================= //
//                                 string.h                                //
// ======================================================================= //
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

/**
DEPENDENCIES: none.
ft strlen ; returns length of given string.
*/
int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

/**
DEPENDENCIES: none.
ft strtablen ; returns the total length of all the strings in the
string table combined (all null-terminators excluded)
*/
int		ft_strtablen(int argc, char **argv)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	size = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j++])
			size++;
	}
	return (size);
}

/**
DEPENDENCIES: none.
ft strrev ; returns the given string in reverse order.
*/
char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	temp;

	j = 0;
	while (str[j])
		++j;
	i = -1;
	while (--j > ++i)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
	return (str);
}

/**
DEPENDENCIES: none.
ft strcpy ; copies all the characters of the buffer 'src' into the
buffer 'dest'.
*/
char	*ft_strcpy(char *dest, char *src)
{
	unsigned int i;

	i = 0;
	while (*src)
		dest[i++] = *src++;
	dest[i] = *src;
	return (dest);
}

/**
DEPENDENCIES: none.
ft strncpy ; copies up to 'n' characters of the buffer 'src' into the
buffer 'dest'.
*/
char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n && *src)
		dest[i++] = *src++;
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}

/**
DEPENDENCIES: none.
ft strlcpy ; copies up to dstsize - 1 characters from the string src
to dst, NUL-terminating the result if dstsize is not 0..
*/
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int				dst_len;
	int				src_len;
	int				bytes_left;
	unsigned int	i;

	dst_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	bytes_left = (int)size - 1;
	if (bytes_left >= 0)
	{
		i = 0;
		while (bytes_left-- && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		return (src_len);
	}
	return (src_len + size);
}

/**
DEPENDENCIES: none.
ft strstr ; locates a substring 'to_find' in the string 'str'
(reproduces the function strstr).
*/
char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	char	*anchor;

	if (!(*to_find))
		return (str);
	i = -1;
	while (str[++i])
		if (str[i] == to_find[0])
		{
			j = 0;
			anchor = (str + i);
			while (str[i] && to_find[j] && str[i] == to_find[j])
			{
				if (to_find[j + 1] == '\0')
					return (anchor);
				i++;
				j++;
			}
			if (!str[i])
				return (0);
		}
	return (0);
}

/**
DEPENDENCIES: none.
ft intcmp ; compares every two integers; returns the difference
between the two integers.
*/
int		ft_intcmp(int int1, int int2)
{
	unsigned int i;

	i = 0;
	while (int1[i] == int2[i] && int1[i] && int2[i])
		i++;
	return (int1[i] - int2[i]);
}

/**
DEPENDENCIES: none.
ft strcmp ; compares every character of two strings.
(reproduces the function strcmp).
*/
int		ft_strcmp(char *s1, char *s2)
{
	unsigned int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

/**
DEPENDENCIES: none.
ft strncmp ; compares up to 'n' characters of two strings.
(reproduces the function strncmp).
*/
int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	i = 0;
	n--;
	while (i < n && s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

/**
DEPENDENCIES: none.
ft strcapitalize ; function that capitalizes the first letter of each
word and transforms all other letters to lowercase.
*/
char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		while (str[i] && !ISALNUM(str[i]))
			i++;
		if (str[i] && ISLOWER(str[i]))
			str[i] = str[i] - 32;
		i++;
		while (str[i] && ISALNUM(str[i]))
			i++;
	}
	return (str);
}

/**
DEPENDENCIES: none.
ft strcat ; appends a copy of the null-terminated string 'src' to
the end of the null terminated string 'dest'.
(reproduction of the strcat function)
*/
char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}

/**
DEPENDENCIES: none.
ft strncat ; appends at most 'nb' characters of the null-terminated string 'src' to the end of the null terminated string 'dest'.
(reproduction of the strncat function)
*/
char	*ft_strncat(char *dest, char *src, int nb)
{
	int i;
	int j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j] && nb-- > 0)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}

/**
DEPENDENCIES: ft_strlen
ft strlcat ; appends at most (dest_buffer_size - strlen(dest) - 1)
characters from 'src' to 'dest'.
(reproduction of the function strlcat)
*/
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int				dst_len;
	int				src_len;
	int				bytes_left;
	unsigned int	i;
	unsigned int	j;

	dst_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	bytes_left = (int)size - dst_len - 1;
	if (bytes_left >= 0)
	{
		i = dst_len;
		j = 0;
		while (bytes_left-- && src[j])
			dest[i++] = src[j++];
		dest[i] = '\0';
		return (src_len + dst_len);
	}
	return (src_len + size);
}

/**
DEPENDENCIES: ft_strlen
ft strlcpy ; copies at most (dest_buffer_size - 1) characters
from 'src' to 'dest'.
(reproduction of the function strlcpy)
*/
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int				dst_len;
	int				src_len;
	int				bytes_left;
	unsigned int	i;

	dst_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	bytes_left = (int)size - 1;
	if (bytes_left >= 0)
	{
		i = 0;
		while (bytes_left-- && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		return (src_len + dst_len);
	}
	return (src_len + size);
}

/**
DEPENDENCIES:

	ft_word_count
	ft_ischarset
	ft_strdup_range

ft split_whitespaces ; cuts up a string by the word seperators:

	space
	return to lines (\n)
	tabulations (\t)

and stores the individual words in a string array and returns the
string array.
*/
char	**ft_split_whitespaces(char *str)
{
	char	**strtab;
	int		strtab_size;
	int		i;
	int		j;
	int		k;

	if (!(strtab = malloc(
		sizeof(char *) * (strtab_size = ft_word_count(str, " \t\n") + 1))))
		return ((strtab = 0));
	i = 0;
	k = 0;
	while (k < (strtab_size - 1))
	{
		while (str[i] && ft_ischarset(str[i], " \t\n"))
			i++;
		j = i;
		while (str[i] && !ft_ischarset(str[i], " \t\n"))
			i++;
		if (!(strtab[k++] = ft_strdup_range(str, j, i)))
			return ((strtab = 0));
	}
	strtab[k] = 0;
	return (strtab);
}

/**
DEPENDENCIES:

	ft_word_count
	ft_ischarset
	ft_strdup_range

ft split ; cuts up a string at the specified word seperators passed in the string 'charset'; returns a string array with the individual words.
*/
char	**ft_split(char *str, char *charset)
{
	char	**strtab;
	int		strtab_size;
	int		i;
	int		j;
	int		k;

	if (!(strtab = malloc(
		sizeof(char *) * (strtab_size = ft_word_count(str, charset) + 1))))
		return ((strtab = 0));
	i = 0;
	k = 0;
	while (k < (strtab_size - 1))
	{
		while (str[i] && ft_ischarset(str[i], charset))
			i++;
		j = i;
		while (str[i] && !ft_ischarset(str[i], charset))
			i++;
		if (!(strtab[k++] = ft_strdup_range(str, j, i)))
			return ((strtab = 0));
	}
	strtab[k] = 0;
	return (strtab);
}

/**
DEPENDENCIES: ft_ischarset
ft word_count ; counts the number of words that exist in the
string 'str' seperated by the specified word seperators.
*/
int		ft_word_count(char *str, char *word_seperators)
{
	int word_count;

	word_count = 0;
	while (*str)
	{
		while (*str && ft_ischarset(*str, word_seperators))
			str++;
		if (*str && !ft_ischarset(*str, word_seperators))
		{
			word_count++;
			while (*str && !ft_ischarset(*str, word_seperators))
				str++;
		}
	}
	return (word_count);
}

/**
DEPENDENCIES: malloc, <stdlib.h>
ft strdup ; allocates memory for a string duplicate of the
string 'src', then duplicates a string 'src' and finally
returns a pointer to it.
*/
char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i])
		i++;
	if (!(dest = malloc(i + 1)))
		return (0);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
DEPENDENCIES: malloc, <stdlib.h>
ft strdup_range ; allocates memory for a string duplicate of the
string 'src' from the index 'start' to the index 'end', does the
duplication and finally returns a pointer to it the string.
*/
char	*ft_strdup_range(char *src, int start, int end)
{
	int		i;
	char	*dest;

	if (!src)
		return (0);
	if (!(dest = malloc((end - start) + 1)))
		return (0);
	i = 0;
	while (start < end)
		dest[i++] = src[start++];
	dest[i] = '\0';
	return (dest);
}

/**
DEPENDENCIES: ft_strtablen, malloc, <stdlib.h>
ft concat_params ; creaetes a big string and concatenates all the arguments/
strings of the string array into it, seperating each string by a return
to line ('\n').
*/
char	*ft_concat_params(int argc, char **argv)
{
	char	*big_str;
	int		size;
	int		i;
	int		j;

	size = ft_strtablen(argc, argv);
	if (!(big_str = malloc(size + (argc - 1))))
		return (big_str = 0);
	i = 0;
	size = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j])
			big_str[size++] = argv[i][j++];
		if (i < argc - 1)
			big_str[size++] = '\n';
	}
	big_str[size--] = '\0';
	return (big_str);
}

/**
DEPENDENCIES: none.
ft memset ; fills a byte string with a byte value.
(reproduction of memset)

NOT TESTED !
NOT NORMED !
*/
char	*ft_memset(char *buf, char c, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < size)
		buf[i++] = c;
	return (buf);
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
// ======================================================================= //
//                                  math.h                                 //
// ======================================================================= //
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

/**
DEPENDENCIES: none.
ft factorial ; returns factorial of given number.
*/
int		ft_factorial(int nb)
{
	int i;
	int product;

	if (nb < 0 || nb > 12)
		return (0);
	if (nb == 0)
		return (1);
	product = nb;
	i = nb - 1;
	while (--nb)
		product *= i--;
	return (product);
}

/**
DEPENDENCIES: none.
ft power ; returns 'nb' to the power of 'power'.
*/
// WRONG DOESN'T HANDLE NEGATIVE 'nb' //
int		ft_power(int nb, int power)
{
	long	product;
	int		sign;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	sign = 1;
	if (nb < 0)
	{
		nb = -nb;
		sign = -1;
	}
	product = nb;
	while (--power)
	{
		product *= nb;
		if (product > 2147483647)
			return (-1);
	}
	return (sign * product);
}

/**
DEPENDENCIES: none.
ft sqrt ; returns square root of given number.
*/
int	ft_sqrt(int nb)
{
	int sqrt;
	int result;

	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (nb);
	sqrt = 2;
	result = 0;
	while ((result = sqrt * sqrt) <= nb)
	{
		if (result == nb)
			return (sqrt);
		sqrt++;
	}
	return (0);
}

/**
DEPENDENCIES: none.
ft is_prime ; returns 1 if given number is a prime number; else 0.
*/
int		ft_is_prime(int nb)
{
	long i;
	long result;

	if (nb < 2)
		return (0);
	if (nb == 2 || nb == 3 || nb == 5 || nb == 7)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0 || nb % 5 == 0 || nb % 7 == 0)
		return (0);
	i = 11;
	while ((result = i * i) < nb)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

/**
DEPENDENCIES: none.
ft find_next_prime ; returns the next prime number that is equal or
greater to given number.
*/
int		ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	if (nb == 2)
		return (nb);
	if (nb % 2 == 0)
		nb++;
	while (!ft_is_prime(nb))
		nb += 2;
	return (nb);
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
// ======================================================================= //
//                                  ctype.h                                //
// ======================================================================= //
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

/**
DEPENDENCIES: none.
ft isalnum ; checks if character is an alphanumeric character.
*/
int		ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') ||
		(c >= 'a' && c <= 'z') ||
		(c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/**
DEPENDENCIES: none.
ft isalpha ; checks if character is an alphabetical character.
*/
int		ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') ||
		(c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/**
DEPENDENCIES: none.
ft isupper ; checks if character is an uppercase character.
*/
int		ft_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

/**
DEPENDENCIES: none.
ft islower ; checks if character is an lowercase character.
*/
int		ft_islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

/**
DEPENDENCIES: none.
ft tolower ; turns the character a lowercase character.
*/
char	ft_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (0);
}

/**
DEPENDENCIES: none.
ft toupper ; turns the character a uppercase character.
*/
char	ft_toupper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (0);
}

/**
DEPENDENCIES: none.
ft isdigit ; checks if character is a digit character.
*/
int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
DEPENDENCIES: none.
ft isprint ; checks if character is a printable character.
*/
int		ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/**
DEPENDENCIES: none.
ft isblank ; checks if character is a space character or a tab character.
*/
int		ft_isblank(int c)
{
	if (c == 32 || c == 9)
		return (1);
	return (0);
}

/**
DEPENDENCIES: none.
ft isspace ; checks if character is an uppercase character.
*/
int		ft_isspace(int c)
{
	if (c >= 9 && c <= 13 || c == 9)
		return (1);
	return (0);
}

/**
DEPENDENCIES: none.
ft ischarset ; checks if character is one of the characters in 'charset',
if so returns 1; else 0; Plus it will store the index of where the character
was found in 'charset'. (first one does not take index)
*/
int		ft_ischarset(char c, char *charset)
{
	while (*charset)
		if (c == *charset++)
			return (1);
	return (0);
}

int		ft_ischarset_v2(char c, char *charset, short *index)
{
	int not_part;

	not_part = 1;
	while (not_part && *charset)
	{
		if (c == *charset++)
			return (1);
		(*index)++;
	}
	return (0);
}

/**
DEPENDENCIES: none.
ft strupcase ; turns all lowercase alphabetical characters to
uppercase alphabetical characters.
*/
char	*ft_strupcase(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
	return (str);
}

/**
DEPENDENCIES: none.
ft strlowcase ; turns all uppercase alphabetical characters to
lowercase alphabetical characters.
*/
char	*ft_strlowcase(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
	return (str);
}

/**
DEPENDENCIES: none.
ft str_is_alpha ; returns 1 if the given string contains only
aplhabetical characters; else 0.
*/
int		ft_str_is_alpha(char *str)
{
	while (*str)
	{
		if (!((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')))
			return (0);
		str++;
	}
	return (1);
}

/**
DEPENDENCIES: none.
ft str_is_numeric ; returns 1 if the given string contains only
numeric characters; else 0.
*/
int		ft_str_is_numeric(char *str)
{
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

/**
DEPENDENCIES: none.
ft str_is_lowercase ; returns 1 if the given string contains only
lowercase characters; else 0.
*/
int		ft_str_is_lowercase(char *str)
{
	while (*str)
	{
		if (!(*str >= 'a' && *str <= 'z'))
			return (0);
		str++;
	}
	return (1);
}

/**
DEPENDENCIES: none.
ft str_is_uppercase ; returns 1 if the given string contains only
uppercase characters; else 0.
*/
int		ft_str_is_uppercase(char *str)
{
	while (*str)
	{
		if (!(*str >= 'A' && *str <= 'Z'))
			return (0);
		str++;
	}
	return (1);
}

/**
DEPENDENCIES: none.
ft str_is_printable ; returns 1 if the given string contains only
printable characters; else 0.
*/
int		ft_str_is_printable(char *str)
{
	while (*str)
	{
		if (!(*str >= 32 && *str <= 126))
			return (0);
		str++;
	}
	return (1);
}

/**
DEPENDENCIES: none.
ft str_is_blank ; returns 1 if the given string contains only
blank characters; else 0.
*/
int		ft_str_is_blank(char *str)
{
	while (*str)
	{
		if (!(*str == 32 || *str == 9))
			return (0);
		str++;
	}
	return (1);
}

/**
DEPENDENCIES: none.
ft is_sort ; returns 1 if the array is sorted and 0 if it isn't

NOTE: The function given as argument should return a negative integer if the
first argument is lower than the second, 0 if they’re equal or a positive
integer for anything else.
*/
int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;

	i = -1;
	while (++i < length - 1)
		if (f(tab[i], tab[i + 1]) > 0)
			return (0);
	return (1);
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
// ======================================================================= //
//                                  utilies.h                              //
// ======================================================================= //
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

/**
DEPENDENCIES: none.
ft swap ; swaps two integers
*/
void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
DEPENDENCIES: none.
ft swap ; swaps two pointers.

NOTE: this is meant to be a generic swap function.
*/
void	ft_swap(void **a, void **b)
{
	void *temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
DEPENDENCIES: none.
ft parse_radix ; ft parse_rdx ; returns base as an integer
if it is valid (base is given as an integer string); else 0
*/
int		ft_parse_rdx(char *base_str)
{
	short	i;
	short	base;

	i = 0;
	base = 0;
	while (base_str[i])
	{
		if (!((base_str[i] >= '0' && base_str[i] <= '9')))
			return (0);
		base = (base * 10) + (base_str[i++] - '0');
	}
	if (base < 2 || base > 35)
		return (0);
	return (base);
}

/**
DEPENDENCIES: none.
ft validate_base_system ; returns 1 if the characters of the base system are valid; else 0; checks...

	- that the string 'base_str' isn't empty
	- that the base isn't empty or of size 1
	- that 'base_str' doesn't contain '+' or '-', etc
	- that the 'base_str' (the base) doesn't contain the same character twice

*/
int		ft_validate_base_system(char *base_str)
{
	short	i;
	short	j;
	short	count;

	if (!base_str || !base_str[0] || !base_str[1])
		return (0);
	i = -1;
	while (base_str[++i])
	{
		count = 0;
		if (!ISPRINT(base_str[i]))
			return (0);
		if (base_str[i] == '+' || base_str[i] == '-')
			return (0);
		j = -1;
		while (base_str[++j])
			if (base_str[i] == base_str[j])
				count++;
		if (count > 1)
			return (0);
	}
	return (1);
}

/**
DEPENDENCIES: none.
ft char_2_indx ; turns a given character into the
index it corresponds to.

NOT TESTED !
NOT NORMED !
*/
int			char_2_indx(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (c - '0');
	}
	else if (c >= 'a' && c <= 'z')
	{
		return (c - 'a' + 10);
	}
	else if (c >= 'A' && c <= 'Z')
	{
		return (c - 'A' + 10);
	}
	else if (c == '\'')
	{
		return (36);
	}
	return (0);
}

/**
DEPENDENCIES: none.
ft alpha_2_indx ; turns a given alphabetical letter
character into the index it corresponds to.

NOT TESTED !
NOT NORMED !
*/
int			alpha_2_indx(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 97);
	}
	else if (c >= 'A' && c <= 'Z')
	{
		return (c - 65);
	}
	else if (c == '\'')
	{
		return (26);
	}
	return (0);
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
// ======================================================================= //
//                                 ftptrs.h                                //
// ======================================================================= //
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

/**
DEPENDENCIES: none.
ft foreach ; applies a function on every element of an integer array
*/
void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int i;

	i = 0;
	while (i < length)
		(*f)(tab[i++]);
}

/**
DEPENDENCIES: malloc, <stdlib.h>
ft map ; applies a function on every element of an integer
array and stores the newly changed values in a duplicate array.
*/
int		*ft_map(int *tab, int length, int (*f)(int))
{
	int *tab_dup;
	int i;

	if (!(tab_dup = malloc(sizeof(int) * length)))
		return (tab_dup = NULL);
	i = -1;
	while (++i < length)
		tab_dup[i] = (*f)(tab[i]);
	return (tab_dup);
}

/**
DEPENDENCIES: none.
ft any ; returns 1 if, passed to the function 'f', at least
one element of the array returns 1; else returns 0.
*/
int		ft_any(char **tab, int (*f)(char*))
{
	while (*tab)
		if ((*f)(*tab++) == 1)
			return (1);
	return (0);
}

/**
DEPENDENCIES: none.
ft count_if ; returns the number of elements of the array that
return 1, passed to the function 'f'.
*/
int		ft_count_if(char **tab, int (*f)(char*))
{
	int count;

	count = 0;
	while (*tab)
		if ((*f)(*tab++) == 1)
			count++;
	return (count);
}

/**
DEPENDENCIES: none.
ft is_sort ; returns 1 if according to the function 'f' the
integer array is sorted; else 0.
*/
int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;

	i = 0;
	while (i + 1 < length)
	{
		if ((*f)(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

/**
DEPENDENCIES: ft_strcmp, ft_swap
ft sort_wordtab ; sorts a string array by ASCII order.
*/
void	ft_sort_wordtab(char **tab)
{
	int i;
	int end;

	end = 0;
	while (tab[end])
		end++;
	while (end > 1)
	{
		i = -1;
		while (++i < end - 1)
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
				ft_swap(&tab[i], &tab[i + 1]);
		end--;
	}
}

/**
DEPENDENCIES: ft_strcmp, ft_swap
ft advanced_sort_wordtab ; sorts a string array according to the
'cmp' function's order.
*/
void	ft_advanced_sort_wordtab(char **tab, int (*cmp)(char *, char *))
{
	int i;
	int end;

	end = 0;
	while (tab[end])
		end++;
	while (end > 1)
	{
		i = -1;
		while (++i < end - 1)
			if ((*cmp)(tab[i], tab[i + 1]) > 0)
				ft_swap(&tab[i], &tab[i + 1]);
		end--;
	}
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
// ======================================================================= //
//                                  llist.h                                //
// ======================================================================= //
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

/* * * * * * * * * * * *
========================
   LINKED LIST HEADER
========================
 * * * * * * * * * * * */

#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

t_list				*ft_create_elem(void *data);
void				ft_list_push_back(t_list **begin_list, void *data);
void				ft_list_push_front(t_list **begin_list, void *data);
int					ft_list_size(t_list *begin_list);
t_list				*ft_list_last(t_list *begin_list);
t_list				*ft_list_push_params(int ac, char **av);
void				ft_list_clear(t_list **begin_list);
t_list				*ft_list_at(t_list *begin_list, unsigned int nbr);
void				ft_list_reverse(t_list **begin_list);
void				ft_list_foreach(t_list *begin_list, void (*f)(void *));
void				ft_list_foreach_if(t_list *begin_list,
							void (*f)(void *), void *data_ref, int (*cmp)());
t_list				*ft_list_find(t_list *begin_list, void *data_ref,
																int (*cmp)());
void				ft_list_remove_if(t_list **begin_list, void *data_ref,
																int (*cmp)());
void				ft_list_merge(t_list **begin_list1, t_list *begin_list2);
void				ft_list_sort(t_list **begin_list, int (*cmp)());
void				ft_list_reverse_fun(t_list *begin_list);
void				ft_sorted_list_insert(t_list **begin_list, void *data,
																int (*cmp)());
void				ft_sorted_list_merge(t_list **begin_list1,
											t_list *begin_list2, int (*cmp)());

#endif


/**
DEPENDENCIES: malloc, <stdlib.h>
ft create_elem ; creates a new list element & assigns 'data' to the given argument and 'next' to NULL.
*/
t_list	*ft_create_elem(void *data)
{
	t_list *new_elem;

	if (!(new_elem = malloc(sizeof(t_list))))
		return (NULL);
	new_elem->data = data;
	new_elem->next = NULL;
	return (new_elem);
}

/**
DEPENDENCIES: ft_create_elem
ft list_push_back ; pushes an element to the back of the list if the list
already exists; else creates an elements and returns an address to it.
*/
void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *probe;

	if (begin_list && (*begin_list))
	{
		probe = (*begin_list);
		while (probe->next)
			probe = probe->next;
		probe->next = ft_create_elem(data);
	}
	else
		(*begin_list) = ft_create_elem(data);
}

/**
DEPENDENCIES: ft_create_elem
ft list_push_front ; pushes an element to the front of the list if the list
already exists and updates the pointer to the pointer to the head of the list;
else creates an element and returns an address to it.
*/
void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *new_elem;

	new_elem = ft_create_elem(data);
	new_elem->next = (*begin_list);
	(*begin_list) = new_elem;
}

/**
DEPENDENCIES: none.
ft list_size ; returns the size of the linked list (number of elements).
*/
int		ft_list_size(t_list *begin_list)
{
	t_list	*probe;
	int		size;

	size = 0;
	probe = begin_list;
	while (probe)
	{
		size++;
		probe = probe->next;
	}
	return (size);
}

/**
DEPENDENCIES: none.
ft list_last ; returns the address of to the last element of the
list; else NULL.
*/
t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*probe;

	if (begin_list)
	{
		probe = begin_list;
		while (probe->next)
			probe = probe->next;
		return (probe);
	}
	return (0);
}

/**
DEPENDENCIES: free, <stdlib.h>
ft list_clear ; frees the entire linked list.
*/
void	ft_list_clear(t_list **begin_list)
{
	t_list *temp;

	if (!begin_list || !(*begin_list))
		return ;
	while (*begin_list)
	{
		temp = (*begin_list);
		(*begin_list) = (*begin_list)->next;
		free(temp);
	}
}

/**
DEPENDENCIES: none.
ft list_at ; returns an address to the N'th element (nbr being N).
*/
t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	int num;

	if (!begin_list)
		return (0);
	num = nbr;
	while (num-- > 0 && begin_list)
		begin_list = begin_list->next;
	return (begin_list);
}

/**
DEPENDENCIES: ft_list_size, ft_list_last
ft list_reverse ; reverse the linked list.
*/
void	ft_list_reverse(t_list **begin_list)
{
	t_list	*last;
	t_list	*after_last;
	int		size;

	if (begin_list && (*begin_list))
	{
		size = ft_list_size(*begin_list);
		last = ft_list_last(*begin_list);
		while (size-- > 1)
		{
			after_last = (*begin_list);
			(*begin_list) = (*begin_list)->next;
			after_last->next = last->next;
			last->next = after_last;
		}
		begin_list = &last;
	}
}

/**
DEPENDENCIES: none.
ft list_foreach ; applys the function 'f' to every element of the
linked list.
*/
void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list *list_ptr;

	list_ptr = begin_list;
	while (list_ptr)
	{
		(*f)(list_ptr->data);
		list_ptr = list_ptr->next;
	}
}

/**
DEPENDENCIES: none.
ft list_foreach_if ; applys the function 'f' to every element of the
linked list if the item of the linked list element matches the item
(data_ref) passed as argument.
*/
void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
	void *data_ref, int (*cmp)())
{
	t_list *list_ptr;

	list_ptr = begin_list;
	while (list_ptr)
	{
		if ((*cmp)(list_ptr->data, data_ref) == 0)
			(*f)(list_ptr->data);
		list_ptr = list_ptr->next;
	}
}

/**
DEPENDENCIES: none.
ft list_find ; finds and returns an address to the first linked list element
that has an item that matches the item (data_ref) passed as argument.
*/
t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list *list_ptr;

	list_ptr = begin_list;
	while (list_ptr)
	{
		if ((*cmp)(list_ptr->data, data_ref) == 0)
			return (list_ptr);
		list_ptr = list_ptr->next;
	}
	return (0);
}

/**
DEPENDENCIES: free, <stdlib.h>
ft list_remove_if ; deletes an element of the linked list if the element's
item matches the item (data_ref) passed as argument.
*/
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *prev_elem;
	t_list *cur_elem;

	cur_elem = (*begin_list);
	while (cur_elem)
	{
		if ((*cmp)(cur_elem->data, data_ref) == 0)
		{
			if (cur_elem == (*begin_list))
			{
				(*begin_list) = (*begin_list)->next;
				free(cur_elem);
				cur_elem = (*begin_list);
				continue ;
			}
			prev_elem->next = cur_elem->next;
			free(cur_elem);
			cur_elem = prev_elem->next;
			continue ;
		}
		prev_elem = cur_elem;
		cur_elem = cur_elem->next;
	}
}

/**
DEPENDENCIES: ft_list_last
ft list_merge ; appends (merges) linked list #2 to the end of linked
list #1.
*/
void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *last;

	if (!begin_list1 || !(*begin_list1))
		(*begin_list1) = begin_list2;
	else
	{
		last = ft_list_last(*begin_list1);
		last->next = begin_list2;
	}
}

/**
DEPENDENCIES: ft_list_size
ft list_sort ; sorts the given linked list according to the
'cmp' function.
*/
void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int		size;
	int		i;
	void	*temp;
	t_list	*probe;

	if (begin_list && (*begin_list))
	{
		size = ft_list_size(*begin_list);
		while (size)
		{
			i = 0;
			probe = (*begin_list);
			while (++i < size)
			{
				if ((*cmp)(probe->data, probe->next->data) > 0)
				{
					temp = probe->data;
					probe->data = probe->next->data;
					probe->next->data = temp;
				}
				probe = probe->next;
			}
			size--;
		}
	}
}

/**
DEPENDENCIES: ft_list_size
ft list_reverse_fun ; reverses the linked list without changing the
pointer to the pointer to the head of the linked list.
*/
void	ft_list_reverse_fun(t_list *begin_list)
{
	int		size;
	int		size_cpy;
	void	*temp;
	t_list	*probe;

	if (begin_list)
	{
		size = ft_list_size(begin_list);
		while (size-- > 1)
		{
			probe = begin_list;
			size_cpy = size;
			while (size_cpy-- > 0)
			{
				temp = probe->data;
				probe->data = probe->next->data;
				probe->next->data = temp;
				probe = probe->next;
			}
		}
	}
}

/**
DEPENDENCIES: ft_list_push_front, ft_list_size, ft_list_sort
ft sorted_list_insert ; inserts an element to the linked list
all while keeping the linked list sorted.
*/
void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	ft_list_push_back(begin_list, data);
	ft_list_sort(begin_list, cmp);
}

/**
DEPENDENCIES: ft_list_push_front, ft_list_size, ft_list_sort
ft sorted_list_merge ; merges two linked lists and then sorts the
complete linked list.
*/
void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
								int (*cmp)())
{
	ft_list_merge(begin_list1, begin_list2);
	ft_list_sort(begin_list1, cmp);
}



// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
// ======================================================================= //
//                                  btree.h                                //
// ======================================================================= //
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

/* * * * * * * * * * * *
========================
   BINARY TREE HEADER
========================
 * * * * * * * * * * * */

#ifndef FT_BTREE_H
# define FT_BTREE_H

typedef struct	s_btree
{
	void			*item;
	struct s_btree	*left;
	struct s_btree	*right;
}				t_btree;

typedef struct	s_list
{
	struct t_btree	*node;
	struct s_list	*next;
}				t_list;

t_btree			*btree_create_node(void *item);
void			btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void			btree_apply_infix(t_btree *root, void (*applyf)(void *));
void			btree_apply_suffix(t_btree *root, void (*applyf)(void *));
void			btree_insert_data(t_btree **root, void *item,
	int (*cmpf)(void *, void *));
void			*btree_search_item(t_btree *root, void *data_ref,
	int (*cmpf)(void *, void *));
int				btree_level_count(t_btree *root);
void			btree_apply_by_level(t_btree *root,
	void (*applyf)(void *item, int current_level, int is_first_elem));
void			ft_list_push_back(t_list **begin_list, void *data);
void			dequeue(t_list **begin_list);
int				ft_treat_node(t_list **q_head, t_btree cur_node, int level,
	int first);

#endif


/**
DEPENDENCIES: malloc, <stdlib.h>
ft btree create_node ; creates a binary tree node and stores in it
the item passed as argument, points the children to NULL.
*/
t_btree		*btree_create_node(void *item)
{
	t_btree *new_node;

	if (!(new_node = malloc(sizeof(t_btree))))
		return (NULL);
	new_node->item = item;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

/**
DEPENDENCIES: none.
ft btree apply_prefix ; pre-order (prefix) traversal.
*/
void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (root)
	{
		(*applyf)(root->item);
		if (root->left)
			btree_apply_prefix(root->left, applyf);
		if (root->right)
			btree_apply_prefix(root->right, applyf);
	}
}

/**
DEPENDENCIES: none.
ft btree apply_infix ; in-order (infix) traversal.
*/
void	btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (root)
	{
		if (root->left)
			btree_apply_infix(root->left, applyf);
		(*applyf)(root->item);
		if (root->right)
			btree_apply_infix(root->right, applyf);
	}
}

/**
DEPENDENCIES: none.
ft btree apply_suffix ; post-order (suffix) traversal.
*/
void	btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (root)
	{
		if (root->left)
			btree_apply_suffix(root->left, applyf);
		if (root->right)
			btree_apply_suffix(root->right, applyf);
		(*applyf)(root->item);
	}
}

/**
DEPENDENCIES: btree_create_node
ft btree insert_data ; inserts an item into the tree all while keeping
the tree in order.
*/
void	btree_insert_data(t_btree **root, void *item,
	int (*cmpf)(void *, void *))
{
	t_btree *probe;

	if (!root || !(*root))
	{
		if (root)
			(*root) = btree_create_node(item);
		return ;
	}
	probe = (*root);
	if ((*cmpf)(item, probe->item) < 0)
	{
		if (probe->left)
			btree_insert_data(&(probe->left), item, cmpf);
		else
			probe->left = btree_create_node(item);
	}
	else
	{
		if (probe->right)
			btree_insert_data(&(probe->right), item, cmpf);
		else
			probe->right = btree_create_node(item);
	}
}

/**
DEPENDENCIES: none.
ft btree search_item ; searches and returns a pointer to the node that
contains an item, that according to the 'cmpf' comparative function,
matches the item (data_ref) passed as argument.
*/
void	*btree_search_item(t_btree *root, void *data_ref,
	int (*cmpf)(void *, void *))
{
	if (root)
	{
		if ((*cmpf)(root->item, data_ref) == 0)
			return (root->item);
		if (root->left)
			return (btree_search_item(root->left, data_ref, cmpf));
		if (root->right)
			return (btree_search_item(root->right, data_ref, cmpf));
	}
	return (0);
}

/**
DEPENDENCIES: none.
ft btree level_count ; returns the height of the tree.
*/
int		btree_level_count(t_btree *root)
{
	int left_count;
	int right_count;

	if (!root)
		return (0);
	left_count = 0;
	right_count = 0;
	if (root->left)
		left_count = btree_level_count(root->left);
	if (root->right)
		right_count = btree_level_count(root->right);
	return ((left_count > right_count) ? left_count + 1 : right_count + 1);
}

/**
DEPENDENCIES: ft_list_push_back, ft_treat_node, dequeue
ft btree level_count ; applys the function 'applyf' to all
elements of the tree by level order.
*/
void	btree_apply_by_level(t_btree *root,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
	t_list	*q_head;
	int		level;
	int		first;
	int		tree_size;
	int		level_size;

	if (!root)
		return ;
	tree_size = 1;
	level = -1;
	q_head = 0;
	ft_list_push_back(&q_head, root);
	while (tree_size > 0)
	{
		level++;
		first = 1;
		level_size = tree_size;
		while (level_size > 0 && tree_size > 0)
		{
			tree_size += ft_treat_node(&q_head, q_head->node);
			(*applyf)(q_head->node->item, level, first);
			dequeue(&q_head, &tree_size, &level_size);
			(first == 1) ? first = 0 : 0;
		}
	}
}

/** Util: stores the children of the current node in the queue passed as arg. */
int		ft_treat_node(t_list **q_head, t_btree *cur_node)
{
	int nodes_added;

	nodes_added = 0;
	if (cur_node->left)
	{
		ft_list_push_back(q_head, cur_node->left);
		nodes_added++;
	}
	if (cur_node->right)
	{
		ft_list_push_back(q_head, cur_node->right);
		nodes_added++;
	}
	return (nodes_added);
}

/** Util: dequeues an element of the queue and decrement some counters. */
void	dequeue(t_list **begin_list, int *tree_size, int *level_size)
{
	t_list *temp;

	if (begin_list && (*begin_list))
	{
		temp = (*begin_list);
		if ((*begin_list)->next)
			(*begin_list) = (*begin_list)->next;
		free(temp);
	}
	(*tree_size)--;
	(*level_size)--;
}



// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
// ======================================================================= //
//                                  trie.h                                 //
// ======================================================================= //
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

/* * * * * * * * * * * *
========================
       TRIE HEADER
========================
 * * * * * * * * * * * */

#ifndef FT_TRIE_H
# define FT_TRIE_H

# define ALPHABET_SIZE 27
# define HEXDIGIT_SIZE 16
# define SIZE_OF_ARRAY ALPHABET_SIZE

typedef struct			s_trie
{
	void				*data;
	struct s_trie		*children[SIZE_OF_ARRAY];
}						t_trie;

unsigned int	char_2_indx(char c);

unsigned int	alpha_2_indx(char c);

t_trie			*trie_create_node(void);

void			trie_insert_data(t_trie **root, char *hash, void *data,
				unsigned int (*char_to_index)(char c));

void			trie_insert_data_recursive(t_trie **root, char *hash,
				void *data, unsigned int (*char_to_index)(char c));

void			trie_delete_data(t_trie **root, char *hash,
				unsigned int (*char_to_index)(char c));
void			trie_destroy(t_trie **root);

void			*trie_fetch_data(t_trie *root, char *hash,
				unsigned int (*char_to_index)(char c));

unsigned int	trie_size(t_trie *root);

#endif

/**
DEPENDENCIES: none.
ft char_2_indx ; turns a given character into the
index it corresponds to.

HALF TESTED !
NOT NORMED !
*/
unsigned int				char_2_indx(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (c - '0');
	}
	else if (c >= 'a' && c <= 'z')
	{
		return (c - 'a' + 10);
	}
	else if (c >= 'A' && c <= 'Z')
	{
		return (c - 'A' + 10);
	}
	else if (c == '\'')
	{
		return (36);
	}
	return (0);
}

/**
DEPENDENCIES: none.
ft alpha_2_indx ; turns a given alphabetical letter
character into the index it corresponds to.

HALF TESTED !
NOT NORMED !
*/
unsigned int				alpha_2_indx(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 97);
	}
	else if (c >= 'A' && c <= 'Z')
	{
		return (c - 65);
	}
	else if (c == '\'')
	{
		return (26);
	}
	return (0);
}

/**
DEPENDENCIES: malloc, <stdlib.h>
ft trie_create_node ; returns length of given string.

HALF TESTED !
NOT NORMED !
*/
t_trie			*trie_create_node(void)
{
	t_trie *new_node;
	unsigned int i;

	if (!(new_node = malloc(sizeof(t_trie))))
		return (NULL);
	new_node->data = NULL;
	i = 0;
	while (i < SIZE_OF_ARRAY)
		(new_node->children)[i++] = NULL;
	return (new_node);
}

/**
DEPENDENCIES: trie_create_node
ft trie_insert_data ; creates & inserts given data into a trie data-structure.

HALF TESTED !
NOT NORMED !
*/
void			trie_insert_data(t_trie **root, char *hash, void *data,
				unsigned int (*char_to_index)(char c))
{
	t_trie			*cur_node;
	unsigned int	index;

	if (root && *root && hash)
	{
		cur_node = (*root);
		while (*hash != '\0')
		{
			index = char_to_index(*hash);
			if ((cur_node->children)[index] == NULL)
				(cur_node->children)[index] = trie_create_node();
			cur_node = (cur_node->children)[index];
			hash++;
		}
		cur_node->data = data;
	}
}

void			trie_insert_data_recursive(t_trie **root, char *hash,
				void *data, unsigned int (*char_to_index)(char c))
{
	unsigned int index;

	if (root && *root && hash)
	{
		if (*hash != '\0')
		{
			index = char_to_index(*hash);
			if (((*root)->children)[index] == NULL)
				((*root)->children)[index] = trie_create_node();
			trie_insert_data(
				(&((*root)->children)[index]), hash + 1, data, char_to_index);
		}
		else
			(*root)->data = data;
	}
}

/**
DEPENDENCIES: free, <stdlib.h>
ft trie_delete_data ; deletes the data that is mapped to the hash
and only the leaf nodes that do not contain any data that lead to
the deleted node.

HALF TESTED !
NOT NORMED !
*/
void			trie_delete_data(t_trie **root, char *hash,
				unsigned int (*char_to_index)(char c))
{
	unsigned int index;

	if (root && *root && hash)
	{
		if (*hash == '\0')
		{
			free((*root)->data);
			(*root)->data = NULL;
		}
		else
		{
			index = char_to_index(*hash);
			if (((*root)->children)[index])
				trie_delete_data(
					&(((*root)->children)[index]), hash + 1, char_to_index);
		}
		if ((*root)->data)
			return ;
		index = 0;
		while (index < SIZE_OF_ARRAY)
			if (((*root)->children)[index++])
				return ;
		free(*root);
		(*root) = NULL;
	}
}

/**
DEPENDENCIES: free, <stdlib.h>
ft trie_destroy ; frees up the entire trie data-structure
(deleteing every node of the trie and all the data
contained within it).

HALF TESTED !
NOT NORMED !
*/
void			trie_destroy(t_trie **root)
{
	unsigned int i;

	if (root && *root)
	{
		i = 0;
		while (i < SIZE_OF_ARRAY)
		{
			if (((*root)->children)[i])
				trie_destroy(&(((*root)->children)[i]));
			i++;
		}
		if ((*root)->data)
		{
			free((*root)->data);
			(*root)->data = NULL;
		}
		free(*root);
		(*root) = NULL;
	}
}

/**
DEPENDENCIES: none.
ft trie_fetch_data ; retrieves the data that is mapped to the hash.
Returns an address to the data.

HALF TESTED !
NOT NORMED !
*/
void			*trie_fetch_data(t_trie *root, char *hash,
				unsigned int (*char_to_index)(char c))
{
	unsigned int index;

	if (root && hash)
	{
		if (*hash == '\0')
			return (root->data);
		index = char_to_index(*hash);
		return (trie_fetch_data(
			(root->children)[index], hash + 1, char_to_index));
	}
	return (NULL);
}

/**
DEPENDENCIES: none.
ft trie_size ; counts & returns the number of data elements currently
stored within the trie data-structure.

HALF TESTED !
NOT NORMED !
*/
unsigned int	trie_size(t_trie *root)
{
	unsigned int data_count;
	unsigned int i;

	if (root)
	{
		data_count = 0;
		if (root->data)
			data_count++;
		i = 0;
		while (i < SIZE_OF_ARRAY)
		{
			if (root->children[i])
				data_count += trie_size(root->children[i]);
			i++;
		}
		return (data_count);
	}
	return (0);
}







// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
// ======================================================================= //
//                         HASH TABLE FUNCTION LIBRARY                     //
// ======================================================================= //
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

/* * * * * * * * * * * *
========================
    HASH TABLE HEADER
========================
 * * * * * * * * * * * */

#ifndef FT_HASHTABLE_H
# define FT_HASHTABLE_H

# define HASHCODE(key, buckets) (hash(key, ft_strlen(key)) % buckets)

# define MIN_LOAD_FACTOR 0.0
# define MAX_LOAD_FACTOR 0.7

typedef struct      s_entry
{
    char            *key;
    void            *value;
    struct s_entry  *successor;
}                   t_entry;

typedef struct      s_hashtable
{
    unsigned int    entries;
    unsigned int    num_buckets;
    t_entry         **bucket_list;
}                   t_hashtable;

t_hashtable     *hashtable_alloc_table(unsigned int num_entries);
int             hashtable_grow_table(t_hashtable **table);
int             hashtable_shrink_table(t_hashtable **table);

t_entry         *hashtable_fetch_entry(t_hashtable *table, char *key);
int             hashtable_insert_entry(t_hashtable **table,
                                       char *key,
                                       void *value);
int             hashtable_delete_entry(t_hashtable **table, char *key);
int             hashtable_rehash_entry(t_hashtable **table_to,
                                       t_entry **entry);
int             hashtable_rehash_table(t_hashtable **table_from,
                                       t_hashtable **table_to);
int             hashtable_destroy_table(t_hashtable **table);
int             hashtable_set_appropriate_load_factor(t_hashtable **table);

t_entry         *entry_create(char *key, void *value);
void            entry_free(t_entry **entry);
void            bucket_free(t_entry **head);

#endif


/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
DEPENDENCIES:   malloc() , <stdlib.h>
                ft_find_next_prime()

DESCRIPTION:    Creates/allocates an empty hash table of size 'num_entries'
                and then some (inorder to get to the nearest prime
                number).

RETURN VALUES:  If successful, returns a pointer to the
                hash table. If an error occurs the function
                will return a NULL pointer.

SEARCH TAGS:    ft hashtable_alloc_table    ft hashtable_create_table
                ft ht_alloc_table           ft ht_create_table
 — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

t_hashtable		*hashtable_alloc_table(unsigned int num_entries)
{
	t_hashtable		*table;
	unsigned int	i;

	if (num_entries < 1)
		return (NULL);
	if (!(table = malloc(sizeof(t_hashtable))))
		return (NULL);
	num_entries = (unsigned int)ft_find_next_prime(num_entries);
	if (!(table->bucket_list =
			malloc(sizeof(t_entry*) * num_entries)))
	{
		free(table);
		return (NULL);
	}
	table->num_buckets = num_entries;
	table->entries = 0;
	i = 0;
	while (i < num_entries)
		(table->bucket_list)[i++] = NULL;
	return (table);
}



/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
DEPENDENCIES:   hashtable_set_appropriate_load_factor()
                entry_create()
                ft_strlen()
                HASHCODE()
                hash()

DESCRIPTION:    Inserts a key-value pair into the hash table.

                NOTE: in this implementation ownership of 'value' is
                taken, that is to say that free'ing of 'value' will be
                taken care of, but 'value' MUST be allocated before hand
                somewhere in the code, if you fail to do so, upon free'ing
                of an entry or the hash table you WILL get a 'bad free'
                error.

                As for the 'key', a duplicate of it will be made (i.e
                memory will be allocated inorder to make a duplicate of
                it). The memory will then be free'd.

RETURN VALUES:  If successful, returns 0; otherwise -1.

SEARCH TAGS:    ft hashtable_insert_data    ft hashtable_add_entry
                ft ht_insert_data           ft ht_add_entry
— — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

int				hashtable_insert_entry(t_hashtable **table,
									   char *key,
									   void *value)
{
	t_entry			*entry;
	unsigned int	index;

	if (table && *table && key && value)
	{
		if (hashtable_set_appropriate_load_factor(table) == -1)
			return (-1);
		if (!(entry = entry_create(key, value)))
			return (-1);
		index = HASHCODE(key, (*table)->num_buckets);
		entry->successor = ((*table)->bucket_list)[index];
		((*table)->bucket_list)[index] = entry;
		(*table)->entries += 1;
		return (0);
	}
	return (-1);
}



/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
DEPENDENCIES:   ft_strcmp()
                ft_strlen()
                HASHCODE()
                hash()

DESCRIPTION:    Finds and returns (retrieves) an entry.

RETURN VALUES:  If the entry is found, a pointer to the entry is
                returned; otherwise a NULL pointer is returned.

SEARCH TAGS:    ft hashtable_fetch_entry     ft hashtable_fetch_data
                ft hashtable_find_entry      ft hashtable_lookup_entry
                ft ht_fetch_entry            ft ht_fetch_data
                ft ht_find_entry             ft ht_lookup_entry
— — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

t_entry			*hashtable_fetch_entry(t_hashtable *table, char *key)
{
	t_entry			*cur_entry;
	unsigned int	index;

	if (table && key)
	{
		index = HASHCODE(key, table->num_buckets);
		cur_entry = (table->bucket_list)[index];
		while (cur_entry)
		{
			if (ft_strcmp(cur_entry->key, key) == 0)
				return (cur_entry);
			cur_entry = cur_entry->successor;
		}
	}
	return (NULL);
}



/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
DEPENDENCIES:   entry_free()
                ft_strcmp()
                ft_strlen()
                HASHCODE()
                hash()

DESCRIPTION:    Finds and deletes/frees an entry in the hash
                table.

RETURN VALUES:  If the entry is found, and is successfully
                deleted/free'd, the function returns 0;
                otherwise the function returns -1.

SEARCH TAGS:    ft hashtable_delete_data    ft ht_delete_data
                ft hashtable_delete_entry   ft ht_delete_entry
— — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

int				hashtable_delete_entry(t_hashtable **table, char *key)
{
	t_entry			*prev_entry;
	t_entry			*cur_entry;
	unsigned int	index;

	if (table && key)
	{
		index = HASHCODE(key, (*table)->num_buckets);
		cur_entry = ((*table)->bucket_list)[index];
		while (cur_entry)
		{
			if (ft_strcmp(cur_entry->key, key) == 0)
			{
				if (cur_entry == ((*table)->bucket_list)[index])
					((*table)->bucket_list)[index] = cur_entry->successor;
				else
					prev_entry->successor = cur_entry->successor;
				entry_free(&cur_entry);
				(*table)->entries -= 1;
				return (0);
			}
			prev_entry = cur_entry;
			cur_entry = cur_entry->successor;
		}
	}
	return (-1);
}



/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
DEPENDENCIES:   free() , <stdlib.h>
                bucket_free()

DESCRIPTION:    Deletes/frees the entire hash table
                and all the entries contained in it.

RETURN VALUES:  If successful returns 0; otherwise -1.

SEARCH TAGS:    ft hashtable_destroy    ft ht_destroy
— — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

int				hashtable_destroy_table(t_hashtable **table)
{
	unsigned int	i;

	if (table)
	{
		if (*table)
		{
			if ((*table)->bucket_list)
			{
				i = 0;
				while (i < (*table)->num_buckets)
				{
					if (((*table)->bucket_list)[i])
						bucket_free(&((*table)->bucket_list)[i]);
					i++;
				}
				free((*table)->bucket_list);
				(*table)->bucket_list = NULL;
			}
			free(*table);
			(*table) = NULL;
		}
		return (0);
	}
	return (-1);
}



/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
DEPENDENCIES:   hashtable_grow_table()
                hashtable_shrink_table()
                MAX_LOAD_FACTOR
                MIN_LOAD_FACTOR

DESCRIPTION:    Checks that the current load factor is
                neither greater than nor smaller than
                the desired max load factor and desired
                minimum load factor respectively.

                If either is the case, a procedure to
                realloc (grow) or dealloc (shrink) the
                table will ensue.

                If neither is the case, nothing happens.

RETURN VALUES:  If nothing happens, or a successful
                reallocation or deallocation happens,
                0 is returned. If an error occurs -1
                is returned.

SEARCH TAGS:    ft hashtable_set_appropriate_load_factor
                ft ht_set_appropriate_load_factor
                ft hashtable_check_load_factor
                ft ht_check_load_factor
— — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

int				hashtable_set_appropriate_load_factor(t_hashtable **table)
{
	if (table && *table)
	{
		if ((float)(*table)->entries / (float)(*table)->num_buckets
			> MAX_LOAD_FACTOR)
		{
			if (hashtable_grow_table(table) == -1)
				return (-1);
			return (0);
		}
		if ((float)(*table)->entries / (float)(*table)->num_buckets
			< MIN_LOAD_FACTOR)
		{
			if (hashtable_shrink_table(table) == -1)
				return (-1);
			return (0);
		}
		else
		{
			return (0);
		}
	}
	return (-1);
}



/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
DEPENDENCIES:   free() , <stdlib.h>
                hashtable_alloc_table()
                hashtable_rehash_table()
                hashtable_destroy_table()

DESCRIPTION:    Grows the hash table by a factor of 2 and then some
                (inorder to get to the nearest prime number).

RETURN VALUES:  If successful returns 0; otherwise -1.

SEARCH TAGS:    ft hashtable_grow_table       ft ht_grow_table
                ft hashtable_realloc_table    ft ht_realloc_table
— — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

int				hashtable_grow_table(t_hashtable **table)
{
	t_hashtable		*new_table;

	if (table && *table)
	{
		new_table = hashtable_alloc_table((*table)->num_buckets * 2);
		if (new_table == NULL)
			return (-1);
		if (hashtable_rehash_table(table, &new_table) == -1)
			return (-1);
		hashtable_destroy_table(table);
		(*table) = new_table;
		return (0);
	}
	return (-1);
}



/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
DEPENDENCIES:   free() , <stdlib.h>
                hashtable_alloc_table()
                hashtable_rehash_table()
                hashtable_destroy_table()

DESCRIPTION:    Shrinks the hash table by half and then some
                (inorder to get to the nearest prime number).

RETURN VALUES:  If successful returns 0; otherwise -1.

SEARCH TAGS:    ft hashtable_shrink_table    ft ht_shrink_table
                ft hashtable_dealloc_table    ft ht_dealloc_table
— — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

int				hashtable_shrink_table(t_hashtable **table)
{
	t_hashtable		*new_table;

	if (table && *table)
	{
		if ((*table)->num_buckets > 1)
		{
			new_table = hashtable_alloc_table((*table)->num_buckets / 2);
			if (new_table == NULL)
				return (-1);
			if (hashtable_rehash_table(table, &new_table) == -1)
				return (-1);
			hashtable_destroy_table(table);
			(*table) = new_table;
			return (0);
		}
		return (0);
	}
	return (-1);
}



/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
DEPENDENCIES:   ft_strlen()
                HASHCODE()
                hash()

DESCRIPTION:    Rehashs one entry in the 'table_to' hashtable.

RETURN VALUES:  If successful returns 0; otherwise -1.

SEARCH TAGS:    ft hashtable_rehash_entry  ft ht_rehash_entry
— — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

int				hashtable_rehash_entry(t_hashtable **table_to, t_entry **entry)
{
	unsigned int	index;

	if (table_to && *table_to && entry && *entry)
	{
		index = HASHCODE((*entry)->key, (*table_to)->num_buckets);
		(*entry)->successor = ((*table_to)->bucket_list)[index];
		((*table_to)->bucket_list)[index] = (*entry);
		(*table_to)->entries += 1;
		return (0);
	}
	return (-1);
}



/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
DEPENDENCIES:   hashtable_rehash_entry()

DESCRIPTION:    Rehashs all the entries in the hashtable
                'table_from' into the hashtable 'table_to'.

RETURN VALUES:  If successful returns 0; otherwise -1.

SEARCH TAGS:    ft hashtable_rehash_table  ft ht_rehash_table
— — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

int				hashtable_rehash_table(t_hashtable **table_from,
									   t_hashtable **table_to)
{
	t_entry			*cur_entry;
	t_entry			*temp;
	unsigned int	i;

	if (table_from && *table_from && table_to && *table_to)
	{
		i = 0;
		while (i < (*table_from)->num_buckets)
		{
			if (((*table_from)->bucket_list)[i])
			{
				cur_entry = ((*table_from)->bucket_list)[i];
				while (cur_entry)
				{
					temp = cur_entry->successor;
					if (hashtable_rehash_entry(table_to, &cur_entry) == -1)
						return (-1);
					cur_entry = temp;
				}
				((*table_from)->bucket_list)[i] = NULL;
			}
			i++;
		}
	}
	return (((*table_to)->entries == (*table_from)->entries) ? 0 : -1);
}



/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
DEPENDENCIES:   malloc() , <stdlib.h>
                ft_strdup()

DESCRIPTION:    Takes a key and a value and creates an entry out
                of them.

                NOTE: 'value' MUST have previously been
                allocated, otherwise in the free'ing of
                an entry, you WILL get a 'bad free' error.

RETURN VALUES:  If successful, the function returns a pointer
                to the new entry; if an error occurs, it returns
                a NULL pointer.

SEARCH TAGS:    ft entry_create    ft create_entry
— — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

t_entry			*entry_create(char *key, void *value)
{
	t_entry *new_entry;

	if (key && value)
	{
		if (!(new_entry = malloc(sizeof(t_entry))))
			return (NULL);
		new_entry->key = ft_strdup(key);
		new_entry->value = value;
		new_entry->successor = NULL;
		return (new_entry);
	}
	return (NULL);
}



/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
DEPENDENCIES:   free() , <stdlib.h>

DESCRIPTION:    Deletes/frees an entry (this is for use with entries that
                have members that were allocated only).

                NOTE: if 'entry->value' was not allocated somewhere in
                the code, you WILL get a 'bad free' error.

RETURN VALUES:  none.

SEARCH TAGS:    ft entry_free    ft free_entry
— — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

void			entry_free(t_entry **entry)
{
	if (entry && *entry)
	{
		if ((*entry)->key)
			free((*entry)->key);
		if ((*entry)->value)
			free((*entry)->value);
		free(*entry);
		(*entry) = NULL;
	}
}



/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
 * DEPENDENCIES:	entry_free()
 *
 * DESCRIPTION:		Deletes/frees the entire bucket
 * 					(linked list).
 *
 * RETURN VALUES:	none.
 *
 * SEARCH TAGS:		ft bucket_free 		ft free_bucket
 — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

void			bucket_free(t_entry **head)
{
	t_entry	*temp;

	if (head)
	{
		while (*head)
		{
			temp = (*head);
			(*head) = (*head)->successor;
			entry_free(&temp);
		}
	}

}
