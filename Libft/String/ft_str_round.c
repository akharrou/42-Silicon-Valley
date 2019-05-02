/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_round.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 10:26:49 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/30 21:55:56 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/string_42.h"
#include "../Includes/macros_42.h"

																			char		*ft_str_round(char *numstr, char *base, int precision)
																			{
																				int		decimal;
																				int		intbase;
																				int		len;

																				decimal = ft_strchr(numstr, '.') - numstr;
																				intbase = ft_strlen(base);
																				len = ft_strlen(numstr);
																				if (decimal)
																				{
																					if (len >= (decimal + 1) + (precision + 1))
																						if (INT(numstr[decimal + precision + 1], base) >= intbase / 2)
																						{
																							if (INT(numstr[decimal + precision], base) == intbase - 1)
																								numstr[decimal + precision]
																						}
																						numstr[decimal + precision] += numstr[decimal + precision + 1];
																				}
																				return (numstr);
																			}
