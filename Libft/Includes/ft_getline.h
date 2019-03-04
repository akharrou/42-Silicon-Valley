/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 08:29:41 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/04 10:10:17 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETLINE_H
# define FT_GETLINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# include "libft.h"

# define GETLINE_BUFF_SIZE 256

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
int				ft_read_line(int fd, char **line, t_fdentry **fd_entry);
int				ft_copy_line(char **dest, t_fdentry **fd_entry);

#endif
