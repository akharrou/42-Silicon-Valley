/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 08:29:41 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/21 19:25:04 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETLINE_H
# define FT_GETLINE_H

# include "stdio_42.h"
# include "stdlib_42.h"
# include "string_42.h"
# include "macros.h"

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct	s_file_reader
{
	char	*buffer;
	char	*cur_pos;
}				t_file;

int				ft_getline(const int fd, char **line);

#endif
