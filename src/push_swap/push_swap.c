/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 14:33:22 by vlaroque          #+#    #+#             */
/*   Updated: 2019/10/07 18:33:36 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

static int		are_useless_ops(int i)
{
	if (i == (RA | RRA) || i == (RB | RRB) || i == (PA | PB) || i == (RR | RRR))
		return (-1);
	if (i == SA || i == SB || i == SS)
		return (-1);
	if (i == (RA | RB))
		return (RR);
	if (i == (RRA | RRB))
		return (RRR);
	if (i == (SA | SB))
		return (SS);
	return (0);
}

static int		op_modifier(t_op *head, t_op **prev)
{
	t_op		*save;

	if (head->next->op != 0 && are_useless_ops(head->op | head->next->op) == -1)
	{
		*prev = head->next->next;
		free(head->next);
		free(head);
		head = *prev;
		return (1);
	}
	else if (are_useless_ops(head->op | head->next->op) != 0)
	{
		head->op = are_useless_ops(head->op | head->next->op);
		save = head->next->next;
		free(head->next);
		head->next = save;
		return (1);
	}
	return (0);
}

static int		op_list_opti(t_op **begin)
{
	t_op		*head;
	t_op		*save;
	t_op		**prev;
	int			res;

	res = 0;
	if (*begin == NULL)
		return (0);
	head = *begin;
	prev = begin;
	if (head->next == NULL || head->next->next == NULL)
		return (0);
	while (head->next != NULL)
	{
		if (op_modifier(head, prev))
		{
			res = 1;
			head = (*prev)->next;
		}
		prev = &(head->next);
		head = head->next;
	}
	return (res);
}

int				main(int ac, char **av)
{
	t_tab		tab;
	t_tab		*ptr;

	tab.ops = NULL;
	if (ac < 1)
		return (0);
	if (!(tab.a = init_list_a(ac, av)))
		return (0);
	tab.b = init_empty_list();
	ptr = &tab;
	if (!(is_ordered(tab.a) && tab.b->size == 0))
	{
		algo(ptr);
		while (op_list_opti(&(ptr->ops)))
			;
		op_list_read(&(ptr->ops));
	}
	free_op_list(&(ptr->ops));
	free_both_lists(ptr);
	return (0);
}
