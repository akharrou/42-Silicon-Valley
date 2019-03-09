/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket_programming.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 19:36:34 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/09 10:03:17 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCKET_PROGRAMMING_H
# define SOCKET_PROGRAMMING_H

# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include <arpa/inet.h>
# include <netinet/in.h>
# include <sys/socket.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# define TCP 0
# define MAX_CONNECTIONS 5
# define SERVER_PORT 18000
# define LOCAL_HOST "127.0.0.1"
# define SERVER_IP LOCAL_HOST
# define END_MSG "exit\n"
# define END_OF_COMMUNICATION (strcmp(buf, END_MSG) == 0 || buf[0] == '\n')

# define STDIN 0
# define BUFF_SIZE 1024
# define CHECK(expr) if ((expr) == -1) { perror(NULL); exit(EXIT_FAILURE); }

extern int errno;

#endif
