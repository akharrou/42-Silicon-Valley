/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 08:16:53 by akharrou          #+#    #+#             */
/*   Updated: 2019/03/04 10:31:19 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_H
# define HASHTABLE_H

# define HASHCODE(key, buckets) (ft_hash(key) % buckets)

# define INIT_HASHTABLE_SIZE 256
# define MIN_LOAD_FACTOR 0.0
# define MAX_LOAD_FACTOR 0.7

typedef struct		s_entry
{
	char			*key;
	void			*item;
	struct s_entry	*next;
}					t_entry;

typedef struct		s_hashtable
{
	unsigned int	entries;
	unsigned int	num_buckets;
	t_entry			**bucket_list;
}					t_hashtable;

t_hashtable			*hashtab_alloc_table(unsigned int num_entries);
int					hashtab_grow_table(t_hashtable **table);
int					hashtab_shrink_table(t_hashtable **table);
t_entry				*hashtab_fetch_entry(t_hashtable *table, char *key);
int					hashtab_insert_entry(t_hashtable **table,
										char *key,
										void *item);
int					hashtab_delete_entry(t_hashtable **table, char *key);
int					hashtab_rehash_entry(t_hashtable **table_to,
										t_entry **entry);
int					hashtab_rehash_table(t_hashtable **table_from,
										t_hashtable **table_to);
int					hashtab_destroy_table(t_hashtable **table);
int					hashtab_set_appropriate_load_factor(t_hashtable **table);

#endif
