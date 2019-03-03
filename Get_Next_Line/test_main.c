/*
 *
 * TEST MAIN
 *
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "get_next_line.h"

int		main(int ac, char *av[])
{
	char	*line;

/* SINGLE FILE DESCRIPTOR — — — — — — — — — — — — — — — — — — — — — — —*/

	// int		fd1;

	// fd1 = open(av[1], O_RDONLY);

	// printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd1, &line), line);

	// close(fd1);

/* STANDARD INPUT FILEDESCRIPTOR — — — — — — — — — — — — — — — — — — — — — — */

	// while (get_next_line(0, &line) > 0)
	// 	ft_putendl(line);


/* SINGLE DESCRIPTOR ENTIRE FILE — — — — — — — — — — — — — — — — — — — — — — */

	int		fd1;

	fd1 = open(av[1], O_RDONLY);

	while (get_next_line(fd1, &line) > 0)
		ft_putendl(line);

	close(fd1);


/* MULTIPLE FILE DESCRIPTORS — — — — — — — — — — — — — — — — — — — — — — —*/

	// int		fd1;
	// int		fd2;
	// int		fd3;

	// fd1 = open(av[1], O_RDONLY);
	// fd2 = open(av[2], O_RDONLY);
	// fd3 = open(av[3], O_RDONLY);

	// printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd2, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd3, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd2, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd3, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd2, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd3, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd2, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd3, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd2, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd3, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd2, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd3, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd2, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd3, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd2, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd3, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd2, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd3, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd2, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd3, &line), line);

	// close(fd1);
	// close(fd2);
	// close(fd3);

/* 5+ FILEDESCRIPTORS */

	// int		fd1;
	// int		fd2;
	// int		fd3;
	// int		fd4;
	// int		fd5;
	// int		fd6;

	// fd1 = open(av[1], O_RDONLY);
	// fd2 = open(av[2], O_RDONLY);
	// fd3 = open(av[3], O_RDONLY);
	// fd4 = open(av[4], O_RDONLY);
	// fd5 = open(av[5], O_RDONLY);
	// fd6 = open(av[6], O_RDONLY);

	// printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd2, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd3, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd4, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd5, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd6, &line), line);

	// printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd2, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd3, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd4, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd5, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd6, &line), line);

	// printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd2, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd3, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd4, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd5, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd6, &line), line);

	// printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd2, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd3, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd4, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd5, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd6, &line), line);

	// printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd2, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd3, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd4, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd5, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd6, &line), line);

	// printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd2, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd3, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd4, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd5, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd6, &line), line);

	// printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd2, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd3, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd4, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd5, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd6, &line), line);

	// printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd2, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd3, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd4, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd5, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd6, &line), line);

	// printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd2, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd3, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd4, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd5, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd6, &line), line);

	// printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd2, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd3, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd4, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd5, &line), line);
	// printf("[%i] $> %s\n", get_next_line(fd6, &line), line);

	// close(fd1);
	// close(fd2);
	// close(fd3);
	// close(fd4);
	// close(fd5);
	// close(fd6);

	(void)ac;
	(void)av;

	return (0);
}
