/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoinfre.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 23:25:29 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/25 23:43:03 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         ft_strnjoinfre -- joins two strings to create a third
**
**    SYNOPSIS
**         #include <libft.h>
**
**         char *
**         ft_strnjoinfre(char const *dst, char const *src, size_t len,
**            int free_str);
**
**    PARAMETERS
**
**         char const *dst      Destination string. String to which will
**                              be appended to a list.
**
**         char const *src      Source string, to which we will 'append'
**                              the 'src' string.
**
**         size_t len           Maximum length to be copied.
**
**         int free_str         8 bit integer. The first bit represents
**                              whether or not to free the first string
**                              and the second bit represents whether
**                              or not to free the 2nd string. If both
**                              the first and the 2nd bit are on, then
**                              both strings are free'd.
**
**    DESCRIPTION
**         Joins up to 'n' characters together from the first and
**         second integers
**
**    RETURN VALUES
**         If successful returns 0; otherwise -1.
*/

#include "../Includes/stdlib_42.h"
#include "../Includes/string_42.h"

char	*ft_strnjoinfre(char const *dst, char const *src, size_t len,
			int free_str)
{
	char	*new_str;

	new_str = ft_strnjoin(dst, src, len);
	if (free_str & 1 && dst)
		free((void *)dst);
	if (free_str & 2 && src)
		free((void *)src);
	return (new_str);
}
