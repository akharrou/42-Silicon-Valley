/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:08:52 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/17 04:57:05 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#include "../Includes/ctype_42.h"
#include "../Includes/stdlib_42.h"
#include "../Includes/string_42.h"
#include "../Includes/macros.h"

static int	valid_base(char *base_str)
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

char	*ft_itoa_base(int n, char *base, int padding, char pad)
{
	unsigned short	intbase;
	unsigned short	col;
	unsigned int	val;
	char			*buf;
	char			*cur;

	if (!valid_base(base))
		return (NULL);
	col = ft_intlen_base(n, ft_strlen(base)) + (n < 0);
	col += (padding - col > 0) ? padding - col : 0;
	if (!(buf = malloc(col + 1)))
		return (NULL);
	cur = buf;
	cur[col--] = '\0';
	ft_memset(cur, pad, col);
	if (n < 0)
		(*cur++) = '-';
	intbase = ft_strlen(base);
	val = (n < 0) ? -n : n;
	while (cur - buf <= col)
	{
		(*cur++) = base[val % intbase];
		val /= intbase;
	}
	return (ft_strrev(buf));
}


/*
 *
 * TEST MAIN
 *
 */

int		main(int ac, char *av[])
{
	if (ac != 5)
	{
		printf("Usage: ./a integer base_system padding pad\n");
		return (1);
	}

	printf("%s\n", ft_itoa_base(atoi(av[1]), av[2], atoi(av[3]), av[4][0]));

	return (0);
}
