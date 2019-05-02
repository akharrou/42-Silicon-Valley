/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 23:26:37 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/02 15:22:00 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../Includes/stdlib_42.h"
#include "../Includes/string_42.h"
#include "../Includes/macros_42.h"
#include "../Includes/math_42.h"

static void	normalize_integers(char **op_1, char **op_2)
{
	size_t	len_1;
	size_t	len_2;

	len_1 = ft_strlen(*op_1);
	len_2 = ft_strlen(*op_2);
	if (len_1 > len_2)
		(*op_2) = ft_strprepend(*op_2, ft_padding(len_1 - len_2, '0'), 1, 1);
	else if (len_1 < len_2)
		(*op_1) = ft_strprepend(*op_1, ft_padding(len_2 - len_1, '0'), 1, 1);
}

static void	normalize_decimals(char **op_1, char **op_2)
{
	char		*decpt_1;
	char		*decpt_2;
	intmax_t	decimals_1;
	intmax_t	decimals_2;

	decpt_1 = ft_strchr(*op_1, '.');
	decpt_2 = ft_strchr(*op_2, '.');
	decimals_1 = (decpt_1) ? ft_strlen(*op_1) - 1 - (decpt_1 - (*op_1)) : 0;
	decimals_2 = (decpt_2) ? ft_strlen(*op_2) - 1 - (decpt_2 - (*op_2)) : 0;
	if (decpt_1 && !decpt_2)
		(*op_2) = ft_strappend(
			*op_2, ft_strjoinfre(".", ft_padding(decimals_1, '0'), 0, 1), 1, 1);
	else if (!decpt_1 && decpt_2)
		(*op_1) = ft_strappend(
			*op_1, ft_strjoinfre(".", ft_padding(decimals_2, '0'), 0, 1), 1, 1);
	else if (decpt_1 && decpt_2)
	{
		if (decimals_1 > decimals_2)
			(*op_2) = ft_strappend(
				*op_2, ft_padding(decimals_1 - decimals_2, '0'), 1, 1);
		if (decimals_1 < decimals_2)
			(*op_1) = ft_strappend(
				*op_1, ft_padding(decimals_2 - decimals_1, '0'), 1, 1);
	}
}

char		*ft_stradd(char *operand_1, char *operand_2, char *base)
{
	int		intbase;
	int		carry;
	int		sum;
	int		i;

	operand_1 = ft_strdup(operand_1);
	operand_2 = ft_strdup(operand_2);
	/** TODO
	 * PASS CERTAIN CASES TO THE STRSUB FUNCTION.
	*/
	normalize_decimals(&operand_1, &operand_2);
	normalize_integers(&operand_1, &operand_2);
	carry = 0;
	intbase = ft_strlen(base);
	i = ft_strlen(operand_1);
	while (--i >= 0)
	{
		if (operand_1[i] == '.')
			--i;
		sum = carry + INT(operand_1[i], base) + INT(operand_2[i], base);
		operand_1[i] = base[sum % intbase];
		carry = sum >= intbase;
	}
	if (carry)
		operand_1 = ft_strprepend(operand_1, "1", 1, 0);
	free(operand_2);
	return (operand_1);
}

/*
**    DESCRIPTION
**         Wrapper function that allows to clean up & free certain variables
**         after function execution.
**
**    PARAMETERS
**
**         int free_op         Integer who's first 2 bits are used as
**                             booleans.
**
**                             If the first bit is on, then the first
**                             parameter is free'd.
**
**                             If the second bit is on, then the second
**                             parameter is free'd.
**
**    FREE'D PARAMETERS
**
**         - char *operand_1
**         - char *operand_2
*/

char		*ft_straddfre(char *operand_1, char *operand_2, char *base,
				int free_op)
{
	char	*res;

	res = ft_stradd(operand_1, operand_2, base);
	if (free_op & 1 && operand_1)
		free((void *)operand_1);
	if (free_op & 2 && operand_2)
		free((void *)operand_2);
	return (res);
}

// int		main(void)
// {

// 	char *op1 = strdup("9999999999.999999");
// 	char *op2 = strdup("0.000001");

// 	printf("%s\n", ft_strsub(op1, op2, DECIMAL_BASE));

// 	return (0);
// }




// char		*ft_strsub(char *operand_1, char *operand_2, char *base)
// {

// 	/** TODO
// 	 *
// 	 * 1. KEEP TRACK OF SIGN OF BOTH OPERANDS
// 	 * 2. DETERMINE WHAT CASE THE CURRENT SITUATION IS AND DELEGATE
// 	 *
// 	 *
// 	 *
// 	 * 	  CASE 1:
// 	 *
// 	 *
// 	 *
// 	 *
// 	 *
// 	 *
// 	 *
// 	 *
// 	 *
// 	 *
// 	 *
// 	 *
// 	 *
// 	 *
// 	 *
// 	 *
// 	 *
// 	 *
// 	 *
// 	 *
// 	 *
// 	 *
// 	 *
// 	 *
// 	 *
// 	 *
// 	 *
// 	 *
// 	 *
// 	 *
// 	 *
// 	 *
// 	 *
// 	 *
// 	 *
// 	*/

// }
