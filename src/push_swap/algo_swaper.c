#include "push_swap.h"

static int	head_operations(t_tab *tab)
{
	if (tab->a->start->index > tab->a->start->next->index)
		swap_a(tab);
	if (tab->a->start->prev->data == PIVOT)
	{
		if (tab->a->start->prev->index + 1 == tab->a->start->index)
		{
			tab->a->start->data = PIVOT;
			if (tab->a->start->index + 1 == tab->a->start->next->index)
				tab->a->start->next->data = PIVOT;
		}
	}
	if (tab->a->start->next->next->data == PIVOT)
	{
		if (tab->a->start->next->next->index - 1 == tab->a->start->next->index)
		{
			tab->a->start->next->data = PIVOT;
			if (tab->a->start->next->index - 1 == tab->a->start->index)
				tab->a->start->data = PIVOT;
		}
	}
	if (tab->a->start->next->next->data == PIVOT && tab->a->start->next->data == PIVOT && tab->a->start->data == PIVOT && tab->a->start->prev->data == PIVOT)
		return (1);
	return (0);
}

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


