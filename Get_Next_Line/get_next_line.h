/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:43:17 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/02 16:04:21 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# include "libft/libft.h"

# define BUFF_SIZE 42
# define BREAK_CHECK(expr) if (expr) break

typedef struct	s_filedes_entry
{
	t_list	*buf_list;
	t_list	*buf_tail;
}				t_fdentry;

typedef struct	s_buffer_profile
{
	char	*init_p;
	char	*cur_p;
}				t_buf;

int				get_next_line(const int fd, char **line);

#endif
