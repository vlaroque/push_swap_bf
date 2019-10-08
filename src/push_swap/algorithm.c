/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 01:20:31 by vlaroque          #+#    #+#             */
/*   Updated: 2019/09/23 02:13:57 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

/*
** WARNING all pivot variables are in reality for the index !
*/

int		pivot_maker(t_tab *tab)
{
	t_elem *head;

	head = tab->a->start;
	while (head->data != PIVOT)
	{
		if (head->prev->data == PIVOT && head->prev->index == head->index - 1)
			head->data = PIVOT;
		head = head->next;
	}
	head = head->prev;
	while (head->data != PIVOT)
	{
		if (head->next->data == PIVOT && head->next->index == head->index + 1)
			head->data = PIVOT;
		head = head->prev;
	}
	return (1);
}

int		dist_to_next_pivot(t_list *list, int *min)
{
	int		dist;
	t_elem	*tmp;

	dist = 0;
	tmp = list->start;
	if ((min))
		*min = tmp->index;
	while (tmp->data != PIVOT)
	{
		dist++;
		if ((min) && *min > tmp->index)
			*min = tmp->index;
		tmp = tmp->next;
	}
	return (dist);
}

int		a_to_b(t_tab *tab)
{
	static int	first = 1;
	int			pivot;
	int			dist;

	pivot = choose_pivot(tab->a);
	dist = dist_pivot(tab->a, pivot, '-');
	if (!(first) && a_to_b_bf(tab))
		return (1);
	while (dist-- >= 0)
	{
		if (tab->a->start->index <= pivot)
		{
			push_b(tab);
			if (tab->b->start->index == pivot)
				rotate_b(tab);
		}
		else
			rotate_a(tab);
	}
	if (!(first))
		a_rev_rotation(tab);
	revrotate_b(tab);
	push_a(tab);
	is_pivot(tab->a->start);
	return ((first = 0));
}

int		b_to_a(t_tab *tab)
{
	int		pivot;
	int		dist;

	pivot = choose_pivot(tab->b);
	dist = dist_pivot(tab->b, pivot, '+') + 1;
	while (dist > 0)
	{
		if (tab->b->start->index >= pivot)
		{
			push_a(tab);
			if (tab->a->start->index == pivot)
				rotate_a(tab);
		}
		else
			rotate_b(tab);
		dist--;
	}
	revrotate_a(tab);
	is_pivot(tab->a->start);
	return (1);
}

int		algo(t_tab *tab)
{
	if (bruteforce_for_five(tab))
		return (1);
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
