/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_42.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 11:09:19 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/16 22:31:31 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_42_H
# define MATH_42_H

# define E              2.71828182845
# define PI             3.14159265359
# define GOLDEN_RATIO   1.61803398875

# define ODD(n)     (n % 2 == 1)
# define EVEN(n)    (n % 2 == 0)

# define ABS(x)     ((x < 0) ? (-x) : (x))

# define MAX(x, y)  ((x > y) ? (x) : (y))
# define MIN(x, y)  ((x < y) ? (x) : (y))

double			ft_sqrt(double x);

double			ft_pow(double x, double y);
long double		ft_powl(long double x, long double y);

int				ft_sum(int *vector, unsigned int size);
long			ft_sum_l(long *vector, unsigned int size);
double			ft_sum_d(double *vector, unsigned int size);
long double		ft_sum_ld(long double *vector, unsigned int size);

long double		ft_max(int *vector);
long			ft_max_l(long *vector, unsigned int size);
double			ft_max_d(double *vector, unsigned int size);

long double		ft_min(int *vector);
long			ft_min_l(long *vector, unsigned int size);
double			ft_min_d(double *vector, unsigned int size);

#endif
