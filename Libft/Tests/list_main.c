/*
 *
 * TEST MAIN
 *
 */

#include "../libft.h"

#include "../list_newelem.c"
#include "../list_prepend.c"
#include "../list_append.c"
#include "../list_append_tail.c"
#include "../list_extend.c"
#include "../list_extend_tail.c"
#include "../list_extendleft.c"
#include "../list_insert.c"
#include "../list_insert_at.c"
#include "../list_item_at.c"
#include "../list_last_item.c"
#include "../list_elem_at.c"
#include "../list_last_elem.c"
#include "../list_getitem.c"
#include "../list_getelem.c"
#include "../list_pop.c"
#include "../list_pop_tail.c"
#include "../list_popleft.c"
#include "../list_pop_item_at.c"
#include "../list_pop_item.c"
#include "../list_remove_item.c"
#include "../list_remove_item_at.c"
#include "../list_remove_elem.c"
#include "../list_remove_elem_at.c"
#include "../list_clear.c"
#include "../list_iter.c"
#include "../list_iteri.c"
#include "../list_count.c"
#include "../list_sort.c"
#include "../list_reverse.c"
#include "../list_map.c"
#include "../list_merge.c"

#include "../ft_strdup.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	print_item(unsigned int i, void *item)
{
	printf("%i: %s\n", i, (char *)item);
}

void	free_item(void *item)
{
	free(item);
}

int		ft_strcmp_(void *str1, void *str2)
{
	unsigned int	i;
	const char		*s1 = str1;
	const char		*s2 = str2;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}


