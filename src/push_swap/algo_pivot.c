#include "push_swap.h"

void	is_pivot(t_elem *elem)
{
	elem->data = PIVOT;
}

int		choose_pivot(t_list *list)
{
	t_elem	*head;
	int		min;
	int		max;

	head = list->start;
	min = head->index;
	max = head->index;
	while (head->data != PIVOT)
	{
		if (head->nbr < min)
			min = head->index;
		if (head->nbr > max)
			max = head->index;
		head = head->next;
		if (head == list->start)
			break ;
	}
	printf("pivot (%D %D) = %d\n", min, max, (min + max) / 2);
	return ((min + max) / 2);
}


