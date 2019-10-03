/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 22:46:22 by vlaroque          #+#    #+#             */
/*   Updated: 2019/09/22 23:02:28 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rotate(t_list *list)
{
	if (list->size > 0)
		list->start = list->start->next;
	return (1);
}

int		rev_rotate(t_list *list)
{
	if (list->size > 0)
		list->start = list->start->prev;
	return (1);
}

int		swap(t_list *list)
{
	t_elem	*prev;
	t_elem	*first;
	t_elem	*sec;
	t_elem	*last;

	if (list->size < 2)
		return (0);
	first = list->start;
	sec = list->start->next;
	if (list->size == 2)
		sec = list->start->next;
	else
	{
		prev = list->start->prev;
		last = list->start->next->next;
		prev->next = sec;
		first->prev = sec;
		first->next = last;
		sec->prev = prev;
		sec->next = first;
		last->prev = first;
	}
	list->start = sec;
	return (1);
}

int		push(t_list *from, t_list *to)
{
	t_elem	*save;

	if (from->size < 1)
		return (0);
	save = from->start;
	from->start->next->prev = from->start->prev;
	from->start->prev->next = from->start->next;
	from->start = from->start->next;
	if (to->size < 1)
	{
		save->next = save;
		save->prev = save;
	}
	else
	{
		save->next = to->start;
		save->prev = to->start->prev;
		to->start->prev->next = save;
		to->start->prev = save;
	}
	to->start = save;
	(from->size)--;
	(to->size)++;
	return (1);
}
