/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_42.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 11:09:19 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/12 11:14:32 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_42_H
# define MATH_42_H

# define PI 3.14

# define EVEN(n)    (n % 2 == 0)
# define ODD(n)     (n % 2 == 1)
# define ABS(x)     ((x < 0) ? (-x) : (x))
# define MAX(x, y)  ((x > y) ? (x) : (y))
# define MIN(x, y)  ((x < y) ? (x) : (y))

long double		ft_pow(int nb, int power);

#endif
