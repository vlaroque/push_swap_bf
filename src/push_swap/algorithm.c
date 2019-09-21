#include "push_swap.h"
#include <stdlib.h>

/*
 * WARNING all pivot variables are in reality for the index !
 */

/*
 * commence sur une case non pivot, jusqu'au prochain
 */

int		microopti(t_tab *tab)
{
	if (tab->a->start->prev->data == PIVOT)
	{
		if (tab->a->start->prev->index == tab->b->start->index + 1)
		{
			push_a(tab);
			is_pivot(tab->a->start);
			rotate_a(tab);
			return (1);
		}
		if (tab->a->start->prev->index == tab->b->start->prev->index + 1)
		{
			revrotate_b(tab);
			push_a(tab);
			is_pivot(tab->a->start);
			rotate_a(tab);
			return (1);
		}
	}
	return (0);
}

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


int		dist_to_next_pivot(t_list *list, int *min)
{
	int		dist;
	t_elem	*tmp;

	dist = 0;
	tmp = list->start;
	if ((min))
		*min = tmp->index;
	while(tmp->data != PIVOT)
	{
		dist++;
		if ((min) && *min > tmp->index)
			*min = tmp->index;
		tmp = tmp->next;
	}
	return (dist);
}

int		a_to_b_bf(t_tab *tab)
{
	int		dist;
	int		i;
	int		combi;
	int		min;
	t_elem	*tmp;

	a_rev_rotation(tab);
	dist = dist_to_next_pivot(tab->a, &min);
	if (dist > 5)
		return (0);
	i = 0;
	tmp = tab->a->start;
	combi = 0;
	while (i < dist)
	{
		tmp->data = PIVOT;
		combi = ((tmp->index - min + 1) + combi * 10);
		tmp = tmp->next;
		i++;
	}
	instant_bf(combi, tab);
	return (1);
}


/*
int		a_to_b_bf(t_tab *tab)
{
	int		dist;
	int		i;
	int		nbr[5];
	int		min;
	t_elem	*tmp;

//	print_tabs(tab);
	a_rev_rotation(tab);
	dist = dist_to_next_pivot(tab->a, &min);
	if (dist > 5)
		return (0);
	i = 0;
	tmp = tab->a->start;
	while (i < dist)
	{
		tmp->data = PIVOT;
		nbr[i] = tmp->index - min + 1;
		tmp = tmp->next;
		i++;
	}
//	printf("min = %d, dist = %d/n", min, dist);
//	print_tabs(tab);
	init_a_locked_bf(nbr, dist, tab);
	return (1);
}
*/

int		a_to_b(t_tab *tab)
{
	static int	first = 1;
	int			pivot;
	int			dist;

	pivot = choose_pivot(tab->a);
	dist = dist_pivot(tab->a, pivot, '-');
	if (!(first) && a_to_b_bf(tab))
		return (1);
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
	revrotate_b(tab);
	push_a(tab);
	is_pivot(tab->a->start);
	first = 0;
	return (1);
}


int		b_to_a(t_tab *tab)
{
	int		pivot;
	int		dist;
	
	pivot = choose_pivot(tab->b);
	dist = best_dist(dist_pivot(tab->b, pivot, '+'), 10 * rev_dist_pivot(tab->b, pivot, '+'));
	while (!(dist == 0))
	{
			if(tab->b->start->index >= pivot)
		{
			push_a(tab);
			if(tab->a->start->index == pivot)
				rotate_a(tab);
			if (dist > 0)
				dist--;
			else
				dist = dist; /* attention laisser ! */
		}
		else if (dist > 0)
		{
			rotate_b(tab);
			dist--;
		}
		else if (dist < 0)
		{
			revrotate_b(tab);
			dist++;
		}
	}
	revrotate_a(tab);
	is_pivot(tab->a->start);
	return (1);
}

int		a_rotation(t_tab *tab)
{
	t_elem *elem;
	int i;
	
	i = 0;
	while(tab->a->start->data == PIVOT)
	{
		rotate_a(tab);
		if (tab->a->start->data != PIVOT)
			pivot_maker(tab);
		if(tab->a->start->index == 0 && is_ordered(tab->a) && tab->b->size == 0)
			return (1);
		if (++i > 500)
			exit (0);
	}
	return (0);
}

int		algo(t_tab *tab)
{
	int i = 0;

	while (10)
	{
		a_to_b(tab);
		while (tab->b->size > 0)
		{
			if (tab->b->size < 22)
				b_to_a_insort(tab);
			else
				b_to_a(tab);
		}
		if (is_ordered(tab->a) && tab->b->size == 0)
			return (1);
		if (a_rotation(tab))
			return (1);
	}
}
