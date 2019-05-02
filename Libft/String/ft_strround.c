/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strround.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 10:26:49 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/02 15:03:22 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         ft_strround -- round a number (that is in the form of a string)
**
**    SYNOPSIS
**         #include <libft.h>
**
**         char *
**         ft_strround(char *numstr, char *base, int precision);
**
**    PARAMETERS
**
**         char *numstr               Brief
**
**         char *base                 Brief
**
**         int precision              Brief
**
**    DESCRIPTION
**         Description.
**
**    RETURN VALUES
**         If successful returns 0; otherwise -1.
*/

#include "../Includes/string_42.h"
#include "../Includes/stdlib_42.h"
#include "../Includes/macros_42.h"

char		*ft_strround(char *numstr, char *base, int precision)
{
	char	*incrementor;
	char	*decimalpt;
	int		decimals;
	int		len;

	numstr = ft_strdup(numstr);
	if (!ft_strchr(numstr, '.'))
		numstr = ft_strappend(numstr, ".000000", 1, 0);
	len = ft_strlen(numstr);
	decimalpt = ft_strchr(numstr, '.');
	decimals = (len - 1) - (decimalpt - numstr);
	if (precision < 1)
		return (ft_strndupfre(numstr, len - (decimals + 1), 1));
	else if (decimals <= precision)
		numstr = ft_strappend(
			numstr, ft_padding(precision - decimals, '0'), 1, 1);
	else if (INT(decimalpt[precision + 1], base) >= (long)ft_strlen(base) / 2)
	{
		incrementor = ft_strappend(ft_strappend(
			ft_strdup("0."), ft_padding(precision - 1, '0'), 1, 1), "1", 1, 0);
		numstr = ft_straddfre(numstr, incrementor, base, 3);
	}
	numstr[(ft_strchr(numstr, '.') - numstr) + 1 + precision] = '\0';
	return (numstr);
}

/*
**    DESCRIPTION
**         Wrapper function that allows to clean up & free certain variables
**         after function execution.
**
**    PARAMETERS
**
**         int free_numstr         Integer (boolean) to signal whether
**                                 or not to free the variable(s).
**
**    FREE'D PARAMETERS
**
**         - char *numstr
*/

char		*ft_strroundfre(char *numstr, char *base, int precision,
				int free_numstr)
{
	char	*res;

	res = ft_strround(numstr, base, precision);
	if (free_numstr && numstr)
		free((void *)numstr);
	return (res);
}

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —  */

// #include <stdio.h>
// #include <unistd.h>

// int		main(void)
// {

// 	// char	*op1 = strdup("9232.32522836");
// 	// char	*op1 = strdup("0.32522836");
// 	// char	*op1 = strdup("0.2999999999");
// 	char	*op1 = strdup("28379429620346230846238745238452342387452634502738548238475230423253420234528342735.02739472093742374023847902801273487230942634");
// 	// char	*op1 = strdup("5a.5a8");

// 	char	*tmp;

// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   -100,    0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   -1,      0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   0,       0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   1,       0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   2,       0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   3,       0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   4,       0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   5,       0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   6,       0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   7,       0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   8,       0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   9,       0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   10,      0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   11,      0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   12,      0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   13,      0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   14,      0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   15,      0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   16,      0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   17,      0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   18,      0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   19,      0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   20,      0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   21,      0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   22,      0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   23,      0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   24,      0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   25,      0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   26,      0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   27,      0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   28,      0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   29,      0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   30,      0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   31,      0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   32,      0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   33,      0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   34,      0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   35,      0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   36,      0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   37,      0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   38,      0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   39,      0  ))); free(tmp);
// 	printf("%s\n", (tmp = ft_strroundfre(  op1,   DECIMAL_BASE,   40,      1  )));

// 	// printf("%s\n", (tmp = ft_strround(  op1,   DECIMAL_BASE,   -100  )));  free(tmp);
// 	// printf("%s\n", (tmp = ft_strround(  op1,   DECIMAL_BASE,   -1    )));  free(tmp);
// 	// printf("%s\n", (tmp = ft_strround(  op1,   DECIMAL_BASE,   0     )));  free(tmp);
// 	// printf("%s\n", (tmp = ft_strround(  op1,   DECIMAL_BASE,   1     )));  free(tmp);
// 	// printf("%s\n", (tmp = ft_strround(  op1,   DECIMAL_BASE,   2     )));  free(tmp);
// 	// printf("%s\n", (tmp = ft_strround(  op1,   DECIMAL_BASE,   3     )));  free(tmp);
// 	// printf("%s\n", (tmp = ft_strround(  op1,   DECIMAL_BASE,   4     )));  free(tmp);
// 	// printf("%s\n", (tmp = ft_strround(  op1,   DECIMAL_BASE,   5     )));  free(tmp);
// 	// printf("%s\n", (tmp = ft_strround(  op1,   DECIMAL_BASE,   6     )));  free(tmp);
// 	// printf("%s\n", (tmp = ft_strround(  op1,   DECIMAL_BASE,   7     )));  free(tmp);
// 	// printf("%s\n", (tmp = ft_strround(  op1,   DECIMAL_BASE,   8     )));  free(tmp);
// 	// printf("%s\n", (tmp = ft_strround(  op1,   DECIMAL_BASE,   9     )));  free(tmp);
// 	// printf("%s\n", (tmp = ft_strround(  op1,   DECIMAL_BASE,   10    )));  free(tmp);
// 	// printf("%s\n", (tmp = ft_strround(  op1,   DECIMAL_BASE,   11    )));  free(tmp);
// 	// printf("%s\n", (tmp = ft_strround(  op1,   DECIMAL_BASE,   12    )));  free(tmp);
// 	// printf("%s\n", (tmp = ft_strround(  op1,   DECIMAL_BASE,   13    )));

// 	// printf("%s\n", (tmp = ft_strroundfre(  op1,   HEX_LOWER_BASE,   0,    0  ))); free(tmp);
// 	// printf("%s\n", (tmp = ft_strroundfre(  op1,   HEX_LOWER_BASE,   1,    0  ))); free(tmp);
// 	// printf("%s\n", (tmp = ft_strroundfre(  op1,   HEX_LOWER_BASE,   2,    0  ))); free(tmp);
// 	// printf("%s\n", (tmp = ft_strroundfre(  op1,   HEX_LOWER_BASE,   3,    0  ))); free(tmp);
// 	// printf("%s\n", (tmp = ft_strroundfre(  op1,   HEX_LOWER_BASE,   4,    0  ))); free(tmp);
// 	// printf("%s\n", (tmp = ft_strroundfre(  op1,   HEX_LOWER_BASE,   5,    1  )));

// 	sleep(1);

// 	return (0);
// }
