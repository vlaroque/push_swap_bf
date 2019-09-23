/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_insort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 23:08:20 by vlaroque          #+#    #+#             */
/*   Updated: 2019/09/22 23:13:14 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min_max(t_tab *tab, int *min, int *max)
{
	t_elem	*head;
	int		i;

	i = tab->b->size;
	head = tab->b->start;
	*min = head->index;
	*max = head->index;
	while (i > 0)
	{
		if (head->index < *min)
			*min = head->index;
		if (head->index > *max)
			*max = head->index;
		head = head->next;
		i--;
	}
	return (0);
}

/*
** ^ dist negative
** v dist positive
*/

static int	dist_calc(t_tab *tab, int min, int max)
{
	t_elem	*head_prev;
	t_elem	*head_next;
	int		dist;

	dist = 0;
	head_prev = tab->b->start;
	head_next = tab->b->start;
	while (dist < 10)
	{
		if (head_prev->index == max)
			return (-dist);
		if (head_next->index == max)
			return (dist);
		if (head_prev->index == min)
			return (-dist);
		if (head_next->index == min)
			return (dist);
		head_prev = head_prev->prev;
		head_next = head_next->next;
		dist++;
	}
	return (-999999);
}

int			b_to_a_insort(t_tab *tab)
{
	int		min;
	int		max;
	int		dist;

	while (tab->b->size > 0)
	{
		min_max(tab, &min, &max);
		dist = dist_calc(tab, min, max);
		while (dist != 0)
		{
			if (dist > 0)
				rotate_b(tab);
			else
				revrotate_b(tab);
			if (dist > 0)
				dist--;
			else
				dist++;
		}
		push_a(tab);
		is_pivot(tab->a->start);
		if (tab->a->start->index == min)
			rotate_a(tab);
	}
	return (1);
}