int		main(int ac, char *av[])
{
	if (ac == 1)
	{
		printf("Usage: ./a item1 item2 item3 itemN ...\n");
		return (1);
	}

	t_list *head;
	t_list *tail;

/* APPENDING VALUES */
	// int i = 1;
	// while (ac > i)
	// 	list_append(&head, (void *)av[i++]);
	// list_iteri(head, &print_item);

/* PREPENDING VALUES */
	// int i = 1;
	// while (ac > i)
	// 	list_prepend(&head, (void *)av[i++]);
	// list_iteri(head, &print_item);

/* EXTENDING LISTS */
	// list_extend(&head, (void *)(++av));
	// list_iteri(head, &print_item);

/* EXTENDING LISTS FROM TAIL */
	// list_append(&head, *av++);
	// tail = head;
	// list_extend_tail(&tail, (void *)av);
	// list_iteri(head, &print_item);
	// printf("First Element: %s\n", head->item);
	// printf("Last Element: %s\n", tail->item);

/* EXTENDING LISTS FROM THE LEFT */
	// list_extendleft(&head, (void *)(++av));
	// list_iteri(head, &print_item);

/* INSERTING VALUES */
	// list_extend(&head, (void *)(++av));
	// printf("——————————————————————\nPre-Insertion:\n\n");
	// list_iteri(head, &print_item);

	// list_insert(&head, ft_strdup("#Z"), &ft_strcmp_);

	// printf("——————————————————————\nPost-Insertion (by comparasion) #1:\n\n");
	// list_iteri(head, &print_item);

	// list_insert_at(&head, ft_strdup("#A"), 0);
	// list_insert_at(&head, ft_strdup("#B"), 2);
	// list_insert_at(&head, ft_strdup("#C"), 4);
	// list_insert_at(&head, ft_strdup("#D"), 20);

	// printf("——————————————————————\nPost-Insertion (by index) #2:\n\n");
	// list_iteri(head, &print_item);
	// printf("——————————————————————\n");

/* GET ELEMENTS & VALUES */
	// list_extend(&head, (void *)(++av));
	// printf("————————————————————————————————————————————————————————\nList:\n\n");
	// list_iteri(head, &print_item);
	// printf("————————————————————————————————————————————————————————\nlist_getelem(head, \"James\") ——> %p\n", list_getelem(head, "James", &ft_strcmp_));
	// printf("————————————————————————————————————————————————————————\nlist_getitem(head, \"James\") ——> %s\n", list_getitem(head, "James", &ft_strcmp_));
	// printf("————————————————————————————————————————————————————————\n");

/* POP LAST ELEMENT */
	// list_extend(&head, (void *)(++av));
	// printf("————————————————————————————————————————————————————————\nList:\n\n");
	// list_iteri(head, &print_item);
	// while (head)
	// 	printf("————————————————————————————————————————————————————————\nItem Popped ——> %s\n", (char *)list_pop(&head));
// 	printf("————————————————————————————————————————————————————————\nItem Popped ——> %s\n", (char *)list_pop(&head));
// 	printf("————————————————————————————————————————————————————————\nItem Popped ——> %s\n", (char *)list_pop(&head));
	// printf("————————————————————————————————————————————————————————\n");

/* POP LAST ELEMENT FROM TAIL */
	// list_extend(&head, (void *)(++av));
	// printf("————————————————————————————————————————————————————————\nList:\n\n");
	// list_iteri(head, &print_item);
	// tail = head;
	// printf("————————————————————————————————————————————————————————\nItem Popped ——> %s\n", (char *)list_pop_tail(&tail));
	// printf("————————————————————————————————————————————————————————\nItem Popped ——> %s\n", (char *)list_pop_tail(&tail));
	// printf("————————————————————————————————————————————————————————\nItem Popped ——> %s\n", (char *)list_pop_tail(&tail));
	// printf("————————————————————————————————————————————————————————\nItem Popped ——> %s\n", (char *)list_pop_tail(&tail));
	// printf("————————————————————————————————————————————————————————\nItem Popped ——> %s\n", (char *)list_pop_tail(&tail));
	// printf("————————————————————————————————————————————————————————\nItem Popped ——> %s\n", (char *)list_pop_tail(&tail));
	// printf("————————————————————————————————————————————————————————\n");

/* POP FIRST ELEMENT */
	// list_extend(&head, (void *)(++av));
	// printf("————————————————————————————————————————————————————————\nList:\n\n");
	// list_iteri(head, &print_item);
	// while (head)
	// 	printf("————————————————————————————————————————————————————————\nItem Popped ——> %s\n", (char *)list_popleft(&head));
	// 	printf("————————————————————————————————————————————————————————\nItem Popped ——> %s\n", (char *)list_popleft(&head));
	// 	printf("————————————————————————————————————————————————————————\nItem Popped ——> %s\n", (char *)list_popleft(&head));
	// printf("————————————————————————————————————————————————————————\n");





/* POP ELEMENT & ELEMENT AT */
	// TODO

//   []  list_pop_item_at()
//   []  list_pop_item()




/* REMOVE ELEMENT & ELEMENT AT */
	// TODO

//   []  list_remove_item()
//   []  list_remove_item_at()
//   []  list_remove_elem()
//   []  list_remove_elem_at()



/* COUNTING NUMBER OF ELEMENTS */
	// list_extend(&head, (void *)(++av));
	// list_iteri(head, &print_item);
	// printf("————————————————————\nElement Count: %i\n", list_count(head));

/* LAST ELEMENT/ITEM OF A LIST */
	// list_extend(&head, (void *)(++av));
	// list_iteri(head, &print_item);
	// printf("——————————————————————\nElement at Index #%i ——> %p\n", 3, (char *)list_elem_at(head, 3));
	// printf("——————————————————————\nItem at Index #%i ——> %s\n", 3, (char *)list_item_at(head, 3));
	// printf("——————————————————————\nLast Element ——> %p\n", list_last_elem(head));
	// printf("——————————————————————\nLast Item ——> %s\n", (char *)list_last_item(head));
	// printf("——————————————————————\n");

/* SORTING A LIST */
	// list_extend(&head, (void *)(++av));
	// printf("——————————————————————\nPre-Sorting:\n\n");
	// list_iteri(head, &print_item);
	// printf("——————————————————————\nPost-Sorting:\n\n");
	// list_sort(&head, &ft_strcmp_);
	// list_iteri(head, &print_item);
	// printf("——————————————————————\n");

/* REVERSING A LIST */
	// list_extend(&head, (void *)(++av));
	// printf("——————————————————————\nPre-Reversing:\n\n");
	// list_iteri(head, &print_item);
	// printf("——————————————————————\nPost-Reversing:\n\n");
	// list_reverse(&head);
	// list_iteri(head, &print_item);
	// printf("——————————————————————\n");



/* LIST MAPPING */
	// TODO

//   []  list_map()


/*  MERGING LISTS */
	// t_list *head2;

	// list_extend(&head, (void *)(++av));
	// printf("——————————————————————\nList #1:\n\n");
	// list_iteri(head, &print_item);

	// list_extendleft(&head2, (void *)(av));
	// printf("——————————————————————\nList #2:\n\n");
	// list_iteri(head2, &print_item);

	// list_merge(&head, head2);
	// printf("——————————————————————\nMerged List:\n\n");
	// list_iteri(head, &print_item);
	// printf("——————————————————————\n");

/* FREEING AN ENTIRE LIST (YOU MUST HAVE ALLOCATED THE MEMORY) */
	// char **str;
	// int i = 0;

	// str = (char **)malloc(sizeof(char *) * ac);
	// while (ac > ++i)
	// 	str[i - 1] = ft_strdup(av[i]);
	// str[i - 1] = NULL;

	// list_extend(&head, (void *)str);
	// printf("————————————————————————————\n1st Iteration:\n");
	// list_iteri(head, &print_item);
	// printf("————————————————————————————\nlist_clear() ——> %i\n", list_clear(&head, &free_item));
	// printf("————————————————————————————\n2nd Iteration:\n");
	// list_iteri(head, &print_item);
	// printf("————————————————————————————\n");


	(void)ac; (void)av; (void)head; (void)tail;
	return (0);
}


// Tests Completed:

//   [√]  list_newelem()
//   [√]  list_prepend()
//   [√]  list_append()
//   [√]  list_append_tail()
//   [√]  list_extend()
//   [√]  list_extend_tail()
//   [√]  list_extendleft()
//   [√]  list_insert()
//   [√]  list_insert_at()
//   [√]  list_item_at()
//   [√]  list_last_item()
//   [√]  list_elem_at()
//   [√]  list_last_elem()
//   [√]  list_getitem()
//   [√]  list_getelem()
//   [√]  list_pop()
//   [√]  list_pop_tail()
//   [√]  list_popleft()
//   []  list_pop_item_at()
//   []  list_pop_item()
//   []  list_remove_item()
//   []  list_remove_item_at()
//   []  list_remove_elem()
//   []  list_remove_elem_at()
//   [√]  list_clear()
//   [√]  list_iter()
//   [√]  list_iteri()
//   [√]  list_count()
//   [√]  list_sort()
//   [√]  list_reverse()
//   []  list_map()
//   [√]  list_merge()
