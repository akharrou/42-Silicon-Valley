/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:54:26 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/04 10:12:58 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ctype_42.h"

int		ft_isalpha(int c)
{
	return (ISLOWER(c) || ISUPPER(c));
}
