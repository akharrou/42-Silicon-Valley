/*
 *
 *  TEST MAIN
 *
 */

#include "../ft_strlen.c"
#include "../ft_putstr.c"

#include "../ft_lstnew.c"
#include "../ft_lstdelone.c"
#include "../ft_lstdel.c"
#include "../ft_lstadd.c"
#include "../ft_lstmap.c"
#include "../ft_lstiter.c"
#include "../ft_lstiteri.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	ft_print_list_elem_content(t_list *elem)
{
	ft_putstr((char *)elem->content);
	ft_putstr("\n");
}

void	ft_print_list_elem(unsigned int i, t_list *link)
{
	printf("———————————————————————————————————\nElement #%i:\n\nNext:		%p\nContent:	%s\nContent Size:	%i\n", i, link->next, (char *)link->content, (int)link->content_size);
}

void	ft_del_list_strelem(void *content, size_t content_size)
{
	(void)content_size;
	(void)content;
}

int		main(int ac, char *av[])
{
	t_list			*head;
	unsigned int	i;

	if (ac < 2)
	{
		printf("Usage: ./program data1 data2 data3 ... \n");
		return (1);
	}

	i = 0;
	while (av[++i])
		ft_lstadd(&head, ft_lstnew(av[i], ft_strlen(av[i] + 1)));

	ft_lstiteri(head, &ft_print_list_elem);
	printf("———————————————————————————————————\n");

	ft_lstdel(&head, ft_del_list_strelem);

	ft_lstiteri(head, &ft_print_list_elem);
	printf("%p\n", head);

	return (0);
}
