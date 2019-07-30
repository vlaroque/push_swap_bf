#include "push_swap.h"

static int	dist_swap(t_tab *tab)
{
	t_elem *head;
	int		dist;

	dist = 0;
	head = tab->a->start;
	while (head->data != PIVOT)
	{
		head = head->next;
		dist++;
	}
	return(dist);
}


int		a_swaper(t_tab *tab)
{
	t_elem	*save;
	int		dist;
	int		i;

	dist = dist_swap(tab);
	while (i < dist - 1)
	{
		if (tab->a->start->index > tab->a->start->next->index)
			swap_a(tab);
		rotate_a(tab);
		i++;
	}
}


