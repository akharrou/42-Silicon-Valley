/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcp_client.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:36:10 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/09 10:19:24 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket_programming.h"

void	ping(int sockfd, struct sockaddr_in server_addr, int ntimes)
{
	char	buf[BUFF_SIZE];

	printf("Connection Established with —> %i on port %i.\n",server_addr.sin_addr.s_addr, server_addr.sin_port);
	while (--ntimes > -1)
	{
		sleep(2);
		bzero(buf, BUFF_SIZE);

		/* Ping Server */
		printf("\nFrom Client:\nping\n");
		sleep(2);
		write(sockfd, "ping\n", 5);

		bzero(buf, BUFF_SIZE);

		/* Read & Display Reponse */
		read(sockfd, buf, BUFF_SIZE);
		printf("\nFrom Server:\n%s", buf);
	}
	sleep(1);
	write(sockfd, END_MSG, strlen(END_MSG));
}

void	chat(int sockfd, struct sockaddr_in server_addr)
{
	char	buf[BUFF_SIZE];
	int		i;

	printf("Connection Established with —> %i on port %i.\n",server_addr.sin_addr.s_addr, server_addr.sin_port);
	while (1)
	{
		/* Type Message */
		bzero(buf, BUFF_SIZE);
		printf("\nFrom Client:\n");
		i = 0;
		while ((buf[i] = getchar()) != '\n')
			i++;

		/* Terminate Connection if... */
		if (END_OF_COMMUNICATION)
		{
			write(sockfd, END_MSG, strlen(END_MSG));
			printf("\nClient Exiting...\n");
			break ;
		}

		/* Send Message to Server */
		write(sockfd, buf, BUFF_SIZE);

		/* Read & Display Reponse */
		bzero(buf, BUFF_SIZE);
		read(sockfd, buf, BUFF_SIZE);
		printf("\nFrom Server:\n%s", buf);
	}
}

int		main(int ac, char *av[])
{
	struct sockaddr_in	server_address;

	int	client_socket_fd;
	int	npings;

	(void)ac;

	/* Create Socket */
	CHECK(client_socket_fd = socket(AF_INET, SOCK_STREAM, TCP));

	/* Setup Localhost Server Address */
	bzero(&server_address, sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(SERVER_PORT);
	server_address.sin_addr.s_addr = inet_addr(SERVER_IP);

	/* Establish Connection to the Localhost Server */
	CHECK(connect( client_socket_fd,
	               (const struct sockaddr *)&server_address,
	               (socklen_t)sizeof(server_address)           ));

	/* Communicate or Ping */
	if (av[1] && strcmp(av[1], "-C") == 0)
		chat(client_socket_fd, server_address);
	else
	{
		npings = (ac == 2) ? atoi(av[1]) : 3;
		npings = (npings == 0) ? 3 : npings;
		ping(client_socket_fd, server_address, npings);
	}

	/* Close Socket */
	close(client_socket_fd);

	return (0);
}
