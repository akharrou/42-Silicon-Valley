/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_getvalue_fast.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:05:53 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/27 16:43:33 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*dict_getvalue_fast(t_hashtable *table, char *key,
							unsigned int table_index)
{
	return ((dict_getitem_fast(table, key, table_index))->value);
}
