/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:36:08 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/08 23:52:13 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket_programming.h"

void	communicate(int client_sockfd, struct sockaddr_in client_addr)
{
	char buf[BUFF_SIZE];

	printf("Connection Established with —> %i on port %i.\n",client_addr.sin_addr.s_addr, client_addr.sin_port);
	while (1)
	{
		bzero(buf, sizeof(buf));
		if ((read(client_sockfd, buf, BUFF_SIZE)) > 1)
		{
			if (END_OF_COMMUNICATION)
			{
				printf("Connection Interrupted.\n");
				return ;
			}
			write(client_sockfd, "pong pong\n", 10);
		}
	}
}

void	make_daemon(int ac, char *arg)
{
	if (ac == 2 && arg && strcmp(arg, "-D") == 0)
		daemon(1, 1);
	else
	{
		printf("Invalid Argument.\n");
		exit(EXIT_FAILURE);
	}
}

int		main(int ac, char *av[])
{
	struct sockaddr_in	server_address;
	struct sockaddr_in	client_address;

	int					server_socket_fd;
	int					client_socket_fd;
	int					client_address_size;

	if (ac > 1)
		make_daemon(ac, av[1]);

	/* Create Socket */
	CHECK(server_socket_fd = socket(AF_INET, SOCK_STREAM, TCP));

	/* Setup Server Address */
	bzero(&server_address, sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(SERVER_PORT);
	server_address.sin_addr.s_addr = htonl(INADDR_ANY);

	/* Bind Socket to the Server Address */
	CHECK(bind(  server_socket_fd,
                 (const struct sockaddr *)&server_address,
                 (socklen_t)sizeof(server_address)          ));

	while (1)
	{
		/* Listen for Incoming Connections */
		listen(server_socket_fd, MAX_CONNECTIONS);

		/* Accept Enqueued Connection(s) */
		client_address_size = sizeof(client_address);
		CHECK(client_socket_fd = accept(  server_socket_fd,
                                          (struct sockaddr *)&client_address,
                                          (socklen_t *)&client_address_size	 ));

		/* Communicate */
		communicate(client_socket_fd, client_address);
	}
	return (0);
}


/*
**
** 1)
**      Set up a Communication Endpoint (a socket) on which the Server
**      will listen at for new Connections. We'll use socket(2) to create
**      the socket.
**
**      int domain: PF_INET <==> AF_INET —> (internet protocal (ipv4))
**      int type:   SOCK_STREAM —> (sequenced, reliable, two-way connection
**                                  based byte streams)
**      int protocol: 0 <==> TCP or UDP
**
**
** 2)
**      Then we have to set up the server address & bind the socket to it.
**      we'll use bind(2) for that.
**
**      Socket address, internet style (structure):
**
**             struct sockaddr_in {
**                 __uint8_t     sin_len;
**                 sa_family_t   sin_family;
**                 in_port_t     sin_port;
**                 struct        in_addr sin_addr;
**                 char          sin_zero[8];
**             };
**
**
** 3)
**      Make the Socket passively listen for new Connections with listen(2).
**      Calling this syscall also has the effect of moving our socket to a
**      different state.
**
**      Instead of CLOSED, now the socket is put into LISTEN state (represents
**      waiting for a connection request from any remote TCP and port -
**      RFC 793 - TCP).
**
**
**      Now once connections start landing, they are stored in 2 different
**      queues.
**
**      One is a waiting list for those connections that landed but haven't
**      finished the three-way handshake, and the second queue is the queue for
**      those connections that have completed the three-way handshake and are
**      ready for communication
**
**
** 4)
**      Once we have completed connections, we can call accept(2). This system
**      call will look through the queue of completed connections, pop the
**      first one off and get a file descriptor to the application it is from,
**      essentially allowing to read and write (send and recieve) to that file
**      descriptor (appilication) data.
**
**      If the queue is empty, it just does nothing.
**
*/

