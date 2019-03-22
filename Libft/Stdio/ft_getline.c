/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 20:55:59 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/21 21:25:28 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         ft_getline -- get a line from a file
**
**    SYNOPSIS
**         #include "stdio_42.h"
**
**         int
**         ft_getline(const int fd, char **line);
**
**    PARAMETERS
**
**         const int fd        A file descriptor.
**
**         char **line         A pointer to a pointer to a buffer.
**
**    DESCRIPTION
**         Reads a line from a file (delimited by a return line), allocates
**         a buffer the size of the line, copies the line into the buffer
**         and makes 'line' point to it.
**
**         NOTE: free'ing of what 'line' points to is not taken care of.
**
**    RETURN VALUES
**         If a line was successfully read, 1 is returned.
**         If the reading of the file is completed, 0 is returned.
**         If an error occurs, -1 is returned.
*/

#include "../Includes/ft_getline.h"

int		ft_getline(const int fd, char **line)
{
	static t_file		file[MAX_FDS];
	char				tmp[BUFF_SIZE + 1];
	char				*newline;
	ssize_t				ret;

	if (!line || fd < 0 || fd > MAX_FDS || read(fd, tmp, 0) == -1)
		return (-1);
	while (!(newline = ft_strchr(file[fd].cur_pos, '\n')) &&
	(ret = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[ret] = '\0';
		file[fd].cur_pos = ft_strjoin(file[fd].cur_pos, tmp);
		FLUSH(file[fd].buffer);
		file[fd].buffer = file[fd].cur_pos;
	}
	if ((ret == 0 && !file[fd].buffer) || ret == -1)
		return (ret);
	if (newline)
		(*newline) = '\0';
	(*line) = (file[fd].buffer) ? ft_strdup(file[fd].cur_pos) : NULL;
	if (newline && *(newline + 1) != '\0')
		file[fd].cur_pos = newline + 1;
	else
		FLUSH(file[fd].buffer);
	return (*line != NULL);
}
