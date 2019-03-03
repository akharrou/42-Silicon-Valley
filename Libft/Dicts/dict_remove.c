/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 09:53:38 by akharrou          #+#    #+#             */
/*   Updated: 2019/02/27 21:28:10 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		dict_remove(t_hashtable **table, char *key)
{
	return (hashtab_delete_entry(table, key));
}
