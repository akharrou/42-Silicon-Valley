/*
 *
 *  TEST MAIN
 *
 */

#include "../ft_lstnew.c"
// #include "../ft_lstdelone.c"
// #include "../ft_lstdel.c"
#include "../ft_lstadd.c"
#include "../ft_lstiter.c"
// #include "../ft_lstmap.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	ft_print_lst_elem_content(t_list *elem)
{
	printf("———————————————————————————————————\nElement:\n\nContent:	%s\n———————————————————————————————————\n", (char *)elem->content);
}

void	ft_print_lst_elem(unsigned int i, t_list *link)
{
	printf("———————————————————————————————————\nElement #%i:\n\nNext:		%p\nContent:	%s\nContent Size:	%i\n———————————————————————————————————\n", i, link->next, (char *)link->content, (int)link->content_size);
}

int		main(int ac, char *av[])
{
	if (ac != 2)
	{
		printf("Usage: ./program data\n");
		return (1);
	}

	t_list *head = ft_lstnew((void *)av[1], strlen(av[1]) + 1);

	ft_print_lst_elem(0, head);
	ft_lstiter(head, &ft_print_lst_elem_content);

	return (0);
}
