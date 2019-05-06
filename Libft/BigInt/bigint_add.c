/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 23:26:37 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/05 19:38:21 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/stdlib_42.h"
#include "../Includes/string_42.h"
#include "../Includes/macros_42.h"
#include "../Includes/math_42.h"

#include "../Includes/bigint.h"

t_bigint		bigint_adder(t_bigint operand_1, t_bigint operand_2, char *base)
{
	char		*result;
	int8_t		intbase;
	int32_t		carry;
	int32_t		sum;
	int32_t		i;

	result = ft_strdup(operand_1);
	intbase = ft_strlen(base);
	i = ft_strlen(result);
	carry = 0;
	while (--i >= 0)
	{
		if (result[i] == '.')
			--i;
		sum = carry + INT(operand_1[i], base) + INT(operand_2[i], base);
		result[i] = base[sum % intbase];
		carry = sum >= intbase;
	}
	if (carry)
		result = ft_strprepend(result, "1", 1, 0);
	bigint_cleaner(&result);
	return (result);
}

t_bigint	bigint_add(t_bigint operand_1, t_bigint operand_2, char *base)
{
	t_bigint	operand_1_copy;
	t_bigint	operand_2_copy;
	t_bigint	result;

	operand_1_copy = ft_strdup(operand_1);
	operand_2_copy = ft_strdup(operand_2);
	if (!operand_1_copy || !operand_2_copy)
		return (NULL);
	result = arithmetic_dispatcher('+', &operand_1_copy, &operand_2_copy, base);
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

t_bigint	bigint_addfre(t_bigint operand_1, t_bigint operand_2, char *base,
				int free_op)
{
	t_bigint	res;

	res = bigint_add(operand_1, operand_2, base);
	if (free_op & 1 && operand_1)
		free(operand_1);
	if (free_op & 2 && operand_2)
		free(operand_2);
	return (res);
}

// /*
//  *
//  * TEST MAIN
//  *
//  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

// int		main(int ac, char **av)
// {

// 	printf("%s\n", bigint_add(av[1], av[2], DECIMAL_BASE));
// 	printf("%s\n", bigint_sub(av[1], av[2], DECIMAL_BASE));

// 	(void)ac;
// 	return (0);
// }


void	remove_trailing_zero(char *num)
{
	int i;

	i = strlen(num);
	while (num[--i] == '0')
		num[i] = '\0';
	if (num[i] == '.')
		num[i + 1] = '0';
}

void	test_case(char *operand_1, char *operand_2)
{
	char		*temp1;
	char		*temp2;

	char		*op1 = strdup(operand_1);
	char		*op2 = strdup(operand_2);
	long double	num1 = atof(op1);
	long double num2 = atof(op2);

	asprintf(&temp2, "%Lf", (num1 - num2));
	asprintf(&temp1, "%Lf", (num1 + num2));

	// remove_trailing_zero(temp1);
	// remove_trailing_zero(temp2);

	printf("MINE:	ADD: %-45s SUB: %-45s\n",
		bigint_add(op1, op2, DECIMAL_BASE), bigint_sub(op1, op2, DECIMAL_BASE));
	printf("SYST:	ADD: %-45s SUB: %-45s\n", temp1, temp2);
	printf("\n");
}

int main(void)
{
	/*
	** As per the photo of the cases
	*/
	test_case("73", "11");
	test_case("73", "-11");
	test_case("73", "-81");
	test_case("81", "-81");
	test_case("-83", "73");
	test_case("-11", "73");
	test_case("-81", "81");
	test_case("-73", "-11");
	test_case("11", "-73");
	test_case("-11", "73");

	/*
	** Other Test
	*/

	test_case("-1.000000001", "0.000000002");
	test_case("12345", "3456");
	test_case("3456", "12345");

	test_case("345600000", "12345");

	test_case("345600000", "12345");
	test_case("3.45600000", "12345");

	test_case("0", "0");
	test_case("-0", "-0");

	test_case("-123", "-31253234626376574678759897689877");


	// test_case()
	return (0);
}
