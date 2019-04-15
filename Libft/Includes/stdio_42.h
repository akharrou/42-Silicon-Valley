/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdio_42.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 21:39:25 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/15 08:04:21 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STDIO_42_H
# define STDIO_42_H

# include <unistd.h>

void	ft_putbits(unsigned long long num, int n_bits);
void	ft_putbyte(int c);
void	ft_putbyte_fd(int c, int fd);
void	ft_putbytes(const char *byte_str);
void	ft_putbytes_fd(const char *byte_str, int fd);
void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr(char const *s);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl(char const *s);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putstrtab(char **tab, char sep);
void	ft_putstrtab_fd(char **tab, char sep, int fd);
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr_base(int nbr, char *base);
void	ft_putnbr_base_fd(int nbr, char *base, int fd);

int		ft_getline(const int fd, char **line);

#endif
