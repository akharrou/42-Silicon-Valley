/*
 *
 * TEST MAIN.
 *
 */

#include "../libft.h"

#include "../ft_strlen.c"
#include "../ft_itoa_base.c"
#include "../ft_strdup.c"

#include "../ft_hash.c"
#include "../ft_alpha_to_index.c"
#include "../ft_char_to_index.c"

#include "../trie_newnode.c"
#include "../trie_remove.c"
#include "../trie_clear.c"
#include "../trie_getitem.c"
#include "../trie_insert.c"
#include "../trie_count.c"

#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char *av[])
{
	(void)ac;
	(void)av;

	t_trie *root;
	char *s1 = ft_strdup(av[1]);
	char *s2 = ft_strdup(av[2]);
	char *s3 = ft_strdup(av[3]);

	// Create root of the trie
	root = trie_newnode();

	// Insert some item
	trie_insert(&root, s1, ft_strdup("Hey!"), &ft_alpha_to_index);
	trie_insert(&root, s2, ft_strdup("This"), &ft_alpha_to_index);
	trie_insert(&root, s3, ft_strdup("works!"), &ft_alpha_to_index);

	printf("Trie Size After all Inserts: %d\n\n", trie_count(root));

	printf("  Hash: %s\nString: '%s'\n\n", s1,(char*)trie_getitem(root, s1, &ft_alpha_to_index));

	trie_remove(&root, s1, &ft_alpha_to_index);

	printf("Trie Size After 1 Deletion: %d\n\n", trie_count(root));

	printf("  Hash: %s\nString: '%s'\n\n", s2,(char*)trie_getitem(root, s2, &ft_alpha_to_index));

	trie_remove(&root, s2, &ft_alpha_to_index);

	printf("Trie Size After 2 Deletions: %d\n\n", trie_count(root));

	printf("  Hash: %s\nString: '%s'\n\n", s3,(char*)trie_getitem(root, s3, &ft_alpha_to_index));

	trie_clear(&root);

	printf("Trie Size After Destruction of the Trie: %d\n\n", trie_count(root));

	return (0);
}
