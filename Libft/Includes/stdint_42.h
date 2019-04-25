/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdint_42.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 12:03:50 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/25 07:52:25 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STDINT_42_H
# define STDINT_42_H

# include <stddef.h>
# include <stdint.h>

typedef union				u_data
{
	char					*str_;
	signed char				char_;
	signed short			short_;
	signed int				int_;
	signed long				long_;
	signed long long		long_long_;
	unsigned char			uchar_;
	unsigned short			ushort_;
	unsigned int			uint_;
	unsigned long			ulong_;
	unsigned long long		ulong_long_;
	double					double_;
	long double				long_double_;
	intmax_t				intmax_;
	uintmax_t				uintmax_;
	intptr_t				intptr_;
	uintptr_t				uintptr_;
	ptrdiff_t				ptrdiff_;
	size_t					size_;
}							t_data;

#endif
