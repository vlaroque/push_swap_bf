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

int		a_swaper(t_tab *tab)
{
//	write(1, "swap in\n", 8);
//	print_tabs(tab);
	if (head_operations(tab))
		return (1);
	while(1)
	{
		while(tab->a->start->next->next->data != PIVOT)
		{
			rotate_a(tab);
			if (head_operations(tab))
				return (1);
		}
		while(tab->a->start->prev->data != PIVOT)
		{
			revrotate_a(tab);
			if (head_operations(tab))
				return (1);
		}
	}
	return (0);
}
