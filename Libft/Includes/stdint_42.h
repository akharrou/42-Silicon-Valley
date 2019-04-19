/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdint_42.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 12:03:50 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/18 18:48:14 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STDINT_42_H
# define STDINT_42_H

typedef char				t_bool;
typedef char				t_char;

typedef unsigned char		t_uint8;
typedef unsigned short		t_uint16;
typedef unsigned long		t_uint32;
typedef unsigned long long	t_uint64;

typedef signed char			t_int8;
typedef signed short		t_int16;
typedef signed long			t_int32;
typedef signed long long	t_int64;

unsigned int				ft_hash(const char *str);

#endif
