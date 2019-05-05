/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 19:31:36 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/04 23:17:58 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/stdlib_42.h"
#include "../Includes/string_42.h"
#include "../Includes/macros_42.h"
#include "../Includes/math_42.h"

#include "../Includes/bigint.h"

t_bigint	bigint_subtracter(t_bigint operand_1, t_bigint operand_2,
				char *base)
{
	(void)operand_1;
	(void)operand_2;
	(void)base;
	return (NULL);
}

t_bigint	bigint_sub(t_bigint operand_1, t_bigint operand_2, char *base)
{
	t_bigint	operand_1_copy;
	t_bigint	operand_2_copy;
	t_bigint	result;

	operand_1_copy = ft_strdup(operand_1);
	operand_2_copy = ft_strdup(operand_2);
	if (!operand_1_copy || !operand_2_copy)
		return (NULL);
	result = arithmetic_dispatcher('-', &operand_1_copy, &operand_2_copy, base);
	free(operand_1_copy);
	free(operand_2_copy);
	return (result);
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

t_bigint	bigint_subfre(t_bigint operand_1, t_bigint operand_2, char *base,
				int free_op)
{
	t_bigint	res;

	res = bigint_sub(operand_1, operand_2, base);
	if (free_op & 1 && operand_1)
		free(operand_1);
	if (free_op & 2 && operand_2)
		free(operand_2);
	return (res);
}
