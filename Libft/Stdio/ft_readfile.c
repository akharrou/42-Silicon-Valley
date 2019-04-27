/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 22:53:51 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/26 22:58:33 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/stdio_42.h"
#include "../Includes/string_42.h"

char	*ft_readfile(int filedes)
{
	char	*file;
	char	*line;

	while (ft_readline(filedes, &line))
		file = ft_strappend(file, line, 1, 1);
	return (file);
}
