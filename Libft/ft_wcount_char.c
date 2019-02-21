/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcount_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:14:37 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/19 15:44:03 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_wcount_char(const char *s, int c)
{
	int		i;
	int		word_count;

	i = 0;
	word_count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == (unsigned char)c)
			i++;
		while (s[i] && !(s[i] == (unsigned char)c))
			i++;
		word_count++;
		while (s[i] && s[i] == (unsigned char)c)
			i++;
	}
	return (word_count);
}
