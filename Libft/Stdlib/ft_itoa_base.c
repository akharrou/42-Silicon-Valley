/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:08:52 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/17 03:43:42 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ctype_42.h"
#include "../Includes/stdlib_42.h"
#include "../Includes/string_42.h"
#include "../Includes/macros.h"

static int	ft_validate_base_system(char *base_str)
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

char		*ft_itoa_base(long nbr, char *base)
{
	int		i;
	int		quotient;
	long	base_len;
	long	col;
	char	*buf;

	i = 0;
	if (!ft_validate_base_system(base) || !(buf = (char*)malloc(34)))
		return (NULL);
	base_len = ft_strlen(base);
	col = base_len;
	if (nbr < 0)
		buf[i++] = '-';
	nbr = (nbr < 0) ? -nbr : nbr;
	while (col <= nbr)
		col *= base_len;
	while (col > 1)
	{
		col /= base_len;
		(quotient = nbr / col);
		buf[i++] = base[quotient];
		nbr -= (quotient * col);
	}
	buf[i] = '\0';
	return (buf);
}


int		ft_intlen_base(int n, unsigned int base)
{
	unsigned int num;
	unsigned int length;

	length = 1;
	num = (n < 0) ? -n : n;
	while (num >= base)
	{
		num /= base;
		++length;
	}
	return (length);
}

char	*ft_itoa_rec(unsigned int num, int base, char *base_str, char *buf, int i)
{
	if (num >= (unsigned int)base)
		buf = ft_itoa_rec(num / base, base, base_str, buf, i - 1);
	buf[i] = base_str[num % base];
	return (buf);
}

char	*ft_itoa_base(int value, char *base)
{
	int				sign;
	char			*buf;
	unsigned int	num;
	unsigned int    intlen;

	if (!ft_validate_base_system(base))
		return (NULL);
	intlen = ft_intlen_base(value, (unsigned int)base);
	sign = (value < 0 && base == 10) ? 1 : 0;
	if (!(buf = (char *)malloc(intlen + sign + 1)))
		return (NULL);
	buf[intlen + sign] = '\0';
	if (sign)
		buf[0] = '-';
	num = (sign) ? -value : value;
	buf = ft_itoa_rec(num, base, base_str, buf, intlen + sign - 1);
	return (buf);
}



char	*ft_itoa_base(int n, char *base, int padding, char pad)
{
	unsigned int	val;
	unsigned short	col;
	char			*buf;

	if (!valid_base(base))
		return (NULL);
	col = ft_intlen_base(n, base);
	col += padding - col;
	if (!(buf = malloc(col + 1)))
		return (NULL);
	buf[col] = '\0';
	ft_memset(buf, pad, col);
	if (n < 0)
		(*buf) = '-';
	val = n * -(n < 0);
	while (col)
	// place the negative sign if number is negative
	// turn number to positive if negative
	// start grabbing values individually and storing them
	// return buf
	return (buf);
}
