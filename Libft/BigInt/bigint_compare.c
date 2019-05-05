/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_compare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 19:53:44 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/04 21:23:56 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/string_42.h"
#include "../Includes/stdlib_42.h"

#include "../Includes/bigint.h"

int		bigint_compare(t_bigint operand_1, t_bigint operand_2)
{
	int res;

	operand_1 = ft_strdup(operand_1);
	operand_2 = ft_strdup(operand_2);
	if (!operand_1 || !operand_2)
		return (0);
	normalize_bigint(&operand_1, &operand_2);
	if (!(operand_1[0] == '-') && (operand_2[0] == '-'))
		res = 1;
	else if ((operand_1[0] == '-') && !(operand_2[0] == '-'))
		res = -1;
	else if ((operand_1[0] == '-') && (operand_2[0] == '-'))
		res = -ft_strcmp(operand_1, operand_2);
	else
		res = ft_strcmp(operand_1, operand_2);
	free(operand_1);
	free(operand_2);
	return (res);
}
