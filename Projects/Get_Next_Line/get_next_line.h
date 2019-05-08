/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:15:35 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/21 18:37:31 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# define MAX_FDS 65536
# define BUFF_SIZE 42

typedef struct	s_file_reader
{
	char	*buffer;
	char	*cur_pos;
}				t_file;

int				get_next_line(const int fd, char **line);

#endif
