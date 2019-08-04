#include "push_swap.h"

/*
 * WARNING all pivot variables are in reality for the index !
 */

/*
 * commence sur une case non pivot, jusqu'au prochain
 */

int		pivot_maker(t_tab *tab)
{
	t_elem *head;

	head = tab->a->start;
	while (head->data != PIVOT)
	{
		if(head->prev->data == PIVOT && head->prev->index == head->index - 1)
			head->data = PIVOT;
		head = head->next;
	}
	head = head->prev;
	while (head->data != PIVOT)
	{
		if(head->next->data == PIVOT && head->next->index == head->index + 1)
			head->data = PIVOT;
		head = head->prev;
	}
	return (1);
}

int		a_rev_rotation(t_tab *tab)
{
	t_elem *elem;

	while(tab->a->start->prev->data != PIVOT)
		revrotate_a(tab);
	return (0);
}

int		a_to_b(t_tab *tab)
{
	static int	first = 1;
	int			pivot;
	int			dist;

	pivot = choose_pivot(tab->a);
	dist = dist_pivot(tab->a, pivot, '-');
	if (dist <= 3 && !(first))
	{
//		print_tabs(tab);
		a_swaper(tab);
//		print_tabs(tab);
		return (1);
	}
	while (dist >= 0)
	{
		if (tab->a->start->index <= pivot)
		{
			push_b(tab);
			if(tab->b->start->index == pivot)
				rotate_b(tab);
		}
		else
			rotate_a(tab);
		dist--;
	}
	if (!(first))
		a_rev_rotation(tab);
	first = 0;
	return (1);
}

int		b_to_a(t_tab *tab)
{
	int		pivot;
	int		dist;
	
	pivot = choose_pivot(tab->b);
	dist = best_dist(dist_pivot(tab->b, pivot, '+'), 999999);
	while (dist >= 0)
	{
		if(tab->b->start->index >= pivot)
		{
			push_a(tab);
			if(tab->a->start->index == pivot)
				rotate_a(tab);
		}
		else if (dist > 0)
			rotate_b(tab);
		else if (dist < 0)
			revrotate_b(tab);
		//if (dist > 0)
			dist--;
		//else
		//	dist++;
	}
	revrotate_a(tab);
	return (1);
}

int		a_rotation(t_tab *tab)
{
	t_elem *elem;

	while(tab->a->start->data == PIVOT)
	{
		rotate_a(tab);
		if (tab->a->start->data != PIVOT)
			pivot_maker(tab);
		if(tab->a->start->index == 0 && is_ordered(tab->a))
			return (1);
	}
	return (0);
}

int		algo(t_tab *tab)
{
	while (1)
	{
		a_to_b(tab);
		//print_tabs(tab);
		while (tab->b->size > 0)
		{
			if (tab->b->size < 11)
				b_to_a_insort(tab);
			else
			{
				b_to_a(tab);
				is_pivot(tab->a->start);
			}
		//	print_tabs(tab);
		}
		if (is_ordered(tab->a))
			return (1);
		if (a_rotation(tab))
			return (1);
	}
//	print_tabs(tab);
}
