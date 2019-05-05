/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 23:26:37 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/04 19:34:11 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/stdlib_42.h"
#include "../Includes/string_42.h"
#include "../Includes/macros_42.h"
#include "../Includes/math_42.h"

#include "../Includes/bigint.h"

t_bigint	bigint_addition(t_bigint operand_1, t_bigint operand_2, char *base)
{
	int		intbase;
	int		carry;
	int		sum;
	int		i;

	operand_1 = (t_bigint)ft_strdup(operand_1);
	operand_2 = (t_bigint)ft_strdup(operand_2);
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

t_bigint	bigint_add(t_bigint operand_1, t_bigint operand_2, char *base)
{
	return (arithmetic_dispatcher('+', operand_1, operand_2, base));
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
**         - t_bigint operand_1
**         - t_bigint operand_2
*/

t_bigint	bigint_addfre(t_bigint operand_1, t_bigint operand_2, char *base,
				int free_op)
{
	t_bigint	res;

	res = bigint_add(operand_1, operand_2, base);
	if (free_op & 1 && operand_1)
		free((void *)operand_1);
	if (free_op & 2 && operand_2)
		free((void *)operand_2);
	return (res);
}
