#include <stdlib.h>
#include "push_swap.h"

t_list		*init_empty_list(void)
{
	t_list	*list;

	if (!(list = malloc(sizeof(t_list))))
		return (NULL);
	list->start = NULL;
	list->size = 0;
	return(list);
}

void		print_tabs(t_tab *tab)
{
	int		i;
	t_elem	*elem;

	i = -1;
	elem = tab->a->start;
	printf("A = ");
	while(++i < tab->a->size)
	{
		if (elem->prev->next->nbr != elem->nbr
				|| elem->next->prev->nbr != elem->nbr)
			printf("!pb!\n");
		if (elem->data == PIVOT)
			printf("!");
		printf(" (%d) %-5d ",elem->index, elem->nbr);
		elem = elem->next;
	}
	printf("\n");
	i = -1;
	elem = tab->b->start;
	printf("B = ");
	while(++i < tab->b->size)
	{
		if (elem->data == PIVOT)
			printf("!");
		printf(" (%d) %-5d ",elem->index, elem->nbr);
		elem = elem->next;
	}
	printf("\n");
}
