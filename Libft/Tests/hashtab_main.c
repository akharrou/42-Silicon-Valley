/*
*
*  TEST MAIN.
*
*/

// HEADERS ====================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../libft.h"

#include "../ft_hash.c"

#include "../ft_strcmp.c"
#include "../ft_strlen.c"
#include "../ft_strdup.c"
#include "../ft_isprime.c"
#include "../ft_find_next_prime.c"

#include "../hashtab_set_appropriate_load_factor.c"
#include "../hashtab_shrink_table.c"
#include "../hashtab_grow_table.c"
#include "../hashtab_rehash_entry.c"
#include "../hashtab_rehash_table.c"
#include "../hashtab_delete_entry.c"
#include "../hashtab_destroy_table.c"
#include "../hashtab_alloc_table.c"
#include "../hashtab_fetch_entry.c"
#include "../hashtab_insert_entry.c"

// MAIN =======================================================================

int main(int ac, char *av[])
{
	if (ac < 7)
	{
		printf("Usage: ./a key1 key2 key3 key4 key5 key6\n");
		return (0);
	}

	t_hashtable *hashtab;

	printf("——————————————————————————\nCreation:\n\n");
	printf("Hashtable Address: %p\n\n", hashtab = hashtab_alloc_table(100));

	printf("——————————————————————————\nInsertion:\n\n");
	printf("#1:	[%d]\n", hashtab_insert_entry(&hashtab, av[1], ft_strdup("yo")));
	printf("#2:	[%d]\n", hashtab_insert_entry(&hashtab, av[2], ft_strdup("check")));
	printf("#3:	[%d]\n", hashtab_insert_entry(&hashtab, av[3], ft_strdup("this")));
	printf("#4:	[%d]\n", hashtab_insert_entry(&hashtab, av[4], ft_strdup("hash")));
	printf("#5:	[%d]\n", hashtab_insert_entry(&hashtab, av[5], ft_strdup("table")));
	printf("#6:	[%d]\n\n", hashtab_insert_entry(&hashtab, av[6], ft_strdup("out!")));

	printf("——————————————————————————\nRetrieval:\n\n");
	printf("#1: %s\n", (char*)(hashtab_fetch_entry(hashtab, av[1])->value));
	printf("#2: %s\n", (char*)(hashtab_fetch_entry(hashtab, av[2])->value));
	printf("#3: %s\n", (char*)(hashtab_fetch_entry(hashtab, av[3])->value));
	printf("#4: %s\n", (char*)(hashtab_fetch_entry(hashtab, av[4])->value));
	printf("#5: %s\n", (char*)(hashtab_fetch_entry(hashtab, av[5])->value));
	printf("#6: %s\n\n", (char*)(hashtab_fetch_entry(hashtab, av[6])->value));

	printf("Buckets: %d\n\n", hashtab->num_buckets);

	printf("——————————————————————————\nShrinkage:\n\n");
	printf("#1 Shrinkage Status: [%d]\n", hashtab_shrink_table(&hashtab));
	printf("Buckets: %d\n\n", hashtab->num_buckets);

	printf("#2 Shrinkage Status: [%d]\n", hashtab_shrink_table(&hashtab));
	printf("Buckets: %d\n\n", hashtab->num_buckets);

	printf("#3 Shrinkage Status: [%d]\n", hashtab_shrink_table(&hashtab));
	printf("Buckets: %d\n\n", hashtab->num_buckets);

	printf("——————————————————————————\nRetrieval:\n\n");
	printf("#1: %s\n", (char*)(hashtab_fetch_entry(hashtab, av[1])->value));
	printf("#2: %s\n", (char*)(hashtab_fetch_entry(hashtab, av[2])->value));
	printf("#3: %s\n", (char*)(hashtab_fetch_entry(hashtab, av[3])->value));
	printf("#4: %s\n", (char*)(hashtab_fetch_entry(hashtab, av[4])->value));
	printf("#5: %s\n", (char*)(hashtab_fetch_entry(hashtab, av[5])->value));
	printf("#6: %s\n\n", (char*)(hashtab_fetch_entry(hashtab, av[6])->value));

	printf("Number of current entries: %d\n\n", hashtab->entries);

	printf("——————————————————————————\nReallocation:\n\n");
	printf("#1 Grow Status: [%d]\n", hashtab_grow_table(&hashtab));
	printf("Buckets: %d\n\n", hashtab->num_buckets);

	printf("——————————————————————————\nRetrieval:\n\n");
	printf("#1: %s\n", (char*)(hashtab_fetch_entry(hashtab, av[1])->value));
	printf("#2: %s\n", (char*)(hashtab_fetch_entry(hashtab, av[2])->value));
	printf("#3: %s\n", (char*)(hashtab_fetch_entry(hashtab, av[3])->value));
	printf("#4: %s\n", (char*)(hashtab_fetch_entry(hashtab, av[4])->value));
	printf("#5: %s\n", (char*)(hashtab_fetch_entry(hashtab, av[5])->value));
	printf("#6: %s\n\n", (char*)(hashtab_fetch_entry(hashtab, av[6])->value));

	printf("Number of current entries: %d\n\n", hashtab->entries);

	printf("——————————————————————————\nDeletion:\n\n");
	printf("#1:	[%d]\n", hashtab_delete_entry(&hashtab, av[1]));
	printf("#2:	[%d]\n", hashtab_delete_entry(&hashtab, av[2]));
	printf("#3:	[%d]\n", hashtab_delete_entry(&hashtab, av[3]));
	printf("#4:	[%d]\n", hashtab_delete_entry(&hashtab, av[4]));
	printf("#5:	[%d]\n", hashtab_delete_entry(&hashtab, av[5]));
	printf("#6:	[%d]\n\n", hashtab_delete_entry(&hashtab, av[6]));

	printf("Number of current entries: %d\n\n", hashtab->entries);

	printf("——————————————————————————\nDestruction:\n\n");
	printf("Destroy Status: [%d]\n", hashtab_destroy_table(&hashtab));
	printf("Hashtable Address: %p\n\n", hashtab);

	printf("——————————————————————————\n\n");

	return (0);
}
