/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:44:08 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/06 11:33:22 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		tt_btyes(t_fdentry *fdentry)
{
	int		tt_bytes;
	int		list_size;
	char	*cur_buf;

	tt_bytes = 0;
	cur_buf = ((t_buf *)(fdentry)->buf_list->item)->cur_p;
	while (*cur_buf != '\n' && *cur_buf != '\0')
	{
		++cur_buf;
		++tt_bytes;
	}
	list_size = list_count((fdentry)->buf_list) - 2;
	if (list_size > 0)
		tt_bytes += list_size * BUFF_SIZE;
	if ((fdentry)->buf_tail != (fdentry)->buf_list)
	{
		cur_buf = ((t_buf *)(fdentry)->buf_tail->item)->cur_p;
		while (*cur_buf != '\n' && *cur_buf != '\0')
		{
			++cur_buf;
			++tt_bytes;
		}
	}
	return (tt_bytes);
}

static int		ft_copy_line(char **dest, t_fdentry **fd_entry)
{
	int		j;
	int		tt_line_bytes;
	t_buf	*tmp;

	tt_line_bytes = tt_btyes(*fd_entry);
	MALLOC_GUARD((*dest) = (char *)malloc(tt_line_bytes + 1), -1);
	(*dest)[tt_line_bytes] = '\0';
	j = 0;
	while ((*fd_entry)->buf_list)
	{
		tmp = (t_buf *)list_popleft(&((*fd_entry)->buf_list));
		while (*(tmp->cur_p) != '\0' && *(tmp->cur_p) != '\n')
			(*dest)[j++] = *(tmp->cur_p)++;
		if (!(*(tmp->cur_p) == '\n' && *(tmp->cur_p + 1) == '\0') &&
		*(tmp->cur_p++) != '\0')
		{
			list_append(&(*fd_entry)->buf_list, tmp);
			break ;
		}
		free(tmp->init_p);
		free(tmp);
	}
	(*fd_entry)->buf_tail = (*fd_entry)->buf_list;
	return (1);
}

static int		ft_read_line(int fd, char **line, t_fdentry **fd_entry)
{
	int		res;
	t_buf	*buf;

	res = -1;
	buf = NULL;
	if ((*fd_entry)->buf_list)
		buf = (t_buf *)((*fd_entry)->buf_list->item);
	while (1)
	{
		if (buf && ft_strchr(buf->cur_p, '\n'))
			return (ft_copy_line(line, fd_entry));
		MALLOC_GUARD(buf = (t_buf *)malloc(sizeof(t_buf)), -1);
		BREAK_CHECK(!(buf->init_p = (char *)malloc(BUFF_SIZE + 1)));
		res = read(fd, buf->init_p, BUFF_SIZE);
		BREAK_CHECK(res < 1);
		buf->init_p[res] = '\0';
		buf->cur_p = buf->init_p;
		list_append_both(&(*fd_entry)->buf_list, &(*fd_entry)->buf_tail, buf);
	}
	if (buf->init_p)
		free(buf->init_p);
	free(buf);
	if (res == 0 && (*fd_entry)->buf_list)
		return (ft_copy_line(line, fd_entry));
	return (res);
}

int				get_next_line(const int fd, char **line)
{
	static t_dict	*filedes_table = NULL;
	t_fdentry		*fd_entry;
	int				ret;

	if (fd > -1 && line && read(fd, &ret, 0))
	{
		if ((ret = dict_getindex(filedes_table, (char *)&fd)) == -1)
		{
			MALLOC_GUARD(fd_entry = (t_fdentry *)malloc(sizeof(t_fdentry)), -1);
			fd_entry->buf_list = NULL;
			fd_entry->buf_tail = NULL;
			ret = dict_insert(&filedes_table, (char *)&fd, fd_entry);
		}
		if ((fd_entry = dict_getitem_fast(filedes_table, (char *)&fd, ret)))
		{
			if ((ret = ft_read_line(fd, line, &fd_entry)) == 1)
				return (1);
			dict_remove(&filedes_table, (char *)&fd);
			if (filedes_table->entries == 0)
				dict_clear(&filedes_table);
			return (ret);
		}
	}
	return (-1);
}
