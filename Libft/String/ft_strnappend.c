/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnappend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 23:27:19 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/26 00:00:21 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/string_42.h"

char	*ft_strnappend(char const *dst, char const *src, size_t len,
			int free_str)
{
	return (ft_strnjoinfre(dst, src, len, free_str));
}
