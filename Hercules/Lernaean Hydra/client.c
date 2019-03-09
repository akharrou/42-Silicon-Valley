/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:36:10 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/08 23:45:44 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket_programming.h"

void	communicate(int sockfd, struct sockaddr_in server_addr)
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
		if (buf[0] == '\n' || END_OF_COMMUNICATION)
		{
			write(sockfd, END_MSG, strlen(END_MSG));
            printf("Client Exiting...\n");
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

int		main(void)
{
	struct sockaddr_in	server_address;

	int	client_socket_fd;

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

	/* Communicate */
	communicate(client_socket_fd, server_address);

	/* Close Socket */
	close(client_socket_fd);

	return (0);
}
