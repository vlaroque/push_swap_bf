/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 22:27:33 by vlaroque          #+#    #+#             */
/*   Updated: 2019/10/09 20:28:05 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

t_op	*op_new(int op)
{
	t_op	*new;

	if (!(new = (t_op *)malloc(sizeof(t_op))))
		return (NULL);
	ft_bzero(new, sizeof(t_op));
	new->op = op;
	new->next = NULL;
	return (new);
}

void	op_add(t_op **begin, t_op *new_op)
{
	t_op	*last;

	if (begin == NULL || new_op == NULL)
		return ;
	last = *begin;
	if (last == NULL)
	{
		*begin = new_op;
		return ;
	}
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = new_op;
	new_op->next = NULL;
}

void	op_add_new(t_op **begin, int op)
{
	t_op *tmp;

	if (!(tmp = op_new(op)))
	{
		free_op_list(begin);
		exit(0);
	}
	op_add(begin, tmp);
}

void	write_op(int op)
{
	if (op == PB)
		write(1, "pb\n", 3);
	else if (op == PA)
		write(1, "pa\n", 3);
	else if (op == RA)
		write(1, "ra\n", 3);
	else if (op == RB)
		write(1, "rb\n", 3);
	else if (op == RR)
		write(1, "rr\n", 3);
	else if (op == RRA)
		write(1, "rra\n", 4);
	else if (op == RRB)
		write(1, "rrb\n", 4);
	else if (op == RRR)
		write(1, "rrr\n", 4);
	else if (op == SA)
		write(1, "sa\n", 3);
	else if (op == SB)
		write(1, "sb\n", 3);
	else if (op == SS)
		write(1, "ss\n", 3);
}

void	op_list_read(t_op **begin)
{
	t_op *head;

	head = *begin;
	while (head)
	{
		write_op(head->op);
		head = head->next;
	}
}
