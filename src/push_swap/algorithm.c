#include "push_swap.h"
/*
 * WARNING all pivot var are in reality for the index !
 */

int		dist_to_next_less_pivot(t_list *list, int pivot)
{
	t_elem	*head;
	int		dist;
	int		res;

	dist = 0;
	while (head->data != PIVOT)
	{
		if(head->nbr <= pivot)
			res = dist;
		head = head->next;
		dist++;
	}
	return (res);
}

int		choose_pivot(t_list *list)
{
	t_elem	*head;
	int		min;
	int		max;

	head = list->start;
	min = head->nbr;
	max = head->nbr;
	while (head->data != PIVOT)
	{
		if (head->nbr < min)
			min = head->nbr;
		if (head->nbr > max)
			max = head->nbr;
		head = head->next;
		if (head == list->start)
			break ;
	}
	return ((min + max) / 2)
}

/*
 * commence sur une case non pivot, jusqu'au prochain
 */
int		a_to_b(t_tab *tab)
{
	int		pivot;
	int		dist;

	pivot = choose_pivot(tab->a->start);
	dist = dist_to_next_less_pivot(tab->a, pivot)
	while (dist >= 0)
	{
		if (tab->a->start->index <= pivot)
		{
			push(tab->a, tab->b);
		}
		rotate(tab->a);
		dist--;
	}
}

int		algo(t_tab *tab)
{
	
}
