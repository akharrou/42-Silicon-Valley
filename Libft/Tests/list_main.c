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

/* COUNTING NUMBER OF ELEMENTS */
	// list_extend(&head, (void *)(++av));
	// list_iteri(head, &print_item);
	// printf("————————————————————\nElement Count: %i\n", list_count(head));

/* FREEING AN ENTIRE LIST */
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

	(void)head;
	(void)tail;

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
//   []  list_insert()
//   []  list_insert_at()
//   []  list_item_at()
//   []  list_last_item()
//   []  list_elem_at()
//   []  list_last_elem()
//   []  list_getitem()
//   []  list_getelem()
//   []  list_pop()
//   []  list_pop_tail()
//   []  list_popleft()
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
//   []  list_sort()
//   []  list_reverse()
//   []  list_map()
//   []  list_merge()
