/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_rotations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 01:48:37 by vlaroque          #+#    #+#             */
/*   Updated: 2019/09/23 10:13:03 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int		a_rev_rotation(t_tab *tab)
{
	t_elem *elem;

	while (tab->a->start->prev->data != PIVOT)
		revrotate_a(tab);
	return (0);
}

int		a_rotation(t_tab *tab)
{
	t_elem	*elem;
	int		i;

	i = 0;
	while (tab->a->start->data == PIVOT)
	{
		rotate_a(tab);
		if (tab->a->start->data != PIVOT)
			pivot_maker(tab);
		if (tab->a->start->index == 0 && is_ordered(tab->a)
				&& tab->b->size == 0)
			return (1);
		if (++i > 500)
			exit(0);
	}
	return (0);
}

int		bruteforce_for_five(t_tab *tab)
{
	int		i;
	t_elem	*head;
	int		a[5];

	if (tab->a->size > 5)
		return (0);
	i = 0;
	head = tab->a->start;
	while (i < tab->a->size)
	{
		a[i] = head->index + 1;
		head = head->next;
		i++;
	}
	init_a_unlocked_bf(a, tab->a->size, tab);
	return (1);
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
