/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoinfre.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 23:25:29 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/26 23:26:09 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         ft_strnjoinfre -- joins at most 'n' characters from two strings
**                           to create a third
**
**    SYNOPSIS
**         #include <libft.h>
**
**         char *
**         ft_strnjoinfre(char const *s1, char const *s2, size_t len,
**            int free_str);
**
**    PARAMETERS
**
**         char const *s1       Destination string to which we will
**                              appended the second string.
**
**         char const *s2       Source string that will be appended.
**                              to the destination string.
**
**         size_t len           Maximum length of the created string.
**
**         int free_str         8 bit integer.
**
**                              The first bit represents whether or
**                              not to free the first string. The
**                              second bit represents whether or not
**                              to free the 2nd string. Finally, If
**                              both the first and the 2nd bit are on,
**                              then both strings are free'd.
**
**    DESCRIPTION
**         Joins up to 'n' characters together from the first and
**         second strings to form a third.
**
**    RETURN VALUES
**         If successful returns the newly created string; otherwise NULL.
*/

#include "../Includes/stdlib_42.h"
#include "../Includes/string_42.h"

char	*ft_strnjoinfre(char const *s1, char const *s2, size_t len,
			int free_str)
{
	char	*new_str;

	new_str = ft_strnjoin(s1, s2, len);
	if (free_str & 1 && s1)
		free((void *)s1);
	if (free_str & 2 && s2)
		free((void *)s2);
	return (new_str);
}
