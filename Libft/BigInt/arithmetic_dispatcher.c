/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic_dispatcher.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:14:42 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/04 23:22:35 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/stdlib_42.h"
#include "../Includes/string_42.h"
#include "../Includes/bigint.h"

t_bigint	arithmetic_dispatcher(char operation, t_bigint *operand_1,
				t_bigint *operand_2, char *base)
{
	t_bigint	result;

	result = NULL;
	normalize_bigint(operand_1, operand_2);
	if (operation == '+')
		result = bigint_adder(*operand_1, *operand_2, base);
	else
		result = bigint_subtracter(*operand_1, *operand_2, base);
	return (result);
}
